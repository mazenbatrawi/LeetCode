class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if(m > n) return "";
        vector<vector<int>> pos_lower(26), pos_upper(26);
        for(int i = 0; i < n; i++){
            if('a' <= s[i] && s[i] <= 'z'){
                pos_lower[s[i] - 'a'].push_back(i);
            }
            else{
                pos_upper[s[i] - 'A'].push_back(i);
            }
        }
        vector<int> cnt_upper(26, 0), cnt_lower(26, 0);
        for(char c : t){
            if('a' <= c && c <= 'z'){
                cnt_lower[c - 'a'] += 1;
            }
            else{
                cnt_upper[c - 'A'] += 1;
            }
        }
        int len = 1e6, l = -1, r = -1;
        for(int i = 0; i < n; i++){
            int mx = -1;
            bool ok = 1;
            for(int j = 0; j < 26; j++){
                if(cnt_lower[j] == 0) continue;
                int idx = lower_bound(pos_lower[j].begin(), pos_lower[j].end(), i) - pos_lower[j].begin();
                int has = (int) pos_lower[j].size() - idx;
                ok &= has >= cnt_lower[j];
                if(!ok) break;
                if(has >= cnt_lower[j]){
                    mx = max(mx, pos_lower[j][idx + cnt_lower[j] - 1]);
                }
            }
            for(int j = 0; j < 26; j++){
                if(cnt_upper[j] == 0) continue;
                int idx = lower_bound(pos_upper[j].begin(), pos_upper[j].end(), i) - pos_upper[j].begin();
                int has = (int) pos_upper[j].size() - idx;
                ok &= has >= cnt_upper[j];
                if(!ok) break;
                if(has >= cnt_upper[j]){
                    mx = max(mx, pos_upper[j][idx + cnt_upper[j] - 1]);
                }
            }
            if(ok && mx - i + 1 < len){
                len = mx - i + 1;
                l = i, r = mx;
            }
            if(len == m) break;
        }
        string ans = "";
        if(l != -1){
            for(int i = l; i <= r; i++) ans += s[i];
        }
        return ans;
    }
};