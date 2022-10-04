class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> has;
        for(int i = 0; i < (int) nums.size(); i++){
            int x = target - nums[i];
            if(has.count(x)){
                return {has[x], i};
            }
            has[nums[i]] = i;
        }
        return {};
    }
};