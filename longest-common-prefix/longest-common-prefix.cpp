class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.empty())return ans;
        int mn = 1e9 + 5;
        for(int i = 0; i < strs.size(); i++){
            mn = min(mn, (int)strs[i].size());
        }
        char c = strs[0][0];
        int cnt = 0;
        int pos = 0;
        while(cnt < mn){
            cout << cnt << " " << pos << " " << c << endl;
            bool ok = 1;
            for(int j = 0; j < strs.size(); j++){
                if(strs[j][pos] != c)ok = false;
            }
            if(ok){
                ans += c;
                pos++;
                c = strs[0][pos];
                cnt++;
            }
            else break;
        }
        return ans;
    }
};