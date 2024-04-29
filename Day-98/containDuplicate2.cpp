    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Using Hashmap
        unordered_map<int,int> map;
        for(int i = 0; i<nums.size(); i++){
            if(map.find(nums[i]) == map.end()){
                // element not present
                map[nums[i]] = i;
            }
            else{
                // element present
                int temp = i - map[nums[i]];
                if(temp<=k){
                    return true;
                }
                else{
                    map[nums[i]] = i;
                }
            }
        }
        return false;
    }
