class Solution {
public:
    string reverseWords(string s) {

        stack<string> collection;
        int i = 0;
        string temp = ""; // temporarily holds words
        char space = ' '; // to avoid the comparsion between lvalue and rvalue
        while(i<s.length()){
            if(s[i] != space){
                temp += s[i]; // taking in the letters without spaces to form word
            }
            if((i == s.length()-1 || s[i] == space ) && temp != ""){
                collection.push(temp);
                temp = "";
            }
            i++;
        }
        s = "";
        while(!collection.empty()){
            s += collection.top();
            collection.pop();
            if(!collection.empty()){
                s += " "; // to add proper spacing
            }
        }

        return s;
    }
};
