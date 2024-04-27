bool checkerOp(string st){
        if(st == "+" || st == "-" || st == "*" || st == "/")
            return true;
        return false;
    }
    
    int operation(string op, int num1, int num2){
        if(op == "+"){
            num1 += num2;
        }
        else if(op == "-"){
            num1 -= num2;
        }
        else if(op == "*"){
            num1 *= num2;
        }
        else if(op == "/"){
            num1 /= num2;
        }
        return num1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> calc;
        int i = 0;
        while(i<tokens.size()){
            
            if(!checkerOp(tokens[i])){
                if(i<tokens.size()-1 && checkerOp(tokens[i+1])){
                    int ans = calc.top();
                    calc.pop();
                    int temp = stoi(tokens[i]);
                    ans = operation(tokens[i+1],ans,temp);
                    calc.push(ans);
                    i = i+2;
                }
                else{
                    calc.push(stoi(tokens[i]));
                    i++;
                }
            }
            else{
                int num1 = calc.top();
                calc.pop();
                int ans = operation(tokens[i],calc.top(),num1);
                calc.pop();
                calc.push(ans);
                i++;
            }
        }
        return calc.top();
    }
