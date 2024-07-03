/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/


class Solution 
{
    public:
    #include <stdio.h> 
    #include <stdlib.h> 
    #include <string.h> 

    
    static bool compareJobs(const Job &a, const Job &b) {
        return a.profit > b.profit; // Sort in descending order of profit
    }
        
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) {
        
        if(n == 0){
            return {0, 0};
        }
        
        int numJob = sizeof(arr) / sizeof(arr[0]); 
        // Sorting using qsort 
        std::sort(arr, arr + n, [](const Job &a, const Job &b) {
            return a.profit > b.profit; // Sort in descending order of profit
        });
        
        vector<int> ans(2, 0);
        
        int m = 0;
        for(int i = 0; i < n; i++){
            m = max(m, arr[i].dead);
        }
        
        vector<bool> marr(m, false);
        
        for(int i = 0; i < n; i++){
            if(marr[arr[i].dead -1] == false){
                marr[arr[i].dead -1] = true;
                ans[0] ++;
                ans[1] += arr[i].profit;
            }
            else{
                for(int j = arr[i].dead - 1; j >= 0; j--){
                    if(marr[j] == false){
                        marr[j] = true;
                        ans[0] ++;
                        ans[1] += arr[i].profit;
                        break;
                    }
                }
            }
        }
        
        return ans;    
    
    
    } 
};