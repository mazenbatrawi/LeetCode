class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for(int i = 0; i < n; i++){
            pos[nums[i]].push_back(i);
        }
        for(int i = 0; i < n; i++){
            int idx = lower_bound(pos[nums[i]].begin(), pos[nums[i]].end(), i + 1) - pos[nums[i]].begin();
            if(idx < (int) pos[nums[i]].size()){
                idx = pos[nums[i]][idx];
                if(idx - i <= k){
                    return true;
                }
            }
        }
        return false;
    }
};