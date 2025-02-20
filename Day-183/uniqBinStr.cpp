string int2Bin(int num, int n){
    string binIndex = "";
    while(num>0){
        binIndex.push_back(num%2 + '0');
        num = num/2;
    }
    //padding zeroes
    while(binIndex.length()<n){
        binIndex.push_back('0');
    }
    reverse(binIndex.begin(),binIndex.end());
    return binIndex;
}

string findDifferentBinaryString(vector<string>& nums) {

    unordered_set<string> checker(nums.begin(),nums.end()); // O(1) for lookup
    int n = nums[0].size();

    for(int i = 0; i<(1<<n);i++){ // 1<<n = 2^n
        string temp = int2Bin(i,n); // converting each index into binary string with padding
        if(checker.find(temp) == checker.end()) // not present in the set
            return temp;
    }

    return "";
}
