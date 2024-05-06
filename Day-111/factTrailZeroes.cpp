// Reference -  https://www.purplemath.com/modules/factzero.htm
int trailingZeroes(int n) {
        int five = 5;
        int divison = n/five;
        int result = 0;
        while(divison>=1){
            result += divison;
            five *= 5;
            divison = n/five;
        }

        return result;
    }
