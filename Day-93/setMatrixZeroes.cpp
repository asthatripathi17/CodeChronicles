// TC = O(mn) and SC = O(m+n)
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

// TC = O(mn) and SC = O(1)
void setZeroes(vector<vector<int>>& matrix) {
        
        int c0 = 1;
        int m = matrix.size(), n = matrix[0].size();
        
        // finding rows and cols with zeroes
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j == 0){
                        c0 = 0;
                    }
                    else{
                        matrix[0][j] = 0;
                    }
                    
                }
            }
        }

        // turning submatrix into zeroes
        for(int i = m-1; i>0; i--){
            for(int j = n-1; j>0; j--){
                //checking for each element
                if((matrix[i][0] && matrix[0][j]) == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // turning the col into zeroes
        if(matrix[0][0] == 0){ //for row0 dependency on it
            for(int j = 1; j<n; j++){
                matrix[0][j] = 0;
            }
        }

        // turning the col into zeroes
        if(c0 == 0){ //for col0 dependency on it
            for(int i = 0; i<m; i++){
                matrix[i][0] = 0;
            }
        }

    }
