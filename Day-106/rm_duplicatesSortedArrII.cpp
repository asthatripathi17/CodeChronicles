// Using two pointers approach
int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()<3){
            return nums.size();
        }
        int index = 2;
        for(int i = 2;i<nums.size();i++){
            if(nums[index-2]!=nums[i]){
                nums[index++] = nums[i];
            }
        }

        return index;
    }
