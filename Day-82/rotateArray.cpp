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
