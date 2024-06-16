int minPatches(vector<int>& nums, int n) {
    long maxReach = 0;
    int patch = 0, i = 0;
    while(maxReach<n){
        if(i<nums.size() && nums[i]<=maxReach+1){
            // we don't need to patch anything
            maxReach+=nums[i];
            i++;
        }
        else{
            // we need to patch
            patch++;
            maxReach += maxReach+1;
        }
    }

    return patch;
}
