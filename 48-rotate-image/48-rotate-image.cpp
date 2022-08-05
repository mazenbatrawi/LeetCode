class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> a(n, vector<int> (n));
        int x = 0, y = 0;
        for(int j = 0; j < n; j++){
            for(int i = n - 1; i >= 0; i--){
                a[x][y] = matrix[i][j];
                y += 1;
                if(y == n){
                    x += 1;
                    y = 0;
                }
            }
        }
        matrix = a;
    }
};