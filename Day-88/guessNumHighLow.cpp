int guessNumber(int n) {
    int start = 1, end = n;

    while(start<=end){
        int mid = start + (end-start)/2;
        if(guess(mid) == 0){
            return mid;
        }
        else if(guess(mid) == -1){
            // number>pick --> mid should move to left side
            end = mid-1;
        }
        else if(guess(mid) == 1){
            // number<pick --> mid should move to right side
            start = mid+1;
        }
    }

    return -1;
}
