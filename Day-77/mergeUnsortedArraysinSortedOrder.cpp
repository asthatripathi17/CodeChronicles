void swapifGreater(int arr1[], int arr2[], int l, int r){
        if(arr1[l]>arr2[r]){
            swap(arr1[l],arr2[r]);
        }
    }
	public:
	void sortedMerge(int a[], int b[], int res[],int n, int m)
	{
	   // Your code goes here
	   sort(a,a+n);
	   sort(b,b+m);
	   
	   int gap = ((n+m)/2) + ((n+m)%2);
	   
	   while(gap>0){
	       
	       int l = 0;
	       int r = l+gap;
	       
	       while(r<(n+m)){
	           //if l and r inside a
	           if(r<n){ //l will always be behind r
	               swapifGreater(a,a,l,r);
	           }
	           
	           //if l and r inside b
	           else if(l>=n && r>=n){
	               swapifGreater(b,b,l-n,r-n);
	           }
	           //if l inside a and r inside b
	           else{
	               swapifGreater(a,b,l,r-n);
	           }
	           
	           l++;
	           r++;
	       }
	       
	       if(gap == 1){
	           break;
	       }
	       gap = (gap/2) + (gap%2);
	   }
	   
	   int k = 0;
	   
	   for(int i = 0;i<n;i++){
	       res[k] = a[i];
	       k++;
	   }
	   for(int i = 0;i<m;i++){
	       res[k] = b[i];
	       k++;
	   }
	}
