class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {

        int n = nums.size();
        if(n == 1){
            return 0;
        }
        else{
            int s = 0;
            int e = n - 1;  
            while(s<e){
                int mid = s + (e-s)/2;
                if(nums[mid]<nums[mid+1]){
                    if(mid+1 == n - 1){
                        return mid+1;
                    }
                    else{
                        s = mid + 1;
                    }
                }
                else if(nums[mid]>nums[mid+1]){
                    if(mid == 0||mid == n - 1){
                        return mid;
                    }
                    else if(nums[mid-1]<nums[mid]){
                        return mid;
                    }
                    else{
                        e = mid;
                    }
                }
            }
        }
        return -1;
    }
};
