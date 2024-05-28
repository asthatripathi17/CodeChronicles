int specialArray(vector<int>& nums) {
    int limit = nums.size();
    int count = 0;
    for(int i = 1; i<=limit; i++){
        for(int j = 0; j<limit; j++){
            if(i<=nums[j]){
                count++;
            }
        }
        if(count == i)
            return count;
        count = 0;
    }

    return -1;
}
