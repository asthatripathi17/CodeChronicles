class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //using monotonic stack - decreasing order
        stack<int> decSt;
        decSt.push(0);

        for(int i = 1; i<temperatures.size(); i++){
            while(!decSt.empty() && temperatures[decSt.top()]<temperatures[i]){
                //when opposite order
                temperatures[decSt.top()] = i - decSt.top();
                decSt.pop();
            }
            if(decSt.empty()|| temperatures[decSt.top()]>=temperatures[i]){
                decSt.push(i);
            }
        }
      
        while(!decSt.empty()){
            temperatures[decSt.top()] = 0;
            decSt.pop();
        }
        return temperatures;
    }
};
