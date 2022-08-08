class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<bool> no(n + 1, 0);
        for(int x : restricted){
            no[x] = 1;
        }
        vector<int> adj[n + 1];
        for(vector<int> v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n + 1, 0);
        stack<int> s;
        s.push(0);
        int ans = 0;
        while(!s.empty()){
            int x = s.top();
            s.pop();
            visited[x] = 1;
            ans += 1;
            for(int y : adj[x]){
                if(!visited[y] && !no[y]){
                    s.push(y);
                    visited[y] = 1;
                }
            }
        }
        return ans;
    }
};