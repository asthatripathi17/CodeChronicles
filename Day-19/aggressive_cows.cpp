class Solution {
public:
    //to find the placement of cows
    bool PossibleSol(vector<int> stalls, int n, int k, int sol){
        int countCow = 1, last_cow = stalls[0];
        for(int i = 0;i<n;i++){
            if(stalls[i]-last_cow>=sol){
                countCow++;
                last_cow = stalls[i];
            }
            if(k == countCow) return true;
        }
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int start = 1, end = stalls[n-1]-stalls[0];
        while(start<=end){
            int mid = start + (end-start)/2;
            if(PossibleSol(stalls,n,k,mid)){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return end;
    }
};
