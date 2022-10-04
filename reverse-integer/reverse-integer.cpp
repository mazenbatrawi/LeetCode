class Solution {
public:
    int reverse(int x) {
        long long n = x;
        bool ok = n < 0;
        string s = to_string(n);
        for(int i = 0; i < (int) s.size() / 2; i++){
            swap(s[i], s[(int) s.size() - i - 1]);
        }
        n = stoll(s);
        n = n * (ok ? -1 : 1);
        if(n > INT_MAX || n < INT_MIN){
            n = 0;
        }
        return n;
    }
};