// With Extra Space using prefix and suffix products
class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        // Prefix Product Calc
        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }
        // Suffix Product Calc
        for(int i = n-2; i>=0; i--){
            suffix[i] = suffix[i+1]*nums[i+1];
        }

        // Product Array
        for(int i = 0; i<n; i++){
            nums[i] = prefix[i]*suffix[i];
        }

        return nums;
    }
};


// Without extra space
vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> results(nums.size(),1);
        int suffix = 1;
        
        // Prefix Product Calc
        for(int i = 1; i<nums.size(); i++){
            results[i] = results[i-1]*nums[i-1];
        }
        // Suffix Product Calc + Results Calc
        for(int i = nums.size()-2; i>=0; i--){
            suffix = suffix*nums[i+1];
            results[i] = suffix*results[i];
        }

        return results;
    }
