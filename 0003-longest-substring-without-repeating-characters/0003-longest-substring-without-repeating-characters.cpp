class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int ans = 0;
        vector<int> cnt(300, 0);
        while(r < n){
            cnt[s[r]]++;
            r++;
            while(*max_element(cnt.begin(), cnt.end()) > 1){
                cnt[s[l]]--;
                l++;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};