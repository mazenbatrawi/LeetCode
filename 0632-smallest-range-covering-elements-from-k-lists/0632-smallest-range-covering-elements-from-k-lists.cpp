class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (int) nums[i].size(); j++){
                v.push_back({nums[i][j], i});
            }
        }
        sort(v.begin(), v.end());
        int l = 0, r = 0, m = v.size(), zero = n;
        vector<int> cnt(n, 0), ans;
        while(r < m){
            cnt[v[r].second]++;
            zero -= cnt[v[r].second] == 1;
            while(true){
                if(cnt[v[l].second] == 1){
                    break;
                }
                cnt[v[l].second]--;
                if(cnt[v[l].second] == 0){
                    zero += 1;
                }
                l++;
            }
            if(zero == 0){
                if(ans.empty() || v[r].first - v[l].first < ans[1] - ans[0]){
                    ans = {v[l].first, v[r].first};
                }
                else{
                    if(v[r].first - v[l].first == ans[1] - ans[0] && v[l].first < ans[0]){
                        ans = {v[l].first, v[r].first};
                    }
                }
            }
            r++;
        }
        return ans;
    }
};