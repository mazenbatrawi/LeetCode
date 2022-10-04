class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            vector<bool> has(10, 0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(has[board[i][j] - '0']){
                        return false;
                    }
                    has[board[i][j] - '0'] = 1;
                }
            }
        }
        for(int i = 0; i < 9; i++){
            vector<bool> has(10, 0);
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.'){
                    if(has[board[j][i] - '0']){
                        return false;
                    }
                    has[board[j][i] - '0'] = 1;
                }
            }
        }
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                vector<bool> has(10, 0);
                for(int a = 0; a < 3; a++){
                    for(int b = 0; b < 3; b++){
                        int nx = i + a, ny = j + b;
                        char c = board[nx][ny];
                        if(c != '.' && has[c - '0']){
                            return false;
                        }
                        if(c != '.'){
                            has[c - '0'] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};