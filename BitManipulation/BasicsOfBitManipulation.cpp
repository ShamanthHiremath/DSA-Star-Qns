// swapp 2 numbers without using temp variable (xor ^)

a = a^b
b = a^b
a = a^b

class Solution {
  public:
    void bitManipulation(int n, int i) {
        // setithBitour code here
        i--;
        // int num = n;
        int getithBit = (n & (1 << i)) != 0;
        // n = num;
        int setithBit = n | (1 << i);
        // n = num;
        int clearithBit = n & ~(1 << i);
        
        cout<<getithBit<<" "<<setithBit<<" "<<clearithBit;
    }
};


// removing the last set bit
n & n-1

// Setting the rightmost set bit and rest all bits to 0
n = (n & (n-1)) ^ n;
n = n & ((~n)+1)

// if a number is a power of 2
(n & (n-1)) == 0;
// or
n % 2 == 0

// odd check
n & 1 == 1 // cuz the last bit of odd number is 1

// n = n/2 or n /= 2
n >> 1

// n = n*2 or n *= 2
n << 1

// counting the no of setBits in a number

int setBits(int n){
    int cnt = 0;
    while(n != 0){
        n = (n & (n-1) );
        cnt++;
    }
    
    return cnt;
}

// set the rightmost unset bit

class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        int y = ~n;
        // unsets the rightmost set bit as 0
        y = y & (y-1);
        
        return ~y;
    }
};

// n = 00111
// y = 11000

// y = y & y-1 = 10000
// ~y = 01111
