void setZeroes(vector<vector<int>>& matrix) {
        
        unordered_set<int> seti,setj;
        int m = matrix.size(), n = matrix[0].size();
        
        // finding rows and cols with zeroes
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 0){
                    seti.insert(i);
                    setj.insert(j);
                }
            }
        }

        // turning all cols into zeroes
        for(auto i:seti){
            for(int j = 0;j<n;j++){
                matrix[i][j] = 0;
            }
        }
        // turning all rows into zeroes
        for(auto j:setj){
            for(int i = 0;i<m;i++){
                matrix[i][j] = 0;
            }
        }
    }
