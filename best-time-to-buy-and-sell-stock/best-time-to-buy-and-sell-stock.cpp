class Solution {
public:
    
    int maxProfit(vector<int>& a) {
        int n = a.size();
        multiset<int> s;
        map<int, int> cnt;
        for(int i = 0; i < n; i++){
            s.insert(a[i]);
            cnt[a[i]]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            cnt[a[i]]--;
            if(cnt[a[i]] == 0){
                s.erase(a[i]);
            }
            if(!s.empty()){
                ans = max(ans, -a[i] + *s.rbegin());
            }
        }
        return ans;
    }
};