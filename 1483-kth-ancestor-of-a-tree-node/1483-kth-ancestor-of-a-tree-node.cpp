class TreeAncestor {
    int up[50005][20];
    int depth[50005];
public:
    TreeAncestor(int n, vector<int>& parent) {
        parent[0] = 0;
        for(int j = 0; j < 20; j++){
            for(int i = 0; i < n; i++){
                if(j == 0){
                    up[i][0] = parent[i];
                }
                else{
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }
                if(i != 0){
                    depth[i] = depth[parent[i]] + 1;
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node] < k) return -1;
        for(int i = 0; i < 20; i++){
            if(k & (1 << i)){
                if(node == -1) return -1;
                node = up[node][i];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */