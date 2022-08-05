class Solution {
public:
    double myPow(double x, long n) {
        if(n == 1){
            return x;
        }
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return myPow(1 / x, -n);
        }
        double ans = myPow(x, n / 2);
        ans *= ans;
        if(n & 1){
            ans *= x;
        }
        return ans;
    }
};