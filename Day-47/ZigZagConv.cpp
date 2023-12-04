//under construction
class Solution {
public:
    string convert(string s, int numrows) {
        if(s.size() == 1){
            return s;
        }
        int size = 0, cols = 0; 
        while(size<s.size()){
            if(cols%(numrows-1)==0){
                size = size+numrows;
                cols++;
            }
            else{
                cols++;
                size++;
            }
        }
        vector<vector<char>> matrix(numrows, vector<char>(cols,'@'));
        int p = 0, i = 0, j = 0;
        for(auto a:matrix){
            for(auto b: a){
                cout<<b<<" ";
            }
            cout<<endl;
        }
        while(p<s.size()){
            if(i == 0){
                while(p<s.size() && i < numrows){
                    matrix[i][j] = s[p];
                    i++;
                    p++;
                }
                i--;
            }
            else if(i == numrows - 1){
                while(p<s.size() && i > 0){
                    j++;
                    matrix[i][j] = s[p];
                    i--;
                    p++;
                }
            }
            j++;
        }
        string ans;
        for(auto a:matrix){
            for(auto b: a){
                if(b!='@'){
                    ans.push_back(b);
                }
            }
        }
        return ans;
    }
};
