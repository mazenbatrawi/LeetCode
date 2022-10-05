class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        function<void(string)> build = [&] (string s){
            int x = stoi(s);
            if(x > n){
                return;
            }
            ans.push_back(x);
            for(char c = '0'; c <= '9'; c++){
                build(s + c);
            }
        };
        for(int i = 1; i <= 9; i++){
            build(to_string(i));
        }
        return ans;
    }
};