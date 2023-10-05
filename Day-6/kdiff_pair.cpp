class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        if(k<0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        // to store unique elements in form of pairs
        set<pair<int,int>> pair;
        int n = nums.size();
        int i = 0, j = 1;

        while(j<n && i<n){
            
            int diff = abs(nums[i]-nums[j]);
            if(i==j){
                j++;
                continue;
            }
            if(diff == k){
                pair.insert({nums[i],nums[j]});
                i++;
                j++;
            }
            else if(diff > k){
                i++;
            }
            else{
                j++;
            }
        }
        return pair.size();
    }
};
