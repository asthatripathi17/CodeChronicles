class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        
        int i = 0;
        int j = a.size() - 1;
        while(i<j){
            if((a[j]&1)==0 && (a[i]&1)==1){
                swap(a[i],a[j]);
                i++;
                j--;
            }
            else if((a[i]&1)==0){
                i++; 
            }
            else if((a[j]&1)==1){
                j--;
            }
        }
        return a;
    }
};
