//TOPOLOGICAL SORT FOR CYCLE DETECTION : 

        vector<int> ind(numCourses);
        vector<vector<int>> v(numCourses);
        for(auto it : prerequisites){
            v[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }
        queue<int> q;
        int i , c = 0;
        for(i = 0 ; i < ind.size() ; i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }
        while(q.empty() == false){
            int u = q.front();
            q.pop();
            for(auto itr : v[u]){
                ind[itr]--;
                if(ind[itr] == 0){
                    q.push(itr);
                }
            }
            c++;
        }
        return c == numCourses;
