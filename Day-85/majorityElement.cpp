class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // Brute Force
        int count = 0, major_element = 0;
        for(int i = 0; i<nums.size(); i++){
            count = 0;
            for(int j = 0; j<nums.size(); j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
            if(count>nums.size()/2){
                return nums[i];
            }
        }

        return -1;

        // Better Approach using Hashmap
        unordered_map<int,int> frequency;
        for(int i = 0;i<nums.size(); i++){
            frequency[nums[i]]++;
            if(frequency[nums[i]] > nums.size()/2){
                return nums[i];
            }
        }
        return -1;


        // Optimal Approach using Moore's Majority Voting Algorithm
        int ele = 0, count = 0; // count's value tells whether ele is more than n/2 (value should be more than 0) or not   
        for(int i = 0; i<nums.size(); i++){
            if(count == 0){
                ele = nums[i];
            }
            if(nums[i] == ele){
                    count++;
            }
            else{
                count--;
            }
        }

        return ele;


    }
};
