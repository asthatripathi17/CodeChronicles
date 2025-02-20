// Approach 1 - Using the unordered set and converting each no between 0 to 2^n - 1 to binary string to check whether it is present or not 
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


// Approach 2 - Using Cantor's Diagonalization method, where we construct a new binary string by flipping the i-th character of nums[i]
// Cantor's Diagonalization Idea - If there are n strings of length n, we can guarantee that our new string differs from each input string at least in one position (the diagonal position). This ensures the new string is not present in the input list.
string findDifferentBinaryString(vector<string>& nums) {

    int n = nums.size();
    string ans = "";

    for(int i = 0; i<n;i++){ 
        if(nums[i][i] == '0'){
            ans.push_back('1');
        }
        else{
            ans.push_back('0');
        }
    }

    return ans;
}
