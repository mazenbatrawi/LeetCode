class Solution {
public:
    int dp[100005];
    
    int calc(int i, int n, vector<int> &a){
        if(i == n){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ret = 0;
        if(i + 1 < n){
            if(a[i] == a[i + 1]){
                ret |= calc(i + 2, n, a);
            }
        }
        if(i + 2 < n){
            if(a[i] == a[i + 1] && a[i] == a[i + 2]){
                ret |= calc(i + 3, n, a);
            }
        }
        if(i + 2 < n){
            if(a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]){
                ret |= calc(i + 3, n, a);
            }
        }
        return dp[i] = ret;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int ans = calc(0, (int) nums.size(), nums);
        return ans == 1;
    }
};