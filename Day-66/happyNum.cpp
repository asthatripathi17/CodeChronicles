class Solution {
public:
    // Used 1 or 4 logic; Can also keep a track of sums to avoid loops by using hashmaps
    int digits(int num){
        int dig = 0;
        while(num>0){
            dig += (num%10)*(num%10);
            num = num/10;
        }
        return dig;
    }

    bool isHappy(int n) {
        int sum = n;
        
        while(sum!=1){
            sum = digits(sum);
            if(sum == 1)   return true;
            else if(sum == 4)   return false;
        }
        
        return true;
    }
};
