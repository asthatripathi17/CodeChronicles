//Recursive Solution
class Solution {
public:

    void converterInt_Words(int num, string &output, map<int,string> &base_words){
        if(num == 0){
            return;
        }
        for (auto itr = base_words.rbegin(); itr != base_words.rend(); ++itr) {
            if(num>=itr->first){
                if(num>=100){
                    converterInt_Words(num/(itr->first),output,base_words);
                }
                num = num%itr->first;
                output += itr->second + " ";
                break;
            }
        }
        converterInt_Words(num,output,base_words);
    }  
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }

        map<int,string> base_words;
        base_words[1] = "One";
        base_words[2] = "Two";
        base_words[3] = "Three";
        base_words[4] = "Four";
        base_words[5] = "Five";
        base_words[6] = "Six";
        base_words[7] = "Seven";
        base_words[8] = "Eight";
        base_words[9] = "Nine";
        base_words[10] = "Ten";
        base_words[11] = "Eleven";
        base_words[12] = "Twelve";
        base_words[13] = "Thirteen";
        base_words[14] = "Fourteen";
        base_words[15] = "Fifteen";
        base_words[16] = "Sixteen";
        base_words[17] = "Seventeen";
        base_words[18] = "Eighteen";
        base_words[19] = "Nineteen";
        base_words[20] = "Twenty";
        base_words[30] = "Thirty";
        base_words[40] = "Forty";
        base_words[50] = "Fifty";
        base_words[60] = "Sixty";
        base_words[70] = "Seventy";
        base_words[80] = "Eighty";
        base_words[90] = "Ninety";
        base_words[100] = "Hundred";
        base_words[1000] = "Thousand";
        base_words[1000000] = "Million";
        base_words[1000000000] = "Billion";

        string output = "";
        converterInt_Words(num,output,base_words);
        output.erase(output.length()-1,1);
        
        return output;
    }
};
