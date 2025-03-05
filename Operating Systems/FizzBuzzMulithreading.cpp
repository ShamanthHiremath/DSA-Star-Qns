/*
1195. Fizz Buzz Multithreaded

https://leetcode.com/problems/fizz-buzz-multithreaded/

You have the four functions:

printFizz that prints the word "fizz" to the console,
printBuzz that prints the word "buzz" to the console,
printFizzBuzz that prints the word "fizzbuzz" to the console, and
printNumber that prints a given integer to the console.
You are given an instance of the class FizzBuzz that has four functions: fizz, buzz, fizzbuzz and number. The same instance of FizzBuzz will be passed to four different threads:

Thread A: calls fizz() that should output the word "fizz".
Thread B: calls buzz() that should output the word "buzz".
Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
Thread D: calls number() that should only output the integers.
Modify the given class to output the series [1, 2, "fizz", 4, "buzz", ...] where the ith token (1-indexed) of the series is:

"fizzbuzz" if i is divisible by 3 and 5,
"fizz" if i is divisible by 3 and not 5,
"buzz" if i is divisible by 5 and not 3, or
i if i is not divisible by 3 or 5.
Implement the FizzBuzz class:

FizzBuzz(int n) Initializes the object with the number n that represents the length of the sequence that should be printed.
void fizz(printFizz) Calls printFizz to output "fizz".
void buzz(printBuzz) Calls printBuzz to output "buzz".
void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output "fizzbuzz".
void number(printNumber) Calls printnumber to output the numbers.
 

Example 1:
Input: n = 15
Output: [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]

Example 2:
Input: n = 5
Output: [1,2,"fizz",4,"buzz"]
*/

#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

class FizzBuzz {
private:
    int n;
    int i;
    mutex mtx;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            while (i <= n && (i % 3 != 0 || i % 5 == 0)) {  // Wait until i is divisible by 3 but not 5
                cv.wait(lock);
            }
            
            if (i > n) return;
            printFizz();
            i++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            while (i <= n && (i % 5 != 0 || i % 3 == 0)) {  // Wait until i is divisible by 5 but not 3
                cv.wait(lock);
            }

            if (i > n) return;
            printBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            while (i <= n && (i % 3 != 0 || i % 5 != 0)) {  // Wait until i is divisible by both 3 and 5
                cv.wait(lock);
            }

            if (i > n) return;
            printFizzBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            while (i <= n && (i % 3 == 0 || i % 5 == 0)) {  // Wait until i is NOT divisible by 3 or 5
                cv.wait(lock);
            }

            if (i > n) return;
            printNumber(i);
            i++;
            cv.notify_all();
        }
    }
};
