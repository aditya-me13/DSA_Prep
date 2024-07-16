class Solution {
public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<int,int> mp;
        
        // to generalize for any target k
        int k = 0;
        int PreSum = 0;
        int Maxi = 0;
        
        for(int i=0; i<n; i++){
            PreSum += arr[i];
            
            if(PreSum == k){
                Maxi = max(Maxi, i+1);
            }
            else{
                int to_find = PreSum - k;
                if(mp.find(to_find)==mp.end()){
                    mp[to_find] = i;
                }
                else{
                    Maxi = max(Maxi,i-mp[to_find]);
                }
            }
        }
        return Maxi;
    }
};