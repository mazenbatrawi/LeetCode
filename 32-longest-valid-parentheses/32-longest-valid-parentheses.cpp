class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int ans = 0;
        for(int j = 0; j < n; j++){
            int sum = 0, len = 0;
            for(int i = j; i < n; i++){
                sum += (s[i] == '(') - (s[i] == ')');
                len += 1;
                if(sum == 0){
                    ans = max(ans, len);
                }
                if(sum < 0){
                    sum = 0, len = 0;
                }
            }
        }
        return ans;
    }
};