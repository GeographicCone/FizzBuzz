
// FizzBuzz
// Implementation

/* Includes */

// Global
#include <stdbool.h>   // Boolean type
#include <stdio.h>     // Standard I/O: fputs(), stdout
#include <stdlib.h>    // Standard Library: free(), malloc()
#include <string.h>    // String: memset()

// Local
#include "config.h"    // Configuration
#include "fmt.h"       // Formatting
#include "impl.h"      // Implementation (self)

/* Functions */

// Processes each Fizz-Buzz batch in the clever implementation
void fizzbuzz_clever_batch(int *pattern, int from, int batch, int until) {
    int limit = batch - 1;
    bool full = true;

    // Allow for an incomplete batch
    if(from + limit > until) {
        limit = until - from + 1;
        full = false;
    }

    // Iterate through the value range
    for(int i = 0; i < limit; i++) {

        // Output entries
        pattern[i] < 0 ?
            pattern[i] < -1 ?
                fputs(BUZZ, stdout)
                : fputs(FIZZ, stdout)
                : fputs(fmt_itoa(from + i, NBASE), stdout);

        // Separate entries
        fputs(SEP, stdout);

    }

    // Full batch ends
    // with a fizz-buzz
    if(full)
        fputs(FIZZ BUZZ SEP, stdout);

}

// Attempts to implement Fizz-Buzz in a clever way
void fizzbuzz_clever(int fizz, int buzz, int until) {
    int *pattern;

    // Define the size of each batch
    const int batch = fizz * buzz;

    // Set up and initialize the memory
    pattern = malloc(batch * sizeof(int));
    memset(pattern, 0, batch * sizeof(int));

    // Mark fizz values
    for(int i = fizz; i <= batch; i += fizz)
        pattern[i - 1] = -1;

    // Mark buzz values (including fizz-buzz)
    for(int i = buzz; i <= batch; i += buzz)
        pattern[i - 1] = -2;

    // Iterate through the value range
    for(int i = 0; i <= until; i += batch)

        // Process each batch
        // reapplying the same pattern
        fizzbuzz_clever_batch(pattern, i + 1, batch, until);

    // Release
    // the memory
    free(pattern);

}

// Implements Fizz-Buzz in the most naive way
void fizzbuzz_naive(int fizz, int buzz, int until) {

    // Iterate through the value range
    for(int i = 1; i <= until; i++) {

        // Output entries
        i % fizz == 0 ?
            i % buzz == 0 ?
                fputs(FIZZ BUZZ, stdout)
                : fputs(FIZZ, stdout)
            : i % buzz == 0 ?
                fputs(BUZZ, stdout)
                : fputs(fmt_itoa(i, NBASE), stdout);

        // Separate entries
        fputs(SEP, stdout);

    }

}

// Implements Fizz-Buzz in a way
// that avoids the use of the remainder
void fizzbuzz_no_remainder(int fizz, int buzz, int until) {
    int *result;

    // Set up and initialize the memory
    result = malloc(until * sizeof(int));
    memset(result, 0, until * sizeof(int));

    // Mark fizz values
    for(int i = fizz; i <= until; i += fizz)
        result[i] = -1;

    // Mark buzz values (including fizz-buzz)
    for(int i = buzz; i <= until; i += buzz)
        result[i] -= (int) 2;

    // Iterate through the value range
    for(int i = 1; i <= until; i++) {

        // Output entries
        result[i] < 0 ?
            result[i] < -1 ?
                result[i] < -2 ?
                    fputs(FIZZ BUZZ, stdout)
                    : fputs(BUZZ, stdout)
                    : fputs(FIZZ, stdout)
                    : fputs(fmt_itoa(i, NBASE), stdout);

        // Separate entries
        fputs(SEP, stdout);

    }

    // Release
    // the memory
    free(result);

}

// Implements Fizz-Buzz in a recursive way
void fizzbuzz_recursive(int fizz, int buzz, int i) {

    // Output
    // prior entry
    if(i > 1)
        fizzbuzz_recursive(fizz, buzz, i - 1);

    // Output entry
    i % fizz == 0 ?
        i % buzz == 0 ?
            fputs(FIZZ BUZZ, stdout)
            : fputs(FIZZ, stdout)
        : i % buzz == 0 ?
            fputs(BUZZ, stdout)
            : fputs(fmt_itoa(i, NBASE), stdout);

    // Separate entries
    fputs(SEP, stdout);

}
