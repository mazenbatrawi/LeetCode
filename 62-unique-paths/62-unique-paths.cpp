class Solution {
public:
    int dp[105][105];
    
    int calc(int i, int j, int &m, int &n){
        if(i == m - 1 && j == n - 1){
            return 1;
        }
        if(i >= m || i < 0 || j >= n || j < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ret = 0;
        ret += calc(i, j + 1, m, n);
        ret += calc(i + 1, j, m, n);
        return dp[i][j] = ret;
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return calc(0, 0, m, n);
    }
};