class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        // to store unique elements in form of pairs
        int result = 0;
        int l = 0, h = nums.size()-1;
        while(l<h){
            int sum = nums[l]+nums[h];
            if(sum==k){
                result++;
                l++;
                h--;
            }
            else if(sum<k){
                l++;
            }
            else{
                h--;
            } 
        }
        return result;
    }
};
