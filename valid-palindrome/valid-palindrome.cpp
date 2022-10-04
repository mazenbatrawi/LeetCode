class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(); 
        string t = "";
        for(int i = 0; i < n; i++){
            if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
                t += s[i];
                continue;
            }
            s[i] = tolower(s[i]);
            if(s[i] >= 'a' && s[i] <= 'z') t += s[i];
        }
        n = t.size();
        for(int i = 0, j = n - 1; i < j; i++, j--){
            if(t[i] != t[j]){
                return false;
            }
        }
        return true;
    }
};