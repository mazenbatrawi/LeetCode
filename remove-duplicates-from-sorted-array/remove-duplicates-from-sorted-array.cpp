class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0, j = 0; i < n; i++){
            i += 1;
            ans += 1;
            while(i < n && nums[i] == nums[i - 1]){
                i += 1;
            }
            i -= 1;
            nums[j++] = nums[i];
        }
        return ans;
    }
};