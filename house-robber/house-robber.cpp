class Solution {
public:
    int calc(int i, vector<int> &dp, vector<int> &nums){
        if(i >= (int) nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        return dp[i] = max(calc(i + 2, dp, nums) + nums[i], calc(i + 1, dp, nums));
    }
    int rob(vector<int>& nums) {
        vector<int> dp((int) nums.size(), -1);
        return calc(0, dp, nums);
    }
};