class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int recent_ele = 0, finder = 1;
        while(finder<nums.size()){
            if(nums[recent_ele] == nums[finder]){
                finder++;
            }
            else if(nums[recent_ele] != nums[finder]){
                if(recent_ele+1 != finder){
                    swap(nums[recent_ele+1],nums[finder]);
                }
                recent_ele++;
                finder++;
            }
        }
        return recent_ele+1;
    }
};
