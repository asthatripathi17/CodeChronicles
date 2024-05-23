class Solution {
public:
    int K;
    int count;
    void helperFunc(vector<int>& nums, int index, unordered_map<int,int>& store){
        if(index>=nums.size()){
            count++;
            return;
        }

        // exclude
        helperFunc(nums,index+1,store);

        // include
        if(!store[nums[index] - K] && !store[nums[index] + K]){ // checking for k
            store[nums[index]]++;
            helperFunc(nums,index+1,store);
            store[nums[index]]--; // backtrack
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        
        count = 0;
        K = k;
        unordered_map<int,int> store;
        helperFunc(nums,0,store);
        return count-1;
    }
};
