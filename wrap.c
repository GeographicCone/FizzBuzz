
// FizzBuzz
// Wrapper

/* Includes */

// Global
#include <stdio.h>     // Standard I/O: fputs(), stderr
#include <time.h>      // Time: clock(), clock_t

// Local
#include "config.h"    // Configuration
#include "fmt.h"       // Formatting
#include "wrap.h"      // Wrapper (self)

/* Functions */

// Wraps a Fizz-Buzz implementation call so that it can be measured
void fizzbuzz_wrapper(char *name, void (*fizzbuzz_impl)(int, int, int)) {

    // Indicate implementation
    // and the start of output
    fputs(name, stderr);
    fputs(START, stderr);

    // Start measurement
    clock_t start = clock();

    // Launch the Fizz-Buzz implementation
    fizzbuzz_impl(FIZZ_AT, BUZZ_AT, UNTIL);

    // End measurement
    clock_t end = clock();

    // Indicate end of output
    fputs(END, stderr);

    // Output execution time in clock cycles
    fputs(TIME, stderr);
    fputs(fmt_itoa(end - start, 10), stderr);

    // Finish with a line break
    fputs(NEWLINE, stderr);

}
