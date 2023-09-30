class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i = 0; i<n; i++){
            int s = i+1;
            int e = n - 1;
            while(s<=e){
                int mid = s + (e-s)/2;
                if(arr[i]<0 ){
                    if(arr[i] == arr[mid]*2){
                        cout<<arr[mid]<<" "<<arr[i];
                        return true;
                    }
                    else if(arr[i]<arr[mid]*2){
                        e = mid - 1;
                    }
                    else if(arr[i]>arr[mid]*2){
                        s = mid + 1;
                    }
                }
                else{
                    if(arr[mid] == arr[i]*2){
                        cout<<arr[mid]<<" "<<arr[i];
                        return true;
                    }
                    else if(arr[mid]<arr[i]*2){
                        s = mid + 1;
                    }
                    else if(arr[mid]>arr[i]*2){
                        e = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};
