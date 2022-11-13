class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> ans;
        for(int i = 0; i < n - 2; i++){
            while(i > 0 && i < n - 2 && nums[i] == nums[i - 1]) i++;
            for(int j = i + 1; j < n - 1; j++){
                int need = -nums[i] - nums[j];
                int idx = lower_bound(nums.begin() + j + 1, nums.end(), need) - nums.begin();
                if(idx < n && nums[idx] == need){
                    vector<int> v = {nums[i], nums[j], nums[idx]};
                    sort(v.begin(), v.end());
                    ans.insert(v);
                }
            }
        }
        vector<vector<int>> v;
        for(auto &it : ans){
            v.push_back(it);
        }
        return v;
    }
};