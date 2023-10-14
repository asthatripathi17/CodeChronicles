class Solution {
public:
    bool PossibleSol(vector<int> w, int d, int sol){
        int wtSum = 0;
        int countD = 1;
        for(int i = 0;i<w.size();i++){
            if(wtSum+w[i]<=sol){
                wtSum+=w[i];
            }
            else{
                countD++;
                wtSum = w[i];
                if(countD>d || w[i]>sol){
                    return false;
                }
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int s = 0, e = accumulate(weights.begin(), weights.end(),0);
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(PossibleSol(weights,days,mid)){
                e = mid-1;
                ans = mid;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};
