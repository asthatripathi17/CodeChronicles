class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        //for bfs as we need to find a min path in a grid
        queue<vector<int>> que;
        int i = 0, j = 0;
        que.push({0,0,k}); //starting point
        
        //data structure to check visited nodes using the constraints given
        bool visited[41][41][1601]; 
        memset(visited, false, sizeof(visited)); //initialize every value with false

        vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}}; //defined the directions - Up|Down|Left|Right

        int steps = 0;
        //starting the bfs
        while(!que.empty()){
            
            int size = que.size();
            //to traverse all the neighbours of popped elements
            while(size--){
                vector<int> temp = que.front();
                que.pop();

                int curr_i = temp[0];
                int curr_j = temp[1];
                int obst = temp[2];

                if(curr_i == m-1 && curr_j == n-1 ) return steps; //end point reached

                for(vector<int> &dir: directions){
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];
                    
                    if(new_i<0 || new_i >= m || new_j<0 || new_j >=n) continue; //out of bound

                    if(grid[new_i][new_j] == 0 && !visited[new_i][new_j][obst]){ //if not visited and there is no obstacle as it is 0
                        que.push({new_i,new_j,obst});
                        visited[new_i][new_j][obst] = true; //visited now
                    }
                    else if(grid[new_i][new_j] == 1 && obst>0 && !visited[new_i][new_j][obst-1]){ //has obstacle but obstacle count > 0
                        que.push({new_i,new_j,obst-1});
                        visited[new_i][new_j][obst-1] = true;
                    }
                }
            }
            steps++;
        } //till queue is empty
        return -1; //target not found
    }
};
