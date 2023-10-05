//Approach 1
//using Two pointer approach
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


//Approach 2
//Using Binary Search
class Solution {
public:

    bool binary_search(vector<int> nums, int a, int k){

        int s = a+1;
        int e = nums.size()-1;
        int target = nums[a]+k;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid]<target){
                //go right
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return false;
    }

    int findPairs(vector<int>& nums, int k) {
        if(k<0)
            return 0;
            
        sort(nums.begin(),nums.end());
        // to store unique elements in form of pairs
        set<pair<int,int>> pair;
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            if(binary_search(nums,i,k)){
                pair.insert({nums[i], nums[i]+k});
            }
            else{
                continue;
            }
        }
        return pair.size();
    }
};
