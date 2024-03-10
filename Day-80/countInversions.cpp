//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    // long long merge(long long arr[], long long temp[], int start, int mid, int end){
    
    //     int i = start, k = start, j = mid+1;
    //     long long count = 0;
        
    //     while(i<=mid && j<=end){
    //         if(arr[i]<arr[j]){
    //             temp[k++] = arr[i++];
    //         }
    //         else{ // arr[i] > arr[j]
    //             temp[k++] = arr[j++];
    //             count += (mid-i+1);
    //         }
    //     }
        
    //     while(i<=mid){
    //         temp[k++] = arr[i++];
    //     }
        
    //     while(j<=end){
    //         temp[k++] = arr[j++];
    //     }
        
    //     // // Print the contents of temp array
    //     // for (int n = 0; n < 42; n++) {
    //     //     cout << temp[n] << " ";
    //     // }
    //     // cout << endl;
                
    //     // Copy elements back from temp to arr
    //     int m = start;
    //     for (int n = start; n <= end; n++) {
    //         arr[n] = temp[m++];
    //     }
    //     return count;
    // }
    
    
    long long merge(long long arr[], long long temp[], int left, int mid, int right)
    {
        int i, j, k;
        long long inv_count = 0;
     
        i = left;
        j = mid;
        k = left;
        while ((i <= mid - 1) && (j <= right)) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
     
                // this is tricky -- see above
                // explanation/diagram for merge()
                inv_count = inv_count + (mid - i);
            }
        }
     
        // Copy the remaining elements of left subarray
        // (if there are any) to temp
        while (i <= mid - 1)
            temp[k++] = arr[i++];
     
        // Copy the remaining elements of right subarray
        // (if there are any) to temp
        while (j <= right)
            temp[k++] = arr[j++];
     
        // Copy back the merged elements to original array
        for (i = left; i <= right; i++)
            arr[i] = temp[i];
     
        return inv_count;
    }
    
    
    // long long mergeSort(long long arr[], long long temp[], int start, int end){
    //     if(start>=end){
    //         return 0;
    //     }
    //     long long count = 0;
    //     int mid = (start+end)/2;
    //     count += mergeSort(arr,temp,start,mid);
    //     count += mergeSort(arr,temp,mid+1,end);
        
    //     count += merge(arr,temp,start,mid,end);
        
    //     return count;
    // }
    
    long long mergeSort(long long arr[], long long temp[], int left, int right)
    {
        int mid;
        long long inv_count = 0;
        if (right > left) {
            // Divide the array into two parts and
            // call _mergeSortAndCountInv()
            // for each of the parts
            mid = (right + left) / 2;
     
            // Inversion count will be sum of
            // inversions in left-part, right-part
            // and number of inversions in merging
            inv_count += mergeSort(arr, temp, left, mid);
            inv_count += mergeSort(arr, temp, mid + 1, right);
     
            // Merge the two parts
            inv_count += merge(arr, temp, left, mid + 1, right);
        }
        return inv_count;
    }
 
// This function merges two sorted arrays
// and returns inversi
    
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
