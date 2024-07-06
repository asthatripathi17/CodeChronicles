    int passThePillow(int n, int time) {
        time %= (n-1)*2;
        if(n>time)
            return 1 + time;
        return n - (time - n + 1);
    }
