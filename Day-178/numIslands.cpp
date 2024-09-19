// BFS Approach

void helperFunc(queue<vector<int>>& bfs,vector<vector<int>>& visited, vector<vector<char>>& grid){
        
        int r = bfs.front()[0];
        int c = bfs.front()[1];
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dir = {{r-1,c},
                                   {r+1,c},
                                   {r,c-1},
                                   {r,c+1}};

        for(int i = 0; i<4; i++){

            int cur_r = dir[i][0];
            int cur_c = dir[i][1];

            if(cur_r>=0 && cur_r<m && cur_c>=0 && cur_c<n){
                // valid
                if(visited[cur_r][cur_c] == -1 && (grid[cur_r][cur_c] - '0') == 1){
                    // not visited and land
                    bfs.push({cur_r,cur_c});
                    visited[cur_r][cur_c] = 1;
                }
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {

        int countLand = 0;

        int row = grid.size();
        int col = grid[0].size();

        // island checker - check in 4 directions
        
        vector<vector<int>> visited (row,vector<int>(col,-1));
        // -1 --> not visited and 1 --> visited

        queue<vector<int>> bfs;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){

                if(grid[i][j] - '0' == 1 && visited[i][j] == -1){

                    // perform bfs
                    bfs.push({i,j});
                    countLand++;
                    visited[i][j] = 1;

                    while(!bfs.empty()){
                        helperFunc(bfs,visited,grid);
                        bfs.pop();
                    }
                }
            }
        }

        return countLand;
    }
