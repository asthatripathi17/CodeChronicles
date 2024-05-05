int compareFunc(int n1, int n2){
        if(n1<n2)
            return -1;
        else if(n1>n2)
            return 1;
        return 0;
    }

    int compareVersion(string version1, string version2) {
        
        vector<int> v1,v2;
        int i1 = 0, i2 = 0;
        string temp1,temp2;

        while(i1<version1.length() || i2<version2.length()){
            
            if(i1<version1.length()){
                if(version1[i1] == '.' || i1 == version1.length()-1){
                    if(i1 == version1.length()-1){
                        temp1 += version1[i1];
                    }
                    v1.push_back(stoi(temp1));
                    if(i2==version2.length() && v1.size()>v2.size()){
                        v2.push_back(0);
                    }
                    temp1 = "";
                }
                else{
                    temp1 += version1[i1];
                }
                i1++;
            }
            
            if(i2<version2.length()){
                if(version2[i2] == '.' || i2 == version2.length()-1){
                    if(i2 == version2.length()-1){
                        temp2 += version2[i2];
                    }
                    v2.push_back(stoi(temp2));
                    if(i1==version1.length() && v2.size()>v1.size()){
                        v1.push_back(0);
                    }
                    temp2 = "";
                }
                else{
                    temp2 += version2[i2];
                }
                i2++;
            }
        }

        i1 = 0;
        i2 = 0;
        while(i1<v1.size()){
            int res = compareFunc(v1[i1],v2[i2]);
            if(res!=0){
                return res;
            }
            i1++;
            i2++;
        }
        return 0;
    }
