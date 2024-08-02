class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x == 1){
            return 1;
        }
        if(n == INT_MAX && x>1){
            return INT_MAX;
        }
        if(n == INT_MIN && x>1){
            return 0;
        }
        int i = 1;
        long long times = n;
        if(n<0){
            times = -times;
        }
        double result = 1;
        double current_product = x;

        while (times > 0) {
            if (times % 2 == 1) { // If n is odd
                result *= current_product;
            }
            current_product *= current_product; // Square the base
            times /= 2; // Divide the exponent by 2
        }

        if(n<0){
            return 1/result;
        }
        else{
            return result;
        }
    }
};