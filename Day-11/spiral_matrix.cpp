class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        int startrow = 0, startcol = 0, endrow = m-1, endcol = n-1;
        int c = 0, totel = m*n;;
        vector<int> res;

        while(c<totel){
            
            for(int i = startcol; i<=endcol && c<totel; i++){
                if(matrix[startrow][i]!=INT_MAX){
                    res.push_back(matrix[startrow][i]);
                    c++;
                }
                else{
                    continue;
                }
                matrix[startrow][i] = INT_MAX;
            }
            startrow++;
            for(int i = startrow; i<=endrow && c<totel; i++){
                if(matrix[i][endcol]!=INT_MAX){
                    res.push_back(matrix[i][endcol]);
                    c++;
                }
                else{
                    continue;
                }
                matrix[i][endcol] = INT_MAX;
            }
            endcol--;
            for(int i = endcol; i>=startcol && c<totel; i--){
                if(matrix[endrow][i]!=INT_MAX){
                    res.push_back(matrix[endrow][i]);
                    c++;
                }
                else{
                    continue;
                }
                matrix[endrow][i] = INT_MAX;
            }
            endrow--;
            for(int i = endrow; i>=startrow && c<totel; i--){
                if(matrix[i][startcol]!=INT_MAX){
                    res.push_back(matrix[i][startcol]);
                    c++;
                }
                else{
                    continue;
                }
                matrix[i][startcol] = INT_MAX;
            }
            startcol++;
        }
        return res;
    }
};
