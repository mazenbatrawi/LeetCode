class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        set<string> st;
        map<string, int> freq;
        for(int i = 0; i + 9 < n; i++){
            string t = "";
            for(int j = i; j <= i + 9; j++){
                t += s[j];
            }
            if(freq.count(t)){
                st.insert(t);
            }
            else{
                freq[t]++;
            }
        }
        vector<string> ans;
        for(auto &it : st) ans.push_back(it);
        return ans;
    }
};