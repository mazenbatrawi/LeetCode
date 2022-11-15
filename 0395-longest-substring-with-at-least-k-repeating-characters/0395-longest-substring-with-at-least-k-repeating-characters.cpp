class Solution {
public:
    int solve(int l, int r, string &s, int k){
        if(l > r){
            return 0;
        }
        if(l == r){
            return k == 1;
        }
        int n = s.size();
        vector<int> cnt(26, 0);
        for(int i = l; i <= r; i++){
            cnt[s[i] - 'a'] += 1;
        }
        int mx = 0;
        for(int i = l; i <= r; i++){
            if(cnt[s[i] - 'a'] < k){
                return max(solve(l, i - 1, s, k), solve(i + 1, r, s, k));
            }
        }
        return r - l + 1;
    }
    
    int longestSubstring(string s, int k) {
        int n = s.size();
        return solve(0, n - 1, s, k);
    }
};