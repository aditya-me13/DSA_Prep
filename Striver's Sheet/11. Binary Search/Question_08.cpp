class Solution {
public:
    
    bool is_possible(vector<int> &stalls, int gap, int k){
        int cows=1; int last = stalls[0];
        for(int val:stalls){
            if(val-last >= gap){
                cows++;
                last = val;
            }
            if(cows == k) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        
        while(high >= low){
            int mid = (high+low)>>1;
            
            if(is_possible(stalls, mid, k)) low = mid+1;
            else high = mid-1;
        }
        
        return high;
    }
};