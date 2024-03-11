//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[], long long temp[], int start, int mid, int end){
    
        int i = start, k = start, j = mid+1;
        long long count = 0;
        
        while(i<=mid && j<=end){
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            }
            else{ // arr[i] > arr[j]
                temp[k++] = arr[j++];
                count += (mid-i+1); // Inversions occurence
            }
        }
        
        while(i<=mid){
            temp[k++] = arr[i++];
        }
        
        while(j<=end){
            temp[k++] = arr[j++];
        }
        
        // Copy elements back from temp to arr
        int m = start;
        for (int n = start; n <= end; n++) {
            arr[n] = temp[n];
        }
        return count;
    }
    
    
    long long mergeSort(long long arr[], long long temp[], int start, int end){
        if(start>=end){
            return 0;
        }
        long long count = 0;
        int mid = (start+end)/2;
        count += mergeSort(arr,temp,start,mid);
        count += mergeSort(arr,temp,mid+1,end);
        
        count += merge(arr,temp,start,mid,end);
        
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long* temp = new long long[N];
        return mergeSort(arr,temp,0,N-1);;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
