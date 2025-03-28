/*
1115. Print FooBar Alternately

https://leetcode.com/problems/print-foobar-alternately/

Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}

The same instance of FooBar will be passed to two different threads:

thread A will call foo(), while
thread B will call bar().
Modify the given program to output "foobar" n times.
 

Example 1:
Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
"foobar" is being output 1 time.

Example 2:
Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.
*/

class FooBar {
    private:
        int n;
        mutex m;
        condition_variable cv;
        bool turn;
    
    public:
        FooBar(int n) {
            this->n = n;
            // 0 is foo, 1 is bar
            turn = 0;
        }
    
        void foo(function<void()> printFoo) {
            
            for (int i = 0; i < n; i++) {
                // set a lock
                unique_lock<mutex> lock(m);
                
                // wait for turn
                while(turn == 1){
                    cv.wait(lock);
                }
                // printFoo() outputs "foo". Do not change or remove this line.
                printFoo();
    
                // change turn and notify all
                turn = 1;
                cv.notify_all();
            }
        }
    
        void bar(function<void()> printBar) {
            
            for (int i = 0; i < n; i++) {
                // set a lock
                unique_lock<mutex> lock(m);
                
                // wait for turn
                while(turn == 0){
                    cv.wait(lock);
                }
                // printBar() outputs "bar". Do not change or remove this line.
                printBar();
    
                // change turn and notify all
                turn = 0;
                cv.notify_all();
    
            }
        }
    };