class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans, cnt(1001, 0);
        for(int x : nums1){
            cnt[x] += 1;
        }
        for(int x : nums2){
            if(cnt[x] > 0){
                ans.push_back(x);
            }
            cnt[x]--;
        }
        return ans;
    }
};