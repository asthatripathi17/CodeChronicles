// TC = O(n); uses unordered set and checks where is the starting point
int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> myset;
        for(int i = 0; i<nums.size(); i++){
            myset.insert(nums[i]);
        }
        int count = 0, longestCount = 0;

        for(auto num : myset){
            if(myset.find(num - 1) == myset.end()){ // myset.find() --> takes near const time
                int x = num; 
                count = 0;
                while(myset.find(x)!=myset.end()){
                    count++;
                    x++;
                }
                longestCount = max(longestCount,count);
            }
        }

        return longestCount;
    }


int longestConsecutive(vector<int>& nums) {
        
        // Uses O(nlogn) time complexity 
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
