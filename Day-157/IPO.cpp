int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    vector<pair<int,int>> store;
    for(int i = 0; i<profits.size(); i++){
        store.push_back({capital[i],profits[i]});
    }

    // sorting the store based on capital
    sort(store.begin(),store.end());

    // since we don't want to sort everytime we add an element
    priority_queue<int> pq;
    int i = 0;

    while(k>0){
        while(i<store.size() && store[i].first<=w){
            pq.push(store[i].second);
            i++;
        }
        if(k == 0 || pq.empty()){
            break;
        }
        w += pq.top();
        k--;
        pq.pop();
    }

    return w;
}
