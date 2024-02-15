// Recursive Solution
// Time Efficient
class Solution {
public:
    void maxProfitRecurse(vector<int> &prices, int &min_price, int &max_profit, int index){
        if(index >= prices.size()){
            return;
        }
        min_price = min(min_price,prices[index]);
        if(max_profit<prices[index]-min_price){
            max_profit=prices[index]-min_price;
        }
        maxProfitRecurse(prices,min_price,max_profit,index+1);
    }
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX, max_profit = 0, index = 0;
        maxProfitRecurse(prices, min_price, max_profit, index);

        return max_profit;
    }
};

// Iterative Solution
// Memory Efficient
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int prof = 0;
        int mini = INT_MAX;
        for(int i = 0; i<prices.size();i++){
                mini = min(mini, prices[i]);
                if(prof<prices[i] - mini){
                    prof = prices[i] - mini;
                }
            }
        return prof;
    }
};
