// Can't convert string into number as -
// first convert string to int dec number, then make a recursive func --> this approach gives Runtime Error

// Check lsb of string - if 1 then add 1 otherwise rightshift until string == "1"
void addOne(string& s, int index){
    if(index<0){
        s.insert(s.begin(),'1');
        return;
    }
    else if(s[index] == '0'){
        s[index] = '1';
        return;
    }
    else{
        s[index] = 0;
        addOne(s,index-1);
    }
}
int numSteps(string s) {
    int count = 0;
    while(s!="1"){
        if(s[s.length()-1] == '1'){
            // odd number
            // add one to it
            addOne(s,s.length()-1);
        }
        else{
            // to divide it by 2, just like right shift operator
            s.erase(s.end()-1);
        }
        count++;
    }
    return count;
}


