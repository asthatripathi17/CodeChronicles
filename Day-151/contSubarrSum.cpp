bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> store; // remainder of sum by k, index
    store[0] = -1; // to ensure that if nums[0] divisible by k -> we can't return due to atleast condition
    int sum = 0;
    for(int i = 0; i<nums.size(); i++){
        sum += nums[i];
        int rem = sum%k;
        if(store.find(rem)!=store.end()){ // if found again an index with same rem then that means subarr sum b/w it is a multiple of k
            if(i-store[rem]>=2)
                return true; // not making any entry in else as we need atleast 2 
        }
        else{
            store[rem] = i;
        }
    }
    return false;
}
