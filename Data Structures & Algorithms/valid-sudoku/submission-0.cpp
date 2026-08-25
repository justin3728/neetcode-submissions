class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //檢查row、col、9x9        
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '1';
                int boxId = (i / 3) * 3 + j / 3;

                if(row[i][num] == true) return false;
                if(col[j][num] == true) return false;
                if(box[boxId][num] == true) return false;

                row[i][num] = true;
                col[j][num] = true;
                box[boxId][num] = true;
            }
        }

        return true;
    }
};
