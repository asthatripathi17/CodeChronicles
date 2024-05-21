bool valid(int i, int j,int m, int n){
    if(i>=0 && i<m && j>=0 && j<n){
        return true;
    }
    return false;
}

bool wordChecker(vector<vector<char>>& board, string& word, int index, int i, int j) {
    if(index == word.size()) {
        return true;
    }
    
    int m = board.size();
    int n = board[0].size();
    
    if(!valid(i, j, m, n) || board[i][j] != word[index]) {
        return false;
    }
    
    char temp = board[i][j];
    board[i][j] = '#'; // mark as visited
    
    // Check all four possible directions
    bool found = wordChecker(board, word, index + 1, i - 1, j) || // up
                 wordChecker(board, word, index + 1, i + 1, j) || // down
                 wordChecker(board, word, index + 1, i, j - 1) || // left
                 wordChecker(board, word, index + 1, i, j + 1);   // right
    
    board[i][j] = temp; // unmark the cell (backtracking)
    
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[0].size(); j++){
            if(word[0] == board[i][j] && wordChecker(board,word,0,i,j)){
                return true;
            }
        }
    }

    return false; // as in the end if no start letter gives us full word
}
