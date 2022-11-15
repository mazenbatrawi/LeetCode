class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        int n = nums.size();
        for(int i = 0; i < k - 1; i++){
            s.insert(nums[i]);
        }
        vector<int> ans;
        for(int i = k - 1; i < n; i++){
            if(i != k - 1){
                s.erase(s.find(nums[i - k]));
            }
            s.insert(nums[i]);
            ans.push_back(*s.rbegin());
        }
        return ans;
    }
};