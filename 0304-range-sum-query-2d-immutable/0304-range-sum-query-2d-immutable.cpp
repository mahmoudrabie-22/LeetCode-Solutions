class NumMatrix {
public:
    vector<vector<int>>prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefixSum.resize(m, vector<int>(n));
        
        for (int i = 0; i < m; i++)
{
    for (int j = 0; j < n; j++)
    {
        if (i == 0)
        {
            if (j == 0)
            {
                prefixSum[i][j] = matrix[i][j];
            }
            else
            {
                prefixSum[i][j] =
                    matrix[i][j] + prefixSum[i][j - 1];
            }
        }
        else
        {
            if (j == 0)
            {
                prefixSum[i][j] =
                    matrix[i][j] + prefixSum[i - 1][j];
            }
            else
            {
                prefixSum[i][j] =
                    matrix[i][j]
                    + prefixSum[i - 1][j]
                    + prefixSum[i][j - 1]
                    - prefixSum[i - 1][j - 1];
            }
        }
    }
}
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sumOfRange=-1;
        if(row1<=row2&&col1<=col2)
        {
            if(row1==0)
            {
                if(col1==0)
                {
                    sumOfRange=prefixSum[row2][col2];
                }
                else
                {
                    sumOfRange=prefixSum[row2][col2]-prefixSum[row2][col1-1];
                }
            }
            else
            {
                if(col1==0)
                {
                    sumOfRange=prefixSum[row2][col2]-prefixSum[row1-1][col2];
                }
                else
                {
                    sumOfRange=prefixSum[row2][col2]-prefixSum[row1-1][col2]-prefixSum[row2][col1-1]+prefixSum[row1-1][col1-1];
                }
            }
        }
        return sumOfRange;
    }
};