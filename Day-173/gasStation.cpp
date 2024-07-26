int checkSum(vector<int>& vec){
    int sum = 0;
    for(int v:vec){
        sum+=v;
    }
    return sum;
}
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    if(checkSum(gas)<checkSum(cost)){
        return -1;
    }
    int index = 0, total = 0;

    for(int i = 0; i<gas.size(); i++){
        total += gas[i]-cost[i];
        if(total<0){
            //total reset
            total = 0;
            index = i + 1;
        }
        
    }

    return index;
}
