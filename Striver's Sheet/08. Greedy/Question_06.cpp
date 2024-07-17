class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0 || g.size()==0) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int b = 0;
        int n = s.size();
        int count = 0;

        for(int i=0; i<g.size(); i++){
            if(g[i] <= s[b]){
                count++;
            } 
            else {
                i--;
            }

            b++;
            if(b==n) break;
            
        }
        return count;
    }
};