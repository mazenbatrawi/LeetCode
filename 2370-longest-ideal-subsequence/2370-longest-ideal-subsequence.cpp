class Solution {
public:
    int dp[100005][30];
    
    int calc(int i, int last, string &s, int &k){
        if(i == (int) s.size()){
            return 0;
        }
        if(dp[i][last] != -1){
            return dp[i][last];
        }
        int ret = calc(i + 1, last, s, k);
        if(last == 29 || abs((s[i] - 'a') - last) <= k){
            ret = max(ret, calc(i + 1, s[i] - 'a', s, k) + 1);
        }
        return dp[i][last] = ret;
    }
    int longestIdealString(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return calc(0, 29, s, k);
    }
};