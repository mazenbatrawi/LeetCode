class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> cnt(26, 0);
        int l = 0, r = 0, ans = 0;
        while(r < n){
            cnt[s[r] - 'A']++;
            int len = r - l + 1;
            while(len - *max_element(cnt.begin(), cnt.end()) > k){
                cnt[s[l] - 'A']--;
                l++, len--;
            }
            r++;
            ans = max(ans, len);
        }
        return ans;
    }
};