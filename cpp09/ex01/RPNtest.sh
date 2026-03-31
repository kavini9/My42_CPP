#!/usr/bin/env bash
set -u

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$SCRIPT_DIR" || exit 1

BIN="./RPN"

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
  local expression="$2"
  local expected_output="$3"

  ((case_count++))
  print_divider
  printf "\033[1mCASE #$case_count: $name\033[0m\n"
  
  # Print ARGS in Yellow
  printf "ARGS: ${CLR_YELLOW}\"%s\"${CLR_RESET}\n" "$expression"

  # Run the program
  local output
  output="$($BIN "$expression" 2>&1)"
  local exit_code=$?
  
  # Clean up actual output
  local actual_output
  actual_output="$(printf '%s' "$output" | tr '\n' ' ' | xargs)"

  if [[ -z "$actual_output" ]]; then
    actual_output="<empty>"
  fi

  # Group Exits together
  printf "EXPECTED EXIT: 0\n"
  printf "ACTUAL EXIT: %s\n" "$exit_code"
  
  # Group Outputs together
  printf "EXPECTED OUTPUT: \"%s\"\n" "$expected_output"
  printf "ACTUAL OUTPUT: \"%s\"\n" "$actual_output"

  # STRICT COMPARISON
  if [[ $exit_code -eq 0 && "$actual_output" == "$expected_output" ]]; then
    printf "RESULT: ${CLR_GREEN}PASS${CLR_RESET}\n"
    ((pass_count++))
  else
    printf "RESULT: ${CLR_RED}FAIL${CLR_RESET}\n"
    ((fail_count++))
  fi
}

run_error_case() {
  local name="$1"
  local expression="$2"

  ((case_count++))
  print_divider
  printf "\033[1mCASE #$case_count: $name\033[0m\n"
  
  # Print ARGS in Yellow
  printf "ARGS: ${CLR_YELLOW}\"%s\"${CLR_RESET}\n" "$expression"
  
  # Run the program
  local output
  output="$($BIN "$expression" 2>&1)"
  local exit_code=$?

  # Clean up the actual output
  local clean_output
  clean_output="$(printf '%s' "$output" | tr '\n' ' ' | xargs)"

  # Group Exits together
  printf "EXPECTED EXIT: 1 (non-zero)\n"
  printf "ACTUAL EXIT: %s\n" "$exit_code"
  
  # Group Outputs together
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
    ((fail_count++))
  fi
}

# ==========================================
# TEST DEFINITIONS
# ==========================================

# 1. The Basics (Sanity Checks)
run_success_case "Subject Example 1" "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
run_success_case "Subject Example 2" "7 7 * 7 -" "42"
run_success_case "Subject Example 3" "1 2 * 2 / 2 * 2 4 - +" "0"

# 2. Deep Stack Operations
run_success_case "Deep Stack Accumulation" "1 2 3 4 5 + + + +" "15"
run_success_case "Mixed Operations" "9 2 8 * + 3 -" "22"
run_success_case "Multiple Spaces Handled" "2  3  +" "5"
run_success_case "Single operand" "4" "4"

# 3. Stack Underflows / Missing Operators
run_error_case "Not enough operands at end" "2 3 + 2 / +"
run_error_case "Leftover numbers on stack" "1 2 + 3"
run_error_case "Immediate stack underflow" "3 /"
run_error_case "Lone operator" "/"
run_error_case "Empty string" ""
run_error_case "Space only string" " "

# 4. Math Errors
run_error_case "Division by zero" "1 0 /"

# 5. Token Parsing Traps
run_error_case "Invalid character" "2 3 + a"
run_error_case "Missing spaces between tokens" "2 3+2"

# Note: If your program strictly enforces single digits (as per 42 subject), 
# this next one should fail. If you allow multi-digits, change to success case.
run_error_case "Multi-digit number" "10 2 +"

# ==========================================
# FINAL SUMMARY
# ==========================================

print_divider
printf "${CLR_YELLOW}TOTAL: %d${CLR_RESET} | ${CLR_GREEN}PASS: %d${CLR_RESET} | ${CLR_RED}FAIL: %d${CLR_RESET}\n" "$case_count" "$pass_count" "$fail_count"

if [[ $fail_count -ne 0 ]]; then
  echo -e "\033[31mSome tests failed.\033[0m"
  exit 1
fi

echo -e "\033[32mAll tests passed.\033[0m"
exit 0