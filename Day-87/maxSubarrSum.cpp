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
