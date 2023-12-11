class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        //using logic
        //other approaches - using binary search, using hashing.
        int n = arr.size();
        int i;
        for(i = 0; i<3*n/4; i++){
            if(arr[i] == arr[i+n/4])
                return arr[i];
        }
        return arr[i];
    }
};
