class Solution {
public:
    int totalMoney(int n) {
        int mon_money = 0, totalMoney = 0;
        for(int i = 0; i<n; i++){
            if(i%7 == 0){
                mon_money++;
            }
            totalMoney += mon_money + i%7;
        }
        return totalMoney;
    }
};
