class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        
        int n = nums.size();

        // Brute Force
        // int globalInv = 0, localInv = 0;
        // Calculate the global and local inversions
        // for(int i = 0; i<n; i++){
        //     for(int j = i+1; j<n; j++){
        //         if(nums[i]>nums[j]){
        //             globalInv++;
        //             if(j == i+1){
        //                 localInv++;
        //             }
        //         }
        //     }
        // }
        // return globalInv == localInv;

        // Disproof that by finding a global inversion that can't be local inversion
        int maxi = -1;
        for(int i = 0; i<n-2; i++){
            maxi = max(maxi,nums[i]);
            if(maxi>nums[i+2]){
                return false;
            }
        }
        return true;
    }
};
