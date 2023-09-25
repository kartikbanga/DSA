class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // Transpose the matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
                swap(matrix[i][j],matrix[j][i]);
        }
        
        // reverse each row,because the resultant matrix should be rotated 90deg clockwise.
        for(int i=0;i<n;i++)
            reverse(matrix[i].begin(),matrix[i].end());
        
    }
};
