int maxLocalCalc(vector<vector<int>>& grid, int i, int rows, int j, int cols){
    int maxi = INT_MIN;
    for (int r = i; r < rows; ++r) {
        for (int c = j; c < cols; ++c) {
            if (grid[r][c] > maxi) {
                maxi = grid[r][c];
            }
        }
    }
    return maxi;
}
vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> maxLocal(rows - 2, vector<int>(cols - 2));

    for (int i = 0; i < rows - 2; i++) {
        for (int j = 0; j < cols - 2; j++) {
            maxLocal[i][j] = maxLocalCalc(grid, i, i + 3, j, j + 3);
        }
    }

    return maxLocal;
}
