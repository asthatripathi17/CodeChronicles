int maxSubArray(vector<int>& nums) {
        
        // //Brute Force using 2 nested loops
        // int sum = INT_MIN;
        // for(int i = 0;i<nums.size();i++){
        //     int temp = 0;
        //     for(int j = i;j<nums.size();j++){
        //         temp += nums[j];
        //         if(temp>sum){
        //             sum = temp;
        //         }
        //     }
        // }
        // return sum;

        // Linear Approach by ignoring negative prefixes
        int sum = INT_MIN, prefix = 0;
        // int index_s = 0, index_e = 0; for printing
        for(int i = 0; i<nums.size(); i++){
            if(prefix < 0){
                prefix = 0; //ignoring negative prefixes
                //index_s = i;
            }
            prefix += nums[i];
            if(prefix>sum){
                sum = prefix;
                //index_e = i;
            } 
        }
        // cout<<index_s<<" "<<index_e;
        return sum;
        
    }

// DnC Approach
int maxSubArrayHelper(vector<int>& nums, int start, int end){

        if(start == end){
            return nums[start];
        }
        int mid = start + ((end-start) >> 1);
        int lsum = maxSubArrayHelper(nums,start,mid);
        int rsum = maxSubArrayHelper(nums,mid+1,end);

        // Calculating the cross border sum
        int leftBorderMaxSum = INT_MIN, rightBorderMaxSum = INT_MIN;
        int leftBorderSum = 0, rightBorderSum = 0;
        // Calculating leftBorderSum
        for(int i = mid; i>=0; i--){
            leftBorderSum += nums[i];
            if(leftBorderSum>leftBorderMaxSum){
                leftBorderMaxSum = leftBorderSum;
            }
        }
        // Calculating rightBorderSum
        for(int i = mid+1; i<=end; i++){
            rightBorderSum += nums[i];
            if(rightBorderSum>rightBorderMaxSum){
                rightBorderMaxSum = rightBorderSum;
            }
        }

        int crossMaxSum = leftBorderMaxSum + rightBorderMaxSum;
        return max(lsum,max(rsum,crossMaxSum));
    }
    int maxSubArray(vector<int>& nums) {
        
        return maxSubArrayHelper(nums,0,nums.size()-1);
    }
