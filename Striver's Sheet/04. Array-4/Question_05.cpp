int Solution::solve(vector<int> &a, int B) {
    int n = a.size();
    vector<int> prefix_xor(n,0);
    prefix_xor[0] = a[0];
    
    for(int i=1;i<n;i++)
    {
        prefix_xor[i] = prefix_xor[i-1]^a[i];
    }
    
    unordered_map<int, int> mp;
    int count = 0;
    for(int i:prefix_xor)
    
    {
        int xor_needed = B^i;
        if(mp.find(xor_needed)!=mp.end())
        {
            count+=mp[xor_needed];
        }
        if(i==B)
        {
            count++;
        }
        mp[i]++;
    }
    return count;
}