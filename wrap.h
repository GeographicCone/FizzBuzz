
// FizzBuzz
// Wrapper (Header)

#ifndef FIZZBUZZ_WRAP
#define FIZZBUZZ_WRAP

/* Functions */

// Wraps a Fizz-Buzz implementation call so that it can be measured
void fizzbuzz_wrapper(char *name, void (*fizzbuzz_impl)(int, int, int));

#endif // FIZZBUZZ_WRAP
