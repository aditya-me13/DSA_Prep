class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {   
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        int mini = 1;
        int curr = 1;
        int a = 1;
        int d = 0;
        
        while(a<n && d<n){
            if(arr[a] <= dep[d]){
                curr++;
                a++;
            }
            else{
                curr--;
                d++;
            }
            mini = max(mini, curr);
        }
        return mini;
    }
};