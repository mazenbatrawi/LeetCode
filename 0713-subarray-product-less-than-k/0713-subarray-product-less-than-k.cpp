class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0){
            return 0;
        }
        int n = nums.size();
        int l = 0, r = 0, p = 1, ans = 0;
        while(r < n){
            p *= nums[r];
            while(l <= r && p >= k){
                p /= nums[l++];
            }
            ans += r++ - l + 1;
        }
        return ans;
    }
};