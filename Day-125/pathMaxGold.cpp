vector<vector<int>> directions{{1,0},{0,-1},{0,1},{-1,0}};
int DFS(vector<vector<int>>& grid, int i, int j){

    // checking for invalid conditions
    if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==0){
        // checking boundary condition + is there blockage? + visited or not?
        return 0;
    }

    int maxGold = 0;
    int orgVal = grid[i][j];
    grid[i][j] = 0; // making it invalid to visit again in this path

    // Movements
    // Down --> DFS(grid,i+1,j); || Left --> DFS(grid,i,j-1);
    // Right --> DFS(grid,i,j+1); || Up --> DFS(grid,i-1,j);
    for(vector<int>& dir:directions){
        int new_i = i+dir[0];
        int new_j = j+dir[1];
        maxGold = max(maxGold, DFS(grid,new_i,new_j)); // max among different direction paths
    }

    // Backtracking
    grid[i][j] = orgVal;

    return orgVal+maxGold;
}

int getMaximumGold(vector<vector<int>>& grid) {
    
    int maxGold = 0;
    for(int i = 0; i<grid.size(); i++){
        for(int j = 0; j<grid[0].size(); j++){
            if(grid[i][j]!=0){ // contains gold
                maxGold = max(maxGold,DFS(grid,i,j)); // max among different start points
            }
        }
    }

    return maxGold;
}
