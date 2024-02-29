void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        int len1 = m-l+1;
        int len2 = r-m;
        
        int* larr = new int[len1];
        int* rarr = new int[len2];
        
        //Copying values of left and right subarrays in new arrays
        int k = l;
        for(int i = 0; i<len1; i++){
            larr[i] = arr[k];
            k++;
        }
        for(int i = 0; i<len2; i++){
            rarr[i] = arr[k];
            k++;
        }
        
        //merging two arrays in the array
        k = l;
        int lindex = 0, rindex = 0;
        while(lindex<len1 && rindex<len2){
            if(larr[lindex]<rarr[rindex]){
                arr[k++] = larr[lindex++]; 
            }
            else{
                arr[k++] = rarr[rindex++];
            }
        }
        //if any subarray is left
        while(lindex<len1){
            arr[k++] = larr[lindex++];
        }
        while(rindex<len2){
            arr[k++] = rarr[rindex++];
        }
        
        delete larr;
        delete rarr;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r){ //invalid or the array only has one element --> no need to sort anymore
            return;
        }
        
        int mid = (l+r)/2;
        
        // sort left subarray
        mergeSort(arr,l,mid);
        // sort right subarray
        mergeSort(arr,mid+1,r);
        
        // merge the sorted subarrays
        merge(arr,l,mid,r);
    }
