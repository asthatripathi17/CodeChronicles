class Solution {
public:
    void merge(vector<int>& nums, int s, int e){

        int len = e-s+1;
        //using gap method as we can't use any built in function
        int gap = (len/2) + (len%2);
        while(gap>0){
            int l = s;
            int r = l + gap;
            while(r<=e){
                if(nums[l]>nums[r]){
                    swap(nums[l],nums[r]);
                }
                l++;
                r++;
            }
            if(gap == 1)    break;
            gap = (gap/2) + (gap%2);
        }
    }

    void mergeSort(vector<int>& nums, int s, int e){
        if(s>=e){
            return;
        }
        int mid  = (s+e)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);

        merge(nums,s,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        mergeSort(nums,s,e);

        return nums;
    }
};
