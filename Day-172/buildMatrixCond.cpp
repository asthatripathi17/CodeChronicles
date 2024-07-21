class Solution {
public:
    void dfs(int u, vector<int>& visited, unordered_map<int, vector<int>>& adj, stack<int>& st, bool& cycle){
        visited[u] = 1;
        for(int &v : adj[u]){
            if(visited[v] == 0){
                dfs(v, visited, adj, st, cycle);
            }else if(visited[v] == 1){
                // cycle is there
                cycle = true;
                return;
            }
        }
        visited[u] = 2; // neigh also visited
        st.push(u);
    }

    vector<int> topSort(vector<vector<int>>& edges, int& k){
        unordered_map<int, vector<int>> adj;
        for(vector<int>& edge: edges){
            int u = edge[0];
            int v = edge[1];
            // u--->v
            adj[u].push_back(v);
        }

        // DFS
        vector<int> visited(k+1,false); // as k = 1,2,....
        stack<int> st;
        vector<int> order; 
        bool cycle = false;

        for(int i = 1; i<=k; i++){
            if(visited[i] == 0){
                // DFS
                dfs(i, visited, adj, st, cycle);
                if(cycle == true){
                    return {};
                }
            }
        }

        while(!st.empty()){
            order.push_back(st.top());
            st.pop();
        }

        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<int> top_row = topSort(rowConditions, k);
        vector<int> top_col = topSort(colConditions, k);

        if(top_row.empty() || top_col.empty()){
            // not a DAG
            return {};
        }

        vector<vector<int>> matrix(k,vector<int>(k,0));

        unordered_map<int,pair<int,int>> indice;
        for(int i = 0; i<k; i++){
            if(indice.find(top_row[i]) == indice.end()){
                indice[top_row[i]] = {i,0};
            }
            else{
                indice[top_row[i]].first = i;
            }
            if(indice.find(top_col[i]) == indice.end()){
                indice[top_col[i]] = {0,i};
            }
            else{
                indice[top_col[i]].second = i;
            }
        }

        for(auto i:indice){
            matrix[i.second.first][i.second.second] = i.first;
        }
        
        return matrix;
    }
};
