// Two Pointer Approach
bool judgeSquareSum(int c) {
    if(c == 1){
        return true;
    }
    int i = 0, j = sqrt(c);
    while(i<=j){
        long j_sq = j*j;
        long i_sq = i*i;
        if(i_sq + j_sq == c){
            return true;
        }
        else if(j_sq+i_sq>c){
            j--;
        }
        else{
            i++;
        }
    }

    return false;
}
