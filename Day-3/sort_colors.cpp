//Three pointer approach; one for comparison and to check the condition for the loop and other two for swapping.
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int l,m,h;
        l = m = 0;
        h = nums.size() - 1;
        while(m<=h){
            if(nums[m]==0){
                swap(nums[m],nums[l]);
                m++;
                l++;
            }
            else if(nums[m]==1){
                m++;
            }
            else{
                swap(nums[m],nums[h]);
                h--;
            }
        }
    }
};


//Uses simple approach of counting and then changing values but doesn't use in place algorithm.
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int z,o,t;
        z=o=t=0;
        //counting the elements
        for(int i = 0; i<nums.size();i++){
            if(nums[i]==0){
                z++;
            }
            else if(nums[i]==1){
                o++;
            }
            else{
                t++;
            }
        }
        
        //reinserting them in a sorted order
        int k = 0;
        while(z!=0){
            nums[k]=0;
            z--;
            k++;
        }
        while(o--){
            nums[k]=1;
            k++;
        }
        while(t--){
            nums[k]=2;
            k++;
        }
    }
};
