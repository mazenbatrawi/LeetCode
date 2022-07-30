class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            if(dp[n - 1]){
                break;
            }
            if(dp[i] == 0){
                continue;
            }
            for(int j = 1; j <= min(a[i], n) && i + j < n; j++){
                dp[i + j] = dp[i] + 1;
            }
        }
        return dp[n - 1] >= 1;
    }
};