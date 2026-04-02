#!/usr/bin/env bash
set -u

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$SCRIPT_DIR" || exit 1

BIN="./PmergeMe"

if [[ ! -x "$BIN" ]]; then
  echo "Building $BIN..."
  if ! make -s; then
    echo "Build failed."
    exit 1
  fi
fi

pass_count=0
fail_count=0
case_count=0

CLR_RED=$'\033[31m'
CLR_GREEN=$'\033[32m'
CLR_YELLOW=$'\033[33m'
CLR_RESET=$'\033[0m'

print_divider() {
  printf '%s\n' "------------------------------------------------------------"
}

run_success_case() {
  local name="$1"
  shift
  local -a args=("$@")

  ((case_count++))
  print_divider
  printf "\033[1mCASE #$case_count: $name\033[0m\n"
  
  # 1. DYNAMICALLY GENERATE THE EXPECTED OUTPUT using Unix 'sort -n'
  local expected_after
  expected_after=$(printf '%s\n' "${args[@]}" | sort -n | xargs)

  # Print ARGS in Yellow
  if [[ ${#args[@]} -gt 30 ]]; then
    printf "ARGS: ${CLR_YELLOW}<${#args[@]} elements generated>${CLR_RESET}\n"
  else
    printf "ARGS: ${CLR_YELLOW}${args[*]}${CLR_RESET}\n"
  fi

  # Run the program first to capture the exit code and actual output
  local output
  output="$($BIN "${args[@]}" 2>&1)"
  local exit_code=$?
  
  # Extract the "After:" line and sanitize it (immune to variable space padding)
  local actual_after
  actual_after="$(printf '%s\n' "$output" | awk '/^After:/ {sub(/^After:[[:space:]]*/, ""); print; exit}' | xargs)"

  if [[ -z "$actual_after" ]]; then
    actual_after="<missing>"
  fi

  # Group Exits together (No yellow)
  printf "EXPECTED EXIT: 0\n"
  printf "ACTUAL EXIT: %s\n" "$exit_code"
  
  # Group Outputs together (No yellow, uses new omitted string)
  if [[ ${#args[@]} -gt 30 ]]; then
    printf "EXPECTED OUTPUT: [output too long. print omitted]\n"
    printf "ACTUAL OUTPUT: [output too long. print omitted]\n"
  else
    printf "EXPECTED OUTPUT: \"%s\"\n" "$expected_after"
    printf "ACTUAL OUTPUT: \"%s\"\n" "$actual_after"
  fi

  # STRICT COMPARISON
  if [[ $exit_code -eq 0 && "$actual_after" == "$expected_after" ]]; then
    printf "RESULT: ${CLR_GREEN}PASS${CLR_RESET}\n"
    ((pass_count++))
  else
    printf "RESULT: ${CLR_RED}FAIL${CLR_RESET}\n"
    echo "RAW OUTPUT:"
    printf '%s\n' "$output"
    
    echo "--- DIFF (Expected vs Actual) ---"
    diff -u <(echo "$expected_after") <(echo "$actual_after")
    ((fail_count++))
  fi
}

run_error_case() {
  local name="$1"
  shift
  local -a args=("$@")

  ((case_count++))
  print_divider
  printf "\033[1mCASE #$case_count: $name\033[0m\n"
  
  # Print ARGS in Yellow
  if [[ ${#args[@]} -eq 0 ]]; then
    printf "ARGS: ${CLR_YELLOW}<none>${CLR_RESET}\n"
  else
    printf "ARGS: ${CLR_YELLOW}${args[*]}${CLR_RESET}\n"
  fi
  
  # Run the program first
  local output
  output="$($BIN "${args[@]}" 2>&1)"
  local exit_code=$?

  # Clean up the actual output
  local clean_output
  clean_output="$(printf '%s' "$output" | tr '\n' ' ' | xargs)"

  # Group Exits together (No yellow)
  printf "EXPECTED EXIT: (non-zero)\n"
  printf "ACTUAL EXIT: %s\n" "$exit_code"
  
  # Group Outputs together (No yellow)
  printf "EXPECTED OUTPUT: \"Error:*\"\n"
  if [[ -z "$clean_output" ]]; then
    printf "ACTUAL OUTPUT: <empty>\n"
  else
    printf "ACTUAL OUTPUT: \"%s\"\n" "$clean_output"
  fi

  # Check if the program threw an error code AND the output contained the word "Error"
  if [[ $exit_code -ne 0 && "$output" == *"Error"* ]]; then
    printf "RESULT: ${CLR_GREEN}PASS${CLR_RESET}\n"
    ((pass_count++))
  else
    printf "RESULT: ${CLR_RED}FAIL${CLR_RESET}\n"
    echo "RAW OUTPUT:"
    printf '%s\n' "$output"
    ((fail_count++))
  fi
}

# ==========================================
# TEST DEFINITIONS
# ==========================================

# Standard cases
run_success_case "Zero allowed" 0
run_success_case "Single element" 42
run_success_case "Two elements unsorted" 2 1
run_success_case "Odd count with straggler" 3 1 2
run_success_case "Odd count with stragglers in several recursion levels" 20 10 16 6 14 1 9 19 13 5 8 3 11 2 21 18 15 4 7 12 17
run_success_case "Already sorted" 1 2 3 4 5
run_success_case "Reverse sorted" 5 4 3 2 1
run_success_case "Duplicates basic" 2 2 1 1
run_success_case "INT_MAX accepted" 2147483647 1 2
run_success_case "Duplicate-heavy mixed" 9 5 7 9
run_success_case "Duplicate-heavy mixed" 3 6 4 2 6 5 7 6 6 9 8 6 6 3

# Invalid-input/error cases
run_error_case "No argument"
run_error_case "Empty argument" ""
run_error_case "Empty argument in the mix" 3 1 8 "" 2
run_error_case "Negative not allowed" 34 -1 78 90
run_error_case "Non-numeric token i" 1a 2
run_error_case "Non-numeric token ii" 100 +-1 2
run_error_case "Non-numeric token iii" 5 + 2
run_error_case "Overflow INT_MAX" 2 5 90 2147483648 23

# ==========================================
# STRESS TESTS
# ==========================================

if command -v jot >/dev/null 2>&1; then
    run_success_case "Stress Test (100 elements using jot)" $(jot -r 100 1 1000)
    run_success_case "Stress Test (3000 elements using jot)" $(jot -r 3000 1 100000)
elif command -v shuf >/dev/null 2>&1; then
    run_success_case "Stress Test (100 elements using shuf)" $(shuf -i 1-1000 -n 100)
    run_success_case "Stress Test (3000 elements using shuf)" $(shuf -i 1-100000 -n 3000)
else
    echo "WARNING: Neither 'jot' nor 'shuf' found. Skipping stress tests."
fi

print_divider
printf "${CLR_YELLOW}TOTAL: %d${CLR_RESET} | ${CLR_GREEN}PASS: %d${CLR_RESET} | ${CLR_RED}FAIL: %d${CLR_RESET}\n" "$case_count" "$pass_count" "$fail_count"

if [[ $fail_count -ne 0 ]]; then
  echo -e "\033[31mSome tests failed.\033[0m"
  exit 1
fi

echo -e "\033[32mAll tests passed.\033[0m"
exit 0