void rowFlip(vector<vector<int>>& grid, int rIndex){
    for(int i = 0; i<grid[0].size(); i++){
        if(grid[rIndex][i] == 0) 
            grid[rIndex][i] = 1;
        else
            grid[rIndex][i] = 0;
    }
}
void colFlip(vector<vector<int>>& grid, int cIndex){
    for(int i = 0; i<grid.size(); i++){
        if(grid[i][cIndex] == 0) 
            grid[i][cIndex] = 1;
        else
            grid[i][cIndex] = 0;
    }
}
int rScore(vector<vector<int>>& grid, int rIndex){
    int ans = 0;
    for(int j = grid[0].size()-1; j>=0; j--){
        int place = grid[0].size()-1 - j;
        if(grid[rIndex][j] == 1){
            ans += pow(2,place);
        }
    }

    return ans;
}
int matrixScore(vector<vector<int>>& grid) {
    
    // checking if first element of a row is zero
    for(int i = 0; i<grid.size(); i++){
        if(grid[i][0] == 0){
            // Flipping the row
            rowFlip(grid,i);
        }
    }

    //  First Column is already taken care
    for(int j = 1; j<grid[0].size(); j++){
        int countZ = 0, countO = 0;
        for(int i = 0; i<grid.size(); i++){
            if(grid[i][j] == 1){
                countO++;
            }
            else{
                countZ++;
            }
        }

        if(countZ>countO){
            // call col flip func
            colFlip(grid,j);
        }
    }
    
    int score = 0; 

    // Score Calculator => row wise summation
    for(int i = 0; i<grid.size(); i++){
        // call for each row
        score += rScore(grid,i);
    }

    return score;
}
