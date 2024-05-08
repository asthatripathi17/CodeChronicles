class Solution {
public:
    int lsb(int num){
        return num&1;
    }
    int minFlips(int a, int b, int c) {
        int c_dash = a | b;
        int count = 0;

        vector<vector<int>> store(2,vector<int>(2,1));
        store[1][1] = 2;

        while(c_dash != 0 || c != 0){
            if(lsb(c_dash)!=lsb(c)){
                // then only we need to make changes
                count+=store[lsb(a)][lsb(b)];
            }
            c_dash = c_dash>>1;
            c = c>>1;
            a = a>>1;
            b = b>>1;
        }
        return count;

    }
};
