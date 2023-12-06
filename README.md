# Fizz Buzz

Just for the sake of it, here's a simple implementation of a couple of approaches to solving the [Fizz-Buzz](https://en.wikipedia.org/wiki/Special:Search?search=FizzBuzz) problem in a way that also allows for basic performance comparison.

## The Approaches

* **Naive** is the most straightforward iterative approach: run through the values, calculate the remainder from division by fizz and buzz respectively in each case, and output accordingly
* **Recursive** is another simple implementation with the above-stated control flow that only replaces iteration with recursion
* **No Remainder** is a variation of the iterative (aka naive) method, replacing the possibly expensive remainder calculations with addition, at the cost of extra memory usage
* Finally, the **Clever** method splits the problem into smaller batches, each of which has the size of _fizz_ ∗ _buzz_, and reapplies the same solution pattern to each of them

I haven't looked at anyone else's implementation before writing these: none of these approaches are greatly optimized, and there likely exists a better solution altogether than even the "clever" one here. There might be a fly in the ointment or even an elephant in the room but like I said, this is just for fun.

An example output (edited for clarity):

````shell
% make all run
[...]
Clever - Start: 1, 2, Fizz, 4, Buzz, [...], 14, FizzBuzz, [...], 98, Fizz, Buzz, End - Cycles: 8
Naive - Start: 1, 2, Fizz, 4, Buzz, [...], 14, FizzBuzz, [...], 98, Fizz, Buzz, End - Cycles: 9
No Remainder - Start: 1, 2, Fizz, 4, Buzz, [...], 14, FizzBuzz, [...], 98, Fizz, Buzz, End - Cycles: 9
Recursive - Start: 1, 2, Fizz, 4, Buzz, [...], 14, FizzBuzz, [...], 98, Fizz, Buzz, End - Cycles: 9
````

## The Measurement

The performance reported in clock cycles is measured in a very basic way, and the result is heavily affected by standard-output buffering. Thus, for the numbers to be a (somewhat) meaningful reflection of actual Fizz-Buzz performance, the output is best discarded:

```` shell
% make all run >/dev/null
````
Otherwise, what ends up being measured is the performance of the terminal (console) implementation instead, which by the way is often [pretty abysmal](https://www.youtube.com/watch?v=hxM8QmyZXtg).

Even with standard output redirected away, the measurements will still show as they are printed to the standard-error stream.

For more meaningful results, the execution time, controlled through the value for `UNTIL`, should also be significantly increased, although at some point this breaks the recursive implementation.

## The Results

Here are the results for running the program until the value of 32376 (for full disclosure, that was the exact point at which the recursive implementation triggered stack overflow in my particular setup at the time).
 
````shell
% make clean all run >/dev/null
Clever - Start: End - Cycles: 92
Naive - Start: End - Cycles: 96
No Remainder - Start: End - Cycles: 96
Recursive - Start: End - Cycles: 97
````

It seems to confirm my intuition that the **Clever** approach would end up proving itself clever, even if only by a tiny bit.

The **No Remainder** approach also appears to shave a bit of time compared to the naive one, although that is even less noticeable.

What is also interesting is how the terminal (console) output slows everything down. Here are the results for only a 1,000 values: 

|              | MSys2 [MinTTY](https://mintty.github.io/) | _ConHost.exe_ |
|:-------------|------------------------------------------:|--------------:|
| Clever       |                                        92 |           111 |
| Naive        |                                        86 |           117 |
| No Remainder |                                        81 |            95 |
| Recursive    |                                        87 |           102 |

So, roughly the same number of cycles for over 30 times less data output. These results also exhibit high variability. Interestingly, the **Clever** variant is no longer demonstrably the fastest, possibly as it is the first to run, which comes with a performance penalty.

## Bonus Content for Subscribers

As a bonus, by setting the value of `NBASE` in `config.h`, the results can be output in any numerical base up to at least 36 (before running out of the letters of the alphabet, even if the conversion still works).

## Building

The gist of it:

* `make all` to build
* `make clean` to clean
* `make run` to run

### Layout

* `main.c` is the entry point to the application
* `fmt.c` and `fmt.h` provide the `fmt_itoa(int)` function for value output, bypassing the need for `fprintf()`
* `impl.c` and `impl.h` is where the sausage is made
* `wrap.c` and `wrap.h` is where the sausage is wrapped, i.e. the function there measures the performance for each call
* `config.h` provides easy access to settings customization, all in one place

### Prerequisites

Tested with [MSys2](https://www.msys2.org/) MinGW64 [GCC](https://gcc.gnu.org/) toolchain. Might need minor adjustments to build in a significantly different environment.

## See Also

* [FizzBuzz Enterprise Edition](https://github.com/EnterpriseQualityCoding/FizzBuzzEnterpriseEdition/)
