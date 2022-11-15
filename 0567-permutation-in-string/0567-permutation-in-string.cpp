class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> cnt(26, 0);
        for(char c : s1){
            cnt[c - 'a'] += 1;
        }
        int l = 0, r = 0;
        vector<int> alt(26, 0);
        while(r < m){
            alt[s2[r] - 'a']++;
            bool ok = 1;
            while(ok){
                ok = 0;
                for(int i = 0; i < 26; i++){
                    ok |= alt[i] > cnt[i];
                }
                if(ok){
                    alt[s2[l++] - 'a']--;
                }
            }
            if(alt == cnt){
                return true;
            }
            r++;
        }
        return false;
    }
};