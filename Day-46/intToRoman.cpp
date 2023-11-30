class Solution {
public:
    string intToRoman(int num) {
        //using map for having increasing order of keys
        map<int,string> store;
        
        store.insert({1, "I"});
        store.insert({4, "IV"});
        store.insert({5, "V"});
        store.insert({9, "IX"});
        store.insert({10, "X"});
        store.insert({40, "XL"});
        store.insert({50, "L"});
        store.insert({90, "XC"});
        store.insert({100, "C"});
        store.insert({400, "CD"});
        store.insert({500, "D"});
        store.insert({900, "CM"});
        store.insert({1000, "M"});

        string str;
        //rbegin() returns a reverse iterator pointing to the last element
        //rend() returns a reverse iterator pointing to one position before the first element.
        for (auto itr = store.rbegin(); itr != store.rend(); ++itr) {
            while(num>=itr->first){
                num = num - itr->first;
                str += itr->second;
            }
            if(num == 0) return str;
        }
        //using rbegin() to start from the highest value in the map
        //using rend() to iterate until the beginning of the map
        return str;
    }
};
