class Solution {
public:
    int clumsy(int n) {
        int i = 0, ans = 0;
        
        stack<int> calc;
        calc.push(n);
        
        while(n>1){
            if(i%4 == 0){
                int betans = calc.top()*--n;
                calc.pop();
                calc.push(betans);
            }
            else if(i%4 == 1){
                if(n-1>0 && !calc.empty()){
                    int betans = calc.top()/(--n);
                    calc.pop();
                    calc.push(betans);
                }
            }
            else if(i%4 == 2){
                calc.push(--n);
            }
            else{
                calc.push(--n*(-1));
            }
            i++;
        }

        while(!calc.empty()){
            ans += calc.top();
            calc.pop();
        }
        return ans;
    }
};
