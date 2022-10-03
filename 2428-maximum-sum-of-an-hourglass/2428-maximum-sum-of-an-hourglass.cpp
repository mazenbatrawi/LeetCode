class Solution {
public:
    int maxSum(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int ans = 0;
        for(int i = 0; i + 2 < n; i++){
            for(int j = 0; j + 2 < m; j++){
                int t = a[i][j] + a[i][j + 1] + a[i][j + 2];
                t += a[i + 1][j + 1];
                t += a[i + 2][j] + a[i + 2][j + 1] + a[i + 2][j + 2];
                ans = max(ans, t);
            }
        }
        return ans;
    }
};