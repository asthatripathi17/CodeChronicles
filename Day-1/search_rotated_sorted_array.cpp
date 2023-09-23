class Solution {
public:

    int pivotElement(vector<int> arr){

        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e-s)/2;
        while(s<=e){
            if(s == e)
                return s;
            else if(mid+1 <= e && arr[mid]>arr[mid+1])
                return mid;
            else if(mid-1>=s && arr[mid-1]>arr[mid])
                return mid-1;
            else if(arr[s]>arr[mid]){
                //go left
                e = mid-1;
            }
            else
                s = mid+1;
            mid = s + (e-s)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {

        int pivotInd = pivotElement(nums);
        int s = 0;
        int e = nums.size() - 1;
        if(target<=nums[pivotInd] && target>=nums[0]){
            e = pivotInd;
        }
        else{
            s = pivotInd + 1;
        }
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                e = mid-1;
            else
                s = mid+1;
        }
        return -1;
    }
};
