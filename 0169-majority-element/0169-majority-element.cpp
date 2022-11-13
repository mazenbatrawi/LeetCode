class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = -1e9 - 1;
        for(int i = 0; i < (int) nums.size(); i++){
            int cnt = 1;
            i++;
            while(i < (int) nums.size() && nums[i] == nums[i - 1]){
                cnt++, i++;
            }
            i--;
            if(cnt > (int) nums.size() / 2) ans = nums[i];
        }
        return ans;
    }
};