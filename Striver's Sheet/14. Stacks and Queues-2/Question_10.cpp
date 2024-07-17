//User function template for C++

class Solution 
{
    private:
    
    bool isCeleb(int ans, vector<vector<int>>& M){
        int n = M.size();
        int zero_count = 0;
        
        for(int i = 0; i<n; i++){
            if(M[ans][i]==0) zero_count++;
        }
        
        if(zero_count != n) return false;
        
        for(int i = 0; i<n; i++){
            if(M[i][ans]==1) zero_count--;
        }
        
        if(zero_count != 1) return false;
        
        return true;
    }
    
    public:
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int small = 0;
        int big = 1;
        
        while(small < n && big <n){
            if(M[small][big]==1){
                small = big;
                big++;
            }
            else{
                big++;
            }
        }
        
        if(isCeleb(small, M)) return small;
        return -1;
    }
};