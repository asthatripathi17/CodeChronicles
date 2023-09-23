class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int X) {
      
        int s = 0;
        int e = (arr.size())*(arr[0].size()) - 1;

        while(s<=e){
            int mid = s + (e-s)/2;
            // x = col*rm + cm ; col = arr[0].size()
            int rm = mid/arr[0].size();
            int cm = mid%arr[0].size();
            if(arr[rm][cm] == X){
                return true;
            }
            else if(arr[mid/arr[0].size()][mid%arr[0].size()] < X){
                //go right
                s = mid + 1;
            }
            else{
                //go left
                e = mid - 1;
            }
        }

        return false;
    }
};
