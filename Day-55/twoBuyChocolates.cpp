//Approach 1 - Brute Force
// Get 2 smallest values by finding every possible pair and then getting the minimium pair among all
// T.C = O(n^2)

//Approach 2 - Using Sorting
// Take first and second element
// T.C. = O(nlogn)

//Approach 3 - Using linear time complexity
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min_f, min_s;
        min_f = INT_MAX;
        min_s = INT_MAX;
        int i = 0;
        while(i<prices.size()){
            if(prices[i]<min_f){
                min_s = min_f; //to preserve the smallest value up until now
                min_f = prices[i];
            }
            else if(prices[i]<=min_s){
                min_s = prices[i];
            }
            i++;
        }
        int sum = money-(min_f+min_s);
        if(sum>=0)
            return sum;
        return money;
    }
};
