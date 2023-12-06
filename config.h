
// FizzBuzz
// Configuration (Header)

#ifndef FIZZBUZZ_CONFIG
#define FIZZBUZZ_CONFIG

/* Definitions */

#define FIZZ            "Fizz"  // Fizz string to output instead of value
#define FIZZ_AT              3  // Divisor for values output as a fizz

#define BUZZ            "Buzz"  // Buzz string to output instead of value
#define BUZZ_AT              5  // Divisor for values output as a buzz

#define START     " - Start: "  // Token indicating start of output
#define NAME_C        "Clever"  // Name for the clever implementation
#define NAME_I         "Naive"  // Name for the naive implementation
#define NAME_N  "No Remainder"  // Name for the no-remainder implementation
#define NAME_R     "Recursive"  // Name for the recursive implementation
#define NEWLINE           "\n"  // New line character, possibly platform-specific
#define SEP               ", "  // Separator to use between entries
#define TIME     " - Cycles: "  // Token indicating start of output
#define END              "End"  // Token indicating end of output

#define MAX_LEN              6  // Maximum length of an integer string
#define NBASE               10  // Numerical base to use in output
#define UNTIL              100  // How many values to output

#define BASE_DIGIT_DEC     '0'  // Base digit for decimal value output
#define BASE_DIGIT_HEX     'A'  // Base digit for hexadecimal value output

#endif // FIZZBUZZ_CONFIG
