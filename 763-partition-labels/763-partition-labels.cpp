class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, -1);
        int n = s.size();
        for(int i = 0; i < n; i++){
            last[s[i] - 'a'] = i;
        }
        int i = 0;
        vector<int> ans;
        while(true){
            int cnt = 0;
            int x = last[s[i] - 'a'];
            while(i <= x){
                cnt += 1;
                x = max(x, last[s[i] - 'a']);
                i += 1;
            }
            ans.push_back(cnt);
            if(i == n){
                break;
            }
        }
        return ans;
    }
};