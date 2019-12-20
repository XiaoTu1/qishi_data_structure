class Solution {
public:
    /**
     * @param matrix: a boolean 2D matrix
     * @return: an integer
     */
    int maximalRectangle(vector<vector<bool>> &matrix) {
        // write your code here
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        
        vector<vector<int>> matrix2(m, vector<int>(n + 1));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix2[i][j] = matrix[i][j];
            }
            
            if (i == 0) {
                continue;
            }
            
            for (int j = 0; j < n; j++) {
                if (matrix2[i][j] == 0) {
                    continue;
                }
                matrix2[i][j] += matrix2[i - 1][j];
            }
        }
        
        int res = 0;
        for (int i = 0; i < m; i++) {
            stack<int> S;
            for (int j = 0; j < n + 1; j++) {
                while (!S.empty() && matrix2[i][S.top()] >= matrix2[i][j]) {
                    int temp = S.top();
                    S.pop();
                    int width = (S.empty()) ? j : j - S.top() - 1;
                    res = max(res, matrix2[i][temp] * width);
                }
                S.push(j);
            }
        }
        
        return res;
    }
};
