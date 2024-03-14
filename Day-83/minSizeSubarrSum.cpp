// Brute Force --> T.C. = O(n^2)
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, result = INT_MAX;

        for(int i = 0; i<nums.size(); i++){
            sum = 0;
            for(int j = i; j<nums.size(); j++){
                sum += nums[j];
                if(sum>=target){
                    result = min(result,j-i+1);
                    break;
                }
            }
        }

        if(result == INT_MAX)   return 0;
        return result;
    }
