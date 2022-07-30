class Solution {
public:
    
    int dp[10005];
    
    int calc(int sum, int &n){
        if(sum >= n){
            return (sum == n ? 0 : n);
        }
        if(dp[sum] != -1){
            return dp[sum];
        }
        int ret = n + 1;
        for(int i = 1; i * i + sum <= n; i++){
            ret = min(ret, calc(i * i + sum, n) + 1);
        }
        return dp[sum] = ret;
    }
    
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return calc(0, n);
    }
};