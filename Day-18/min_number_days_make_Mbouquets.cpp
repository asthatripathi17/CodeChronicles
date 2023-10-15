class Solution {
public:
    bool possibleSol(vector<int> arr, int m, int k, int sol){
        int bouq = 0, flower = 0;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i]<=sol){
                flower++;
                if(flower==k){
                    bouq++;
                    flower = 0;
                }
                if(bouq==m){
                    return true;
                }
            }
            else{
                flower = 0;
                continue;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long mul = (long)k*m;
        if(mul>bloomDay.size()) return -1;
        int start = *min_element(bloomDay.begin(),bloomDay.end());
        int end = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(possibleSol(bloomDay,m,k,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};
