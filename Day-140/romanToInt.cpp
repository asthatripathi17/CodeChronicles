int romanToInt(string s) {
    map<string,int> store{
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000}
    };

    int output = 0;
    int index = 0;

    while(index<s.size()){
        if(index+1<s.size() && store.find(s.substr(index,2)) != store.end()){
            output += store[s.substr(index,2)];
            index = index+2;
        }
        else{
            output += store[s.substr(index,1)];
            index++;
        }
    }

    return output; 
}
