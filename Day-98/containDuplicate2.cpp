    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Using Hashmap
        unordered_map<int,int> map;
        for(int i = 0; i<nums.size(); i++){
            if(map.find(nums[i]) != map.end()){
                // element present
                int temp = i - map[nums[i]];
                if(temp<=k)
                    return true;
            }
            map[nums[i]] = i;
        }
        
        return false;
    }
