class Solution{
    public:
    bool isSafe(int n, int x, int y, vector<vector<int>> &m, vector<vector<bool>> &visited){
        
        if((x>=0 && x<n) && (y>=0 && y<n) && (m[x][y] && visited[x][y] == false)){ // checking boundary condition + is there blockage? + visited or not?
            return true;
        }
        return false;
    }
    
    void solveMaze(vector<vector<int>> &m, int n, int srcr, int srcc, vector<vector<bool>> &visited, vector<string> &paths, string output){

        // Base Case
        if(srcr == n-1 && srcc == n-1){
            // reached destination
            paths.push_back(output);
            return;
        }
        
        // Movements
        // Down --> srcr+1, srcc
        if(isSafe(n, srcr+1, srcc, m, visited)){
            visited[srcr+1][srcc] = true;
            solveMaze(m,n,srcr+1,srcc,visited,paths,output+'D');
            
            //Backtrack
            visited[srcr+1][srcc] = false;
        }
        
        // Left --> srcr, srcc-1
        if(isSafe(n, srcr, srcc-1, m, visited)){
            visited[srcr][srcc-1] = true;
            solveMaze(m,n,srcr,srcc-1,visited,paths,output+'L');
            
            //Backtrack
            visited[srcr][srcc-1] = false;
        }
        
        // Right --> srcr, srcc+1
        if(isSafe(n, srcr, srcc+1, m,visited)){
            visited[srcr][srcc+1] = true;
            solveMaze(m,n,srcr,srcc+1,visited,paths,output+'R');
            
            //Backtrack
            visited[srcr][srcc+1] = false;
        }
        
        // Up --> srcr-1,srcc
        if(isSafe(n, srcr-1, srcc, m,visited)){
            visited[srcr-1][srcc] = true;
            solveMaze(m,n,srcr-1,srcc,visited,paths,output+'U');
            
            //Backtrack
            visited[srcr-1][srcc] = false;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> paths;
        //Blockage from the source --> No path exists
        if(m[0][0] == 0){
            return paths;
        }
        //To track the visits of rat in a path
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        visited[0][0] = true; // source position is true
        
        string output = "";
    
        solveMaze(m,n,0,0, visited, paths, output);
        return paths;
    }
};
