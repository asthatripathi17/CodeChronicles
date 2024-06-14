// Using sorting
int minIncrementForUnique(vector<int>& nums) {
    int increm = 0;
    sort(nums.begin(),nums.end());
    for(int i = 1;i<nums.size();i++){
        if(nums[i]==nums[i-1]){
            nums[i]++;
            increm++;
        }
        else if(nums[i]<nums[i-1]){
            increm += (nums[i-1]-nums[i]+1);
            nums[i] = nums[i-1]+1;
        }
    }

    return increm;
}

// Using kind of counting sort
int minIncrementForUnique(vector<int>& nums) {
    int increm = 0;
    int siz = *max_element(nums.begin(),nums.end()) + nums.size();
    vector<int> storeFreq(siz,0);
    for(int i = 0; i<nums.size(); i++){
        storeFreq[nums[i]]++;
    }
    int carry = 0;
    for(int i = 0;i<storeFreq.size(); i++){
        storeFreq[i] += carry; 
        if(storeFreq[i]>1){
            carry = storeFreq[i]-1;
            increm += carry;
        }
        else{
            carry = 0;
        }
    }
    return increm;
}
