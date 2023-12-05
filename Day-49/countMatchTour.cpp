class Solution {
public:
    int numberOfMatches(int n) {
        int ta = 0, matches = 0; //ta = teams advancing
        int tot_match = 0;
        while(ta!=1){
            if(n%2 == 0){
                matches = n/2;
                ta = n/2;
            }
            else{
                matches = (n-1)/2;
                ta = (n+1)/2;
            }
            tot_match += matches;
            n = ta;
        }
        return tot_match;
    }
};
