class Solution {
public:
    
    int calc(vector<int> &a, int k){
        int ans = 0, n = a.size();
        int l = 0, r = 0;
        vector<int> cnt(n + 1, 0);
        int K = 0;
        while(r < n){
            cnt[a[r]] += 1;
            if(cnt[a[r]] == 1) K++;
            r++;
            while(K > k){
                cnt[a[l]]--;
                if(cnt[a[l]] == 0) K--;
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return calc(nums, k) - calc(nums, k - 1);
    }
};