class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size() + nums2.size();
        vector<int> nums3(n);
        float med = 0;
        int p = 0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),nums3.begin());

        if(n%2!=0){
            p = (n+1)/2;
            med = (nums3[p-1]);
        }
        else if(n%2==0){
            p = n/2;
            med = (nums3[p-1]+nums3[p])/2.0;
        }
        
        return med;

    }
};
