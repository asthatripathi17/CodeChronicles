//using two pointer approach
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int l = 0, h = arr.size() - 1;
        while(h-l!=k-1){
            if(abs(arr[l] - x)>abs(arr[h] - x)){
                l++;
            }
            else{
                h--;
            }
        }
        return vector<int>(arr.begin()+l,arr.begin()+h+1);
    }
};
