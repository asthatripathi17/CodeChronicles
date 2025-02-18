bool conditionCheck(string &original, string &pattern){

    for(int i = 0; i<pattern.size(); i++){
        if(pattern[i] == 'I' && original[i]>original[i+1]){
            return false;   
        }
        else if(pattern[i] == 'D' && original[i]<original[i+1]){
            return false;
        }
    }
    return true;
}

void permutationMaker(int index, string &original, string &pattern, string &smallest){

    if(index == original.size()){
        if(conditionCheck(original,pattern)){
            if (smallest.empty() || original < smallest) {
                smallest = original; // Update the smallest valid permutation
            }
        }
        return;
    }

    for (int i = index; i < original.size(); i++) {
        swap(original[index], original[i]);
        permutationMaker(index + 1, original, pattern, smallest);
        swap(original[index], original[i]);
    }

}

string smallestNumber(string pattern) {
    string original = "";
    for(int i = 1; i<=pattern.size()+1; i++){
        original += '0'+i;
    }

    string smallest = "";
    permutationMaker(0,original,pattern,smallest);

    return smallest;
}
