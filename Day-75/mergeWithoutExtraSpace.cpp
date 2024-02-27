// Approach 1
#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int left = n - 1;
            int right = 0;
            while(arr1[left]>arr2[right] && left>=0 && right<m){
                swap(arr1[left],arr2[right]);
                left--;
                right++;
            }
            
            sort(arr1, arr1+n);
            sort(arr2, arr2+m);
        } 
};

// Approach 2 - Gap Method
class Solution{
    private:
        void swapifGreater(long long arr1[], long long arr2[], int l, int r){
            if(arr1[l]>arr2[r]){
                swap(arr1[l],arr2[r]);
            }
        }
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 

            int len = n+m;
            int gap = (len/2) + len%2;
            while(gap>0){
                int left = 0;
                int right = left + gap;
                while(right<len){
                    if(left<n && right>=n){
                        //in arr1 and arr2
                        swapifGreater(arr1,arr2,left,right-n);
                    }
                    else if(left>=n){
                        //both are inside arr2
                        swapifGreater(arr2,arr2,left-n,right-n);
                    }
                    else{
                        //both are inside arr1
                        swapifGreater(arr1,arr1,left,right);
                    }
                    left++;
                    right++;
                }
                if(gap == 1)     break;
                gap = (gap/2) + (gap%2); //taking the ceiling
            }
        } 
};

