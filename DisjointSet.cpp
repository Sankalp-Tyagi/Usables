//Disjoint Set : Union By Rank : 

class dset{
    int n;
    vector<int> rank;
    vector<int> parent;
    public :
    dset(int n)
    {
        rank.resize(n);
        parent.resize(n);
        this->n = n;
        makeSet();
    }
    void makeSet()
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            rank[i] = 0;
        }
    }
    int find(int x)
    {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void Union(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);
        if (xset == yset){
            return;
        }
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};
