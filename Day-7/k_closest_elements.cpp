//Approach 1
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


//Approach 2
//using binary search + 2 pointer method
class Solution {
public:
    int lowerBound(vector<int> arr, int x){
        
        int s = 0, e = arr.size()-1;
        int ans = e;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                e = mid-1;
            } 
            else {
                s = mid + 1;
            }
        }
    return ans;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int h = lowerBound(arr,x);
        int l = h-1;
        while(k>0){
            if(l<0){
                h++; //all closest elements will be on the high side
            }
            else if(h>arr.size()-1){
                l--;
            }
            else if(abs(x-arr[l])>abs(arr[h]-x)){
                h++;
                //to increase the window size
            }
            else{
                l--;
            }
            k--;
        }
        return vector<int>(arr.begin()+l+1, arr.begin()+h);
    }
};
