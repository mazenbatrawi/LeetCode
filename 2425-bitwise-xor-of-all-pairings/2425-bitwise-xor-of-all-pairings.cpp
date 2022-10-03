class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n % 2 == 0 && m % 2 == 0){
            return 0;
        }
        int ans = 0;
        if(n % 2 == 0){
            for(int x : nums1){
                ans ^= x;
            }
        }
        else if(m % 2 == 0){
            for(int x : nums2){
                ans ^= x;
            }
        }
        else{
            for(int x : nums2){
                ans ^= x;
            }
            for(int x : nums1){
                ans ^= x;
            }
        }
        return ans;
    }
};