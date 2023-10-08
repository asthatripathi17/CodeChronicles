//Using Binary Search to find int sqrt of x
class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 1 || x == 0 ){
            return x;
        }
        int s = 1, e = (x/2), ans = 0;
        while(s<=e){
            long mid = s + (e-s)/2;
            if(mid*mid <= x){
                if(mid*mid == x){
                    return mid;
                }
                else{
                    ans = (mid>ans)?mid:ans;
                    s = mid + 1;
                }
            }
            else if(mid*mid > x){
                e = mid - 1;
            }
        }
        return ans;
    }
};

//Using for loop with condition i*i<=n
class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 1 || x == 0 ){
            return x;
        }
        else{
            int max = 0;
            for(long i = 1; i*i<=x; i++){
                max = i;
            }

            return max;
        }
    }
};
