class Solution {
public:
    bool PossibleSol(vector<int> pos, int m, int sol){
        int countBall = 1, ball_pos = pos[0];
        for(int i = 0;i<pos.size();i++){
            if(pos[i]-ball_pos>=sol){
                countBall++;
                ball_pos = pos[i];
            }
            if(countBall==m){
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int start = 1, end = position[position.size()-1];
        while(start<=end){
            int mid = start+(end-start)/2;
            if(PossibleSol(position,m,mid)){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return end;
    }
};
