class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> cnt(26, 0);
        for(char c : word){
            cnt[c - 'a'] += 1;
        }
        bool ok = 0;
        for(char c = 'a'; c <= 'z'; c++){
            if(cnt[c - 'a'] == 0){
                continue;
            }
            bool temp = 1;
            cnt[c - 'a'] -= 1;
            int x = -1;
            for(char cc = 'a'; cc <= 'z'; cc++){
                if(cnt[cc - 'a'] == 0){
                    continue;
                }
                if(x == -1){
                    x = cnt[cc - 'a'];
                }
                temp &= cnt[cc - 'a'] == x;
            }
            cnt[c - 'a'] += 1;
            ok |= temp;
        }
        return ok;
    }
};