void bfs (queue<pair<int,int>>& store, vector<vector<int>>& floodedImg, vector<vector<int>>& visited){

    int r = store.front().first;
    int c = store.front().second;

    vector<pair<int,int>> dirs = {{r-1,c},
                                 {r+1,c},
                                 {r,c-1},
                                 {r,c+1}};
    
    for(auto dir:dirs){
        int cur_r = dir.first;
        int cur_c = dir.second;

        if(cur_r>=0 && cur_c>=0 && cur_r<floodedImg.size() && cur_c<floodedImg[0].size()){
            // valid coordinates
            if(floodedImg[r][c] == floodedImg[cur_r][cur_c] && visited[cur_r][cur_c] == -1){
                // org color of src and not visited 
                store.push(dir);
            }
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

    int m = image.size();
    int n = image[0].size();
    vector<vector<int>> visited (m,vector<int>(n,-1)); // -1 represents not visited
    vector<vector<int>> floodedImg = image;
    queue<pair<int,int>> store;
    store.push({sr,sc});

    while(!store.empty()){
        bfs(store,floodedImg,visited);
        floodedImg[store.front().first][store.front().second] = color;
        visited[store.front().first][store.front().second] = 1; // visited
        store.pop();
    }

    return floodedImg;
}
