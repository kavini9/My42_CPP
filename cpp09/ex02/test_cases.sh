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
  local expected_after="$2"
  shift 2
  local -a args=("$@")

  ((case_count++))
  print_divider
  echo "CASE #$case_count: $name"
  echo "ARGS: ${args[*]}"
  printf "EXPECTED EXIT: ${CLR_YELLOW}0${CLR_RESET}\n"
  printf "EXPECTED AFTER: ${CLR_YELLOW}%s${CLR_RESET}\n" "$expected_after"

  local output
  output="$($BIN "${args[@]}" 2>&1)"
  local exit_code=$?
  local actual_after
  actual_after="$(printf '%s\n' "$output" | awk -F': ' '/^After:/ {print $2; exit}')"

  if [[ -z "$actual_after" ]]; then
    actual_after="<missing>"
  fi

  printf "ACTUAL EXIT: ${CLR_YELLOW}%s${CLR_RESET}\n" "$exit_code"
  printf "ACTUAL AFTER: ${CLR_YELLOW}%s${CLR_RESET}\n" "$actual_after"

  if [[ $exit_code -eq 0 && "$actual_after" == "$expected_after" ]]; then
    printf "RESULT: ${CLR_GREEN}PASS${CLR_RESET}\n"
    ((pass_count++))
  else
    printf "RESULT: ${CLR_RED}FAIL${CLR_RESET}\n"
    echo "RAW OUTPUT:"
    printf '%s\n' "$output"
    ((fail_count++))
  fi
}

run_error_case() {
  local name="$1"
  shift
  local -a args=("$@")

  ((case_count++))
  print_divider
  echo "CASE #$case_count: $name"
  if [[ ${#args[@]} -eq 0 ]]; then
    echo "ARGS: <none>"
  else
    echo "ARGS: ${args[*]}"
  fi
  printf "EXPECTED EXIT: ${CLR_YELLOW}non-zero${CLR_RESET}\n"
  printf "EXPECTED STDERR/STDOUT: ${CLR_YELLOW}contains 'Error'${CLR_RESET}\n"

  local output
  output="$($BIN "${args[@]}" 2>&1)"
  local exit_code=$?

  local contains_error="no"
  if printf '%s' "$output" | grep -q "Error"; then
    contains_error="yes"
  fi

  printf "ACTUAL EXIT: ${CLR_YELLOW}%s${CLR_RESET}\n" "$exit_code"
  printf "ACTUAL CONTAINS 'Error': ${CLR_YELLOW}%s${CLR_RESET}\n" "$contains_error"

  if [[ $exit_code -ne 0 && "$contains_error" == "yes" ]]; then
    printf "RESULT: ${CLR_GREEN}PASS${CLR_RESET}\n"
    ((pass_count++))
  else
    printf "RESULT: ${CLR_RED}FAIL${CLR_RESET}\n"
    echo "RAW OUTPUT:"
    printf '%s\n' "$output"
    ((fail_count++))
  fi
}

# Valid/sorting cases
run_success_case "Zero allowed" "0" 0
run_success_case "Single element" "42" 42
run_success_case "Two elements unsorted" "1 2" 2 1
run_success_case "Odd count with straggler" "1 2 3" 3 1 2
run_success_case "Already sorted" "1 2 3 4 5" 1 2 3 4 5
run_success_case "Reverse sorted" "1 2 3 4 5" 5 4 3 2 1
run_success_case "Duplicates basic" "1 1 2 2" 2 2 1 1
run_success_case "INT_MAX accepted" "1 2 2147483647" 2147483647 1 2

# Known tricky case that previously failed due to a bug.
run_success_case "Duplicate-heavy mixed" "5 7 9 9" 9 5 7 9
run_success_case "Duplicate-heavy mixed" "2 3 4 5 6 6" 3 6 4 2 6 5

# Invalid-input/error cases
run_error_case "No argument"
run_error_case "Negative not allowed" -1
run_error_case "Non-numeric token" 1a 2
run_error_case "Overflow INT_MAX" 2147483648

print_divider
printf 'TOTAL: %d | PASS: %d | FAIL: %d\n' "$case_count" "$pass_count" "$fail_count"

if [[ $fail_count -ne 0 ]]; then
  echo "Some tests failed."
  exit 1
fi

echo "All tests passed."
exit 0
