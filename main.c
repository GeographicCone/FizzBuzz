
// FizzBuzz
// Main

/* Includes */

// Local
#include "config.h"    // Configuration
#include "impl.h"      // Implementation
#include "wrap.h"      // Wrapper

/* Entry Point */

int main() {

    // Run the clever Fizz-Buzz implementation
    fizzbuzz_wrapper(NAME_C, fizzbuzz_clever);

    // Run the naive Fizz-Buzz implementation
    fizzbuzz_wrapper(NAME_I, fizzbuzz_naive);

    // Run the Fizz-Buzz implementation
    // that avoids the use of the remainder
    fizzbuzz_wrapper(NAME_N, fizzbuzz_no_remainder);

    // Run the recursive Fizz-Buzz implementation
    fizzbuzz_wrapper(NAME_R, fizzbuzz_recursive);

    // Done
    return 0;

}
