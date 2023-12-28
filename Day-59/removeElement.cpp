class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int begin = 0, end = nums.size()-1;
        int result = 0;
        while(begin<=end){
            if(nums[begin] == val && nums[end]!=val){
                swap(nums[begin],nums[end]);
                begin++;
                end--;
                result++;
            }
            else if(nums[end] == val && nums[begin]!=val){
                end--;
                begin++;
                result++;
            }
            else if(nums[begin] == val && nums[end] == val){
                end--;
                result++;
            }
            else if(nums[begin]!=val && nums[end]!=val){
                begin++;
            }
        }
        return nums.size()-result;
    }
};
