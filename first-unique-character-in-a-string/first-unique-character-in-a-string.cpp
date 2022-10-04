class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26, 0);
        for(char c : s){
            cnt[c - 'a'] += 1;
        }
        for(int i = 0; i < (int) s.size(); i++){
            if(cnt[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};