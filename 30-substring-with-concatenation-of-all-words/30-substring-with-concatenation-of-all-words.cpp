class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = words.size(), m = words[0].size();
        int add = n * m;
        unordered_map<string, int> has;
        for(string t : words){
            has[t] += 1;
        }
        for(int i = 0; i + add - 1 < (int) s.size(); i++){
            string t = s.substr(i, add);
            unordered_map<string, int> has2 = has;
            for(int j = i; j <= i + add - 1; j += m){
                string temp = s.substr(j, m);
                if(!has.count(temp)){
                    break;
                }
                if(has2[temp] == 1){
                    has2.erase(temp);
                }
                else{
                    has2[temp] -= 1;
                }
            }
            if(has2.empty()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};