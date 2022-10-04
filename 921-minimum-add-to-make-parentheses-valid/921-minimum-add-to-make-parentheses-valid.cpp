class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += (s[i] == '(') - (s[i] == ')');
            if(sum < 0){
                ans += 1;
                sum = 0;
            }
        }
        return abs(ans) + sum;
    }
};