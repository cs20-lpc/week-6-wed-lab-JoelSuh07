#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

unsigned fact(unsigned);
unsigned tail_fact(unsigned, unsigned);
unsigned fib(unsigned);
unsigned tail_fib(unsigned, int, int);
unsigned mult(unsigned, unsigned);
unsigned tail_mult(unsigned, unsigned, unsigned);
unsigned power(unsigned, unsigned);
unsigned product(unsigned, unsigned);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * optimized using tail recursion.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << tail_mult(6, 123000, 0) << endl;
    
    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << tail_fact(10, 1) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << tail_fib(50, 0, 1) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Function definitions below are NOT tail recursive!
 * TODO: make them tail recursive :)
*******************************************************************************/

unsigned fact(unsigned n) {
    // base cases (combined)
    if (n <= 1) {
        return 1;
    }

    // recursive case
    unsigned res = fact(n - 1);
    return res * n;
}

unsigned tail_fact(unsigned n, unsigned a){
    if (n <= 1) return a;

    return tail_fact(n-1, a * n);
}

unsigned fib(unsigned n) {
    // base case 1
    if (n == 0) {
        return 0;
    }

    // base case 2
    else if (n == 1) {
        return 1;
    }

    // recursive case
    return fib(n - 1) + fib(n - 2);
}

unsigned tail_fib(unsigned n, int a = 0, int b = 1){
    if (n == 0){
        return a;
    }
    if (n == 1){
        return b;
    }

    return tail_fib(n - 1, b, b + a);
}

unsigned mult(unsigned x, unsigned y) {
    // base case
    if (y == 0) {
        return 0;
    }

    // recursive case
    unsigned res = mult(x, y - 1);
    return res + x;
}

unsigned tail_mult(unsigned x, unsigned y, unsigned a){
    if (y == 0) return a; //it's like counting down the y value, repeating the process y times
    //the a keeps getting added by x amount each run, for y times.
    //in the end return a, which has the final multiplied/added value
    return tail_mult(x, y - 1 , a + x);

    /* to use this to make sure it "recycles" stacks
    g++ -O2 lab08.cpp -o lab08
    ./lab08
    */
}

unsigned power(unsigned x, unsigned y) {
    // base case
    if (y == 0) {
        return 1;
    }

    // recursive case
    unsigned res = power(x, y - 1);
    return res * x;
}

unsigned tail_power(unsigned x, unsigned y, unsigned a){
    if (y == 0) return ;

    return 
}

unsigned product(unsigned x, unsigned y) {
    // base case
    if (x == y) {
        return x;
    }

    // recursive case
    unsigned p = product(x + 1, y);
    return p * x;
}
