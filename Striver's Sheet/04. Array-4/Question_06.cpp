class Solution {
private:

    bool isPossible(string s, int k){
        unordered_map<char, int> mp;
        int n = s.size();
    
        for(int i=0; i<k; i++){
            mp[s[i]]++;
        }

        if(mp.size() == k) return true;

        for(int i = 0; i < n-k; i++){    

            if(mp[s[i]] == 1) mp.erase(s[i]);
            else mp[s[i]]--;
            mp[s[i+k]]++;

            if(mp.size()==k) return true;
        }

        return false;
    }

public:
    int lengthOfLongestSubstring(string s) {
        int low = 1;
        int high = s.size();
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossible(s, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return high;
    }
};
