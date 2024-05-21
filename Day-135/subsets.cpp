// Using Recursion - Inclusion and Exclusion Principle
void helperFunc(vector<int>& nums,int index,vector<int> temp,vector<vector<int>>& output){
    if(index>=nums.size()){
        output.push_back(temp);
        return;
    }

    // exclude
    helperFunc(nums,index+1,temp,output);
    // include
    temp.push_back(nums[index]);
    helperFunc(nums,index+1,temp,output);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> output;
    helperFunc(nums,0,{},output);
    return output;
}
