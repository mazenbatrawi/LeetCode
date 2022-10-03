class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;
        for(int i = 1; i <= max(a, b); i++){
            ans += (a % i == 0 && b % i == 0);
        }
        return ans;
    }
};