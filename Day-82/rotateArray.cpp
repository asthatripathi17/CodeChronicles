// Using extra k size vector space

    void rotate(vector<int>& nums, int k) {
        
        if(nums.size() == k){
            return;
        }
        if(nums.size()<k){
            k = k%nums.size(); // for cases like - nums = [1,2] and k = 3 --> then we rotate only the remainder times because if k is equal to size then no rotations in vector
        }
        // when nums.size()>k 
        int j = nums.size() - 1;
        int i = j-k;
        vector<int> temp;
        for(int m = 0; m<k; m++){
            temp.push_back(nums[j-m]);
        }
        while(i>=0){
            swap(nums[i],nums[j]);
            i--; j--;
        }
        i = 0;
        while(k>0){
            nums[i++] = temp[--k];
        }
    }


// Using no extra space to rotate the vector

    void reverse(vector<int>& nums, int start, int end){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        
        if(nums.size() == k){
            return;
        }
        if(nums.size()<k){
            k = k%nums.size(); // for cases like - nums = [1,2] and k = 3 --> then we rotate only the remainder times because if k is equal to size then no changes in vector
        }
        // when nums.size()>k

        reverse(nums,0,nums.size()-1); // [1,2,3,4,5] --> [5,4,3,2,1] when k = 2
        reverse(nums,0,k-1);           // [5,4,3,2,1] --> [4,5,3,2,1]
        reverse(nums,k,nums.size()-1); // [4,5,3,2,1] --> [4,5,1,2,3]
    }
