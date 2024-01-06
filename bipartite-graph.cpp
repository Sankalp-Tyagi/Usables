//CHECK GRAPH BIPARTITION : 
//1
bool isbpt(vector<vector<int>> &adj , int n , int s , vector<int> &c){
        queue<int> q;
        q.push(s);
        c[s] = 1;
        while(q.empty() == false){
            int curr = q.front();
            q.pop();
            for(int i : adj[curr]){
                if(c[i] == c[curr]){
                    return false;
                }
                if(c[i] == -1){
                    c[i] = 1 - c[curr];
                    q.push(i);
                }
            }
        }
        return true;
}
//2
bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size() == 1){
            return true;
        }
        int i;
        vector<int> c(graph.size() , -1);
        for(i = 0 ; i < graph.size() ; i++){
            if(c[i] == -1){
                if(isbpt(graph , graph.size() , i , c) == false){
                    return false;
                }
            }
        }
        return true;
}
