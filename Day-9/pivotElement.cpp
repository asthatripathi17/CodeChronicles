class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int tot_sum = accumulate(nums.begin(), nums.end(), 0);
        int p = 0;
        int lsum = 0, rsum = tot_sum - lsum - nums[p];

        while(p<nums.size()){
            if(p==nums.size()){
                return -1;
            }
            if(lsum!=rsum){
                lsum = lsum + nums[p];
                p++;
                if(p==nums.size()){
                return -1;
                }else{
                    rsum = rsum - nums[p];
                }
            }
            else{
                return p;
            }
        }
        return -1;
    }
};
