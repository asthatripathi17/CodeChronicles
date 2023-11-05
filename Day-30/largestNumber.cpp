class Solution {
public:
//sorts the numbers based on the lexicographic order of their string representations
    static bool compFunc(int i, int j) {
        //sort function will automatically assign an element to both i and j
        string st1, st2;
        st1 = to_string(i);
        st2 = to_string(j);
        return st1+st2>st2+st1; //when sorting in descending order, condition i > j indicates that if i is greater than j, it should come before j in the sorted order
    }

    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), compFunc); //define how to sort the vector
        //Do not include the () for the compFunc as it must be passed as a function pointer or function object
        if(nums[0] == 0) return "0";
        for(int i = 0; i<nums.size(); i++){
            ans += to_string(nums[i]);
        }
        return ans;
    }
};
