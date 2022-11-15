class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        if(is_sorted(nums.begin(), nums.end())){
            return;
        }
        reverse(nums.begin(), nums.end());
        next_permutation(nums.begin(), nums.end());
    }
};