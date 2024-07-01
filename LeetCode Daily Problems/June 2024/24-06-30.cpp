class Disjoint_Set{
public:
    vector<int> rank, parent, size;
public:
    Disjoint_Set(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int find_parent(int child){
        if(child == parent[child]) return child;
        parent[child] = find_parent(parent[child]);
        return parent[child];
    }

    void union_by_size(int u, int v){
        int pu = find_parent(u);
        int pv = find_parent(v);

        if(pu == pv) return;
        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }

    void union_by_rank(int u, int v){
        int pu = find_parent(u);
        int pv = find_parent(v);

        if(pu == pv) return;
        if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else if(rank[pv] > rank[pu]){
            parent[pu] = pv;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // DSU instance for Alice and Bob
        Disjoint_Set alice(n);
        Disjoint_Set bob(n);
        int m = edges.size();
        int count = 0;

        // process all the type 3 edges first
        for(int i=0; i<m; i++){
            bool flag = false;
            if(edges[i][0] == 3){
                if(alice.find_parent(edges[i][1]) != alice.find_parent(edges[i][2])){
                    alice.union_by_size(edges[i][1], edges[i][2]);
                }
                else{
                    flag = true;
                }

                if(bob.find_parent(edges[i][1]) != bob.find_parent(edges[i][2])){
                    bob.union_by_size(edges[i][1], edges[i][2]);
                }
                else{
                    if(flag == true){
                        count++;
                    }
                }
            }
        }

        for(int i=0; i<m; i++){
            if(edges[i][0] == 1){
                if(alice.find_parent(edges[i][1]) != alice.find_parent(edges[i][2])){
                    alice.union_by_size(edges[i][1], edges[i][2]);
                }
                else{
                    count++;
                }
            }

            else if(edges[i][0] == 2){
                if(bob.find_parent(edges[i][1]) != bob.find_parent(edges[i][2])){
                    bob.union_by_size(edges[i][1], edges[i][2]);
                }
                else{
                    count++;
                }
            }
        }

        
        for(int i=1; i<n; i++){
            if(alice.find_parent(i) != alice.find_parent(i+1)) return -1;
            if(bob.find_parent(i) != bob.find_parent(i+1)) return -1;
        }        

        return count;
    }
};