class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        auto fix = [&] (int l, int r){
            while(l < r){
                swap(nums[l], nums[r]);
                l++, r--;
            }
        };
        fix(0, n - k - 1);
        fix(n - k, n - 1);
        fix(0, n - 1);
    }
};