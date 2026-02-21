# Tail recursion Lab

## Directions

For this lab activity, you are going to practice writing tail recursive functions. The starting code contains five recursive functions that we've studied so far in class. Your job is to refactor the functions to be tail recursive (so yes, you can change the parameter list). Do not rely on the compiler automatically optimizing for you, write the tail recursion yourself. The `main` function has already been written for you to run test cases.

Creating a tail recursive version of the Fibonacci function is tricky. But if you do it right, it will reduce the time complexity from $\mathcal{O}(2^n)$ to $\mathcal{O}(n)$. Amazing improvement!

## Sample Run

The following is what your program should display (quickly!) if you converted all the functions into tail recursion:

```text
6 * 123000 = 738000
3 ^ 10 = 59049
8 * 9 * ... * 15 = 259459200
10! = 3628800
50th Fibonacci number is 3996334433
```


