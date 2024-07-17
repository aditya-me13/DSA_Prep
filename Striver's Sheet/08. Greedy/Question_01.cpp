class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>> arr;
        
        for(int i=0; i<n; i++){
            arr.push_back({end[i], start[i]});
        }
        
        sort(arr.begin(), arr.end());
        int last = 0;
        int count = 0;
        
        for(vector<int> val:arr){
            if(val[1] > last){
                count++;
                last = val[0];
            }
        }
        return count;
    }
};