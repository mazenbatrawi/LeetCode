class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        auto comp = [&] (int &x, int &y) -> bool {
            return x % 2 < y % 2;
        };
        sort(nums.begin(), nums.end(), comp);
        return nums;
    }
};