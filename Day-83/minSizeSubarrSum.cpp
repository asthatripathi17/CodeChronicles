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


// Using a sliding window approach
    int minSubArrayLen(int target, vector<int>& nums) {

        int size = INT_MAX, L = 0, R = 0, sum = nums[R];
        while(R<nums.size()){
            if(sum<target){
                R++;
                if(R<nums.size())
                    sum += nums[R];
            }
            else if(sum>=target && R<nums.size()){
                size = min(size,R-L+1);
                sum -= nums[L];
                L++; // we got a new index to check for least window size which satisfies the condition
            }
        }

        return size == INT_MAX?0:size;
    }
