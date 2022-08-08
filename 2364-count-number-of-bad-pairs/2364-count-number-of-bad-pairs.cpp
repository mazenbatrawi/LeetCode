class Solution {
public:
    long long countBadPairs(vector<int>& a) {
        long long ans = 0;
        int n = a.size();
        map<int, int> cnt;
        for(int i = n - 1; i >= 0; i--){
            long long x = cnt[i - a[i]];
            ans += x;
            cnt[i - a[i]] += 1;
        }
        ans = (long long) n * (n - 1) / 2 - ans;
        return ans;
    }
};