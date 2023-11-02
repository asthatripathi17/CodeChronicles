class Solution {
public:
    string removeOccurrences(string s, string part) {
        int found = s.find(part); //finds the first occurrence 
        while(found!=-1){
            s.erase(found,part.length()); //erases from found index till length of part           
            found = s.find(part); //for the leftover string we do it all again
        }
        return s;
    }
};
