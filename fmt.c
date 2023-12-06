
// FizzBuzz
// Formatting

/* Includes */

// Local
#include "config.h"    // Configuration
#include "fmt.h"       // Formatting (self)

/* Variables */

// Buffer used for converting
// an integer to a string
char buf[MAX_LEN];

/* Functions */

// Converts a non-negative integer
// to a string, given a numerical base
char *fmt_itoa(unsigned int n, unsigned int nbase) {
    int i = MAX_LEN;

    // Iterate through
    // each part of the number…
    do {

        // Array is zero-initialized,
        // so no need to append a '\0'
        i--;

        // Append the character to the buffer
        buf[i] = n % nbase + BASE_DIGIT_DEC;

        // If outside the decimal range
        // use letters to supplement digits
        if(buf[i] > BASE_DIGIT_DEC + 9)
            buf[i] += BASE_DIGIT_HEX - BASE_DIGIT_DEC - 10;

    // …for as long as
    // what remains is non-zero
    } while((n /= nbase) > 0);

    // Skip unused part of the buffer
    return &buf[i];

}
