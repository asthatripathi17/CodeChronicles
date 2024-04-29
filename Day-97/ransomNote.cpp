    bool canConstruct(string ransomNote, string magazine) {
        
        if(magazine.length()<ransomNote.length()){
            return false;
        }

        unordered_map<char,int> mpp1,mpp2; //1 for ransomNote, 2 for magazine
        for(int i = 0; i<ransomNote.length(); i++){
            mpp1[ransomNote[i]]++;
        }
        for(int i = 0; i<magazine.length(); i++){
            mpp2[magazine[i]]++;
        }

        for(auto ch:mpp1){
            if(mpp2.find(ch.first) == mpp2.end()){
                return false;
            }
            else{
                if((mpp2.find(ch.first))->second < ch.second){
                    return false;
                }
            }
        }

        return true;
    }
