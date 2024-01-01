class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dir;
        string dir_nm = "";

        for(int i = 0; i<path.size(); i++){

            if(path[i] != '/'){
                dir_nm += path[i];
            }
            if(i == path.size()-1 || path[i] == '/'){
                if(dir_nm != ""){
                    if(dir_nm == ".."){
                        if(!dir.empty())
                            dir.pop();
                    }
                    else if(dir_nm != "."){
                        dir.push(dir_nm);
                    }
                }
                dir_nm = "";
            }
        }
        
        if(dir.empty()) return "/";

        while(!dir.empty()){
            dir_nm = "/"+dir.top()+dir_nm;
            dir.pop();
        }
        return dir_nm;
    }
};
