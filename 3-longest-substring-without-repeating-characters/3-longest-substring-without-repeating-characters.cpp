class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> cnt(257, 0);
        auto check = [&](){
            bool ok = 1;
            for(int k = 0; k < 257; k++){
                ok &= (cnt[k] <= 1);
            }
            return ok;
        };
        int ans = 0;
        for(int i = 0, j = 0; i < n; i++){
            cnt[s[i]] += 1;
            while(!check()){
                cnt[s[j]] -= 1;
                j += 1;
            }
            if(i - j + 1 > ans){
                ans = i - j + 1;
            }
        }
        return ans;
    }
};