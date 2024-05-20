class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool helper(int node, bool graph[101][101], int m, int n, vector<int> colors){
        if(node == n){
            return true;
        }
        
        for(int i = 1; i <= m; i++){
            if(isPosible(node, graph, i, n, colors)){
                colors[node] = i;
                if(helper(node+1, graph, m, n, colors)){
                    return true;
                }
                else{
                    colors[node] = 0;
                }
            }
        }
        return false;
    }
    
    bool isPosible(int node, bool graph[101][101], int color, int n, vector<int> & colors){
        for(int i = 0; i<n; i++){
            if(i != node && graph[i][node] == true && colors[i] == color){
                return false;
                
            }
        }
        return true;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> colors(n, 0);
        colors[0] = 1;
        return helper(1, graph, m, n, colors);
    }
};
