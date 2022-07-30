class Solution {
public:
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n;
    vector<vector<int>> color, v;
    vector<int> sz;
    
    bool check(int x, int y){
        return 0 <= x && x < n && 0 <= y && y < n;
    }
    
    void dfs(int i, int j, int c){
        color[i][j] = c;
        sz[c] += 1;
        for(int a = 0; a < 4; a++){
            int nx = i + dx[a], ny = j + dy[a];
            if(!check(nx, ny)){
                continue;
            }
            if(color[nx][ny] != -1 || v[nx][ny] == 0){
                continue;
            }
            dfs(nx, ny, c);
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        n = grid[0].size();
        v = grid;
        color = vector<vector<int>> (n, vector<int> (n, -1));
        sz = vector<int> (n * n, 0);
        int c = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(color[i][j] != -1 || v[i][j] == 0){
                    continue;
                }
                dfs(i, j, c);
                if(sz[c] > ans){
                    ans = sz[c];
                }
                c += 1;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(v[i][j] == 1){
                    continue;
                }
                set<int> s;
                for(int a = 0; a < 4; a++){
                    int nx = i + dx[a], ny = j + dy[a];
                    if(!check(nx, ny)){
                        continue;
                    }
                    if(!v[nx][ny]){
                        continue;
                    }
                    s.insert(color[nx][ny]);
                }
                int add = 1;
                if(!s.empty()){
                    for(int x : s){
                        add += sz[x];
                    }
                }
                if(ans < add){
                    ans = add;
                }
            }
        }
        return ans;
    }
};