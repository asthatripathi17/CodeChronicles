//Recursively adding the strings
class Solution {
public:
    string addRecurse(string &num1, int p1, string &num2, int p2, int &carry){
        //base case
        if(p1<0 && p2<0){
            if(carry!=0){
                return string(1,carry + '0');
            }
            return "";
        }

        //one case we need to solve
        int n1 = (p1>=0 ? num1[p1] : '0') - '0';
        int n2 = (p2>=0 ? num2[p2] : '0') - '0';
        int sum = n1 + n2 + carry;
        carry = sum/10;
        sum = sum%10;

        char temp = sum+'0';
        //RC
        string ans = addRecurse(num1, p1-1, num2, p2-1, carry) + temp;
        return ans;
    }
    string addStrings(string num1, string num2) {
        int carry = 0;
        string output = addRecurse(num1,num1.length()-1,num2,num2.length()-1,carry);
        return output;
        
    }
};


//Iterative Solution
class Solution {
public:
    string addStrings(string a, string b) {
        int sum = 0, carry = 0, i = 1;
        int m = a.length(), n = b.length();
        string str = "";
        while(i<=max(m,n)){
            if(i==m && i==n){
                sum = int(a[m-i])+ int(b[n-i])+carry - 96;
                carry = 0;
            }
            else if(i<=m && i<=n){
                sum = int(a[m-i])+ int(b[n-i])+carry - 96;
                carry = sum/10;
                sum = sum%10;
            }
            else if(i>m && i<n){
                sum = int(b[n-i])+carry - 48;
                carry = sum/10;
                sum = sum%10;
            }
            else if(i==n && i>m){
                sum = int(b[n-i])+carry - 48;
                carry = 0;
            }
            else if(i>n && i<m){
                sum = int(a[m-i])+carry - 48;
                carry = sum/10;
                sum = sum%10;
            }
            else if(i==m && i>n){
                sum = int(a[m-i])+carry - 48;
                carry = 0;
            }
            string st1 = to_string(int(sum));
            str = st1+str;
            i++;
        }

        while(str[0] =='0'){
            str.erase(str.begin());
            if(str==""){
                return "0";
            }
        }
        return str;
    }
};
