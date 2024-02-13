//Recursive Solution
class Solution {
public:
    // Approach 1: More function calls
    // void recurseRemoval(string &s,string &part, int &index){
    //     //base case
    //     if(index+part.length() > s.length()){
    //         return;
    //     }
    //     if(s.substr(index,part.length()) == part){
    //         s.erase(index,part.length());
    //         index = 0;
    //     }
    //     else{
    //         index++;
    //     }
    //     recurseRemoval(s,part,index);
    // }
    // Approach 2: Using find()
    void recurseRemoval(string &s, string &part){
        
        int found = s.find(part); //finds the first occurrence
        //Base Case
        if(found == -1){
            return;
        } 
        else{
            s.erase(found,part.length()); //erases from found index till length of part           
        }
        recurseRemoval(s,part);
    }
    string removeOccurrences(string s, string part) {
        recurseRemoval(s,part);
        return s;
    }
};


//Iterative Solution
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
