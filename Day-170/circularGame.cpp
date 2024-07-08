// Josephus's Problem
int findTheWinner(int n, int k) {
    // FIFO
    queue<int> store;
    for(int i = 1; i<=n; i++){
        store.push(i);
    }

    int cnt = 0;
    while(store.size()!=1){
        cnt++;
        if(cnt == k){
            cnt = 0;
            store.pop();
        }
        else{
            int temp = store.front();
            store.pop();
            store.push(temp);
        }
    }

    return store.front();
    
}
