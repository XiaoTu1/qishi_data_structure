class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }
        
        int iRow = 0, iCol = n - 1;
        while (iRow  < m && iCol >= 0) {
            while (iRow  < m && iCol >= 0 && matrix[iRow][iCol] > target) {
                iCol--;
            }
            while (iRow  < m && iCol >= 0 && matrix[iRow][iCol] < target) {
                iRow++;
            }
            if (iRow  < m && iCol >= 0 && matrix[iRow][iCol] == target) {
                return true;
            }
        }
        
        return false;
    }
};
