int longestConsecutive(vector<int>& nums) {
        
        // Uses O(nlogn) time complexity --> TODO: Get TC = O(n)
        if(nums.size()<=1){
            return nums.size();
        }

        sort(nums.begin(),nums.end());
        int count = 1, maxseq = 1;
        
        for(int i = 0; i<nums.size()-1; i++){

            if(nums[i]+1 == nums[i+1]){
                count++;
            }
            if(nums[i]+1 != nums[i+1] || nums.size()>=2 && i == nums.size()-2){
                if(nums[i] == nums[i+1]){
                    if(nums.size()>=2 && i == nums.size()-2){
                        maxseq = max(maxseq,count);
                    }
                    continue;
                }
                maxseq = max(maxseq,count);
                count = 1;
            }
        }

        return maxseq;
    }
