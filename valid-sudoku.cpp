class Solution {
    public:
        bool isValid(vector<vector<char>>& board, int row, int col) {
            int n = board.size();
            int m = board[0].size();
    
            cout << row << ", " << col << "Hello ";
    
            for(int i = 0; i < n; i++) {
                if(i != row) {
                    if(board[i][col] == board[row][col]) {
                        return false;
                    }
                }
            }
    
            for(int j = 0; j < m; j++) {
                if(j != col) {
                    if(board[row][j] == board[row][col]) {
                        return false;
                    }
                }
            }
    
            for(int i = 3*(row/3); i <= 3*(row/3) + 2; i++) {
                for(int j = 3*(col/3); j <= 3*(col/3) + 2; j++) {
                    if(i != row || j != col) {
                        if(board[row][col] == board[i][j]) {
                            return false;
                        }
                    }
                }
            }
    
            return true;
        }
    
        bool isValidSudoku(vector<vector<char>>& board) {
            int n = board.size();
            int m = board[0].size();
            
            bool ok = true;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(board[i][j] != '.' && !isValid(board, i, j)) {
                        ok = false;
                        break;
                    }
                }
                if(!ok) {
                    break;
                }
            }
    
            return ok;
        }
    };