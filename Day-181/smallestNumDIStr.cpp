bool conditionCheck(string &original, string &pattern) {
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] == 'I' && original[i] > original[i + 1]) return false;
        if (pattern[i] == 'D' && original[i] < original[i + 1]) return false;
    }
    return true;
}

bool permutationMaker(int index, string &original, string &pattern) {
    if (index == original.size()) {
        if (conditionCheck(original, pattern)) return true; // Found smallest valid permutation
        return false;
    }

    for (int i = index; i < original.size(); i++) {
        swap(original[index], original[i]);
        if (permutationMaker(index + 1, original, pattern)) 
            return true; // Early return
        swap(original[index], original[i]); // Backtrack
    }
    return false;
}

string smallestNumber(string pattern) {
    string original = "";
    for (int i = 1; i <= pattern.size() + 1; i++) {
        original += '0' + i;
    }

    permutationMaker(0, original, pattern); // First valid permutation found is the answer
    return original;
}
