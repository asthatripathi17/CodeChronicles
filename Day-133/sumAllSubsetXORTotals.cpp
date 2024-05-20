// Using Recursion - Inclusion & Exclusion Principle
void allSubset(vector<int>& nums, int index, int& sum, int temp){
    if(index>=nums.size()){
        sum += temp;
        return;
    }
    // exclude
    allSubset(nums,index+1,sum,temp);
    // include
    allSubset(nums,index+1,sum,temp^nums[index]);
}
int subsetXORSum(vector<int>& nums) {
    int sum = 0, index = 0, temp = 0;
    allSubset(nums,index,sum,temp);
    return sum;
}
