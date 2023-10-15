class Solution
{
  public:
  
    bool Possible_Sol(int arr[], int n, int k, long long sol){
        int countPainters = 1;
        long long sumOfLength = 0;
        for(int i = 0;i<n;i++){
            if(arr[i]>sol){
                return false;
            }
            else if(sumOfLength + arr[i]>sol){
                countPainters++;
                sumOfLength = arr[i];
                if(countPainters>k){
                    return false;
                }
            }
            else{
                sumOfLength+=arr[i];
            }
        }
        return true;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        // code here
        long long start = 0, end = 0;
        for(int i = 0; i<n ; i++){
            end += arr[i];
        }
        long long min_time = -1;
        while(start<=end){
            long long mid = start + (end-start)/2;
            if(Possible_Sol(arr,n,k,mid)){
                min_time = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return min_time;
    }
};
