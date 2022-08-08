class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size(), m = b.size();
        vector<int> value(1001, 0);
        for(int i = 0; i < n; i++){
            value[a[i][0]] += a[i][1];
        }
        for(int i = 0; i < m; i++){
            value[b[i][0]] += b[i][1];
        }
        vector<vector<int>> ans;
        for(int i = 0; i < 1001; i++){
            if(value[i]){
                ans.push_back({i, value[i]});
            }
        }
        return ans;
    }
};