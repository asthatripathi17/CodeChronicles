vector<vector<int>> threeSum(vector<int>& nums) {

    sort(nums.begin(),nums.end());
    vector<vector<int>> output;
    for(int i = 0; i<nums.size()-2; i++){
        
        // Skip duplicates for i
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        
        int j = i+1;
        int k = nums.size()-1;

        while(j<k){
            int tSum = nums[k]+nums[j];
            if(tSum+nums[i]<0){
                j++;
            }
            else if(tSum+nums[i]>0){
                k--;
            }
            else{
                // Triplet is found
                output.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;

                // To avoid the duplicate triplets
                while(j<k && nums[j] == nums[j-1]){
                    j++;
                }
                while(j<k && nums[k] == nums[k+1]){
                    k--;
                }
            }
        }
    }

    return output;

}
