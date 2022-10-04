class Solution {
public:
    
    int dp[50];
    
    int calc(int n){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = calc(n - 1) + calc(n - 2);
    }
    
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return calc(n);
    }
};