class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int rowL = 0;
        int rowR = row - 1;


        while(rowL <= rowR) {
            int rowMid = rowL + (rowR - rowL) / 2;
            int colL = 0;
            int colR = col - 1;
            
            if(matrix[rowMid][0] == target) {
                return true;
            }
            else if(matrix[rowMid][0] > target) {
                rowR = rowMid - 1;
            }
            else {
                rowL = rowMid;

                while(colL <= colR) {
                    int colMid = colL + (colR - colL) / 2;
                    if(matrix[rowMid][colMid] == target) {
                        return true;
                    }
                    else if(matrix[rowMid][colMid] < target) {
                        colL = colMid + 1;
                    }
                    else {
                        colR = colMid - 1;
                    }
                }
                rowL++;
            }
        }

        return false;
    }
};
