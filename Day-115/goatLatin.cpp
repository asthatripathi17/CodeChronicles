bool isVowel(char ch){
    if(ch == 'a' || ch == 'i' || ch == 'e'|| ch == 'o'|| ch == 'u'|| ch == 'A'||ch == 'E'||ch == 'I'||ch == 'O'||ch == 'U'){
        return true;
    }
    return false;
}

string toGoatLatin(string sentence) {
    
    int i = 0, word = 1;
    while(i<sentence.length()){

        if(i == 0 || (i>0 && sentence[i-1] == ' ')){
            string suffix = "ma";
            if(!isVowel(sentence[i])){
                suffix = sentence[i] + suffix;
                sentence.erase(sentence.begin()+i);
            }

            suffix += string(word,'a');
            word++;
            
            while(sentence[i] != ' ' && i != sentence.length()){
                i++;
            }
            sentence.insert(i, suffix);
            i = i + suffix.length();
        }
        else{
            i++;
        }
    }

    return sentence;
}
