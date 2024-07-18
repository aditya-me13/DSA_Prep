// Problem Link: https://www.naukri.com/code360/problems/gas-tank_699834?topList=top-google-coding-interview-questions&leftPanelTab=1&leftPanelTabValue=PROBLEM
// Courtesy: https://www.youtube.com/watch?v=lJwbPZGo05A


// Brute force solution
int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) 
{
    for(int i=0; i<n; i++){
        if(gas[i]<cost[i]) continue;
        int currGas=gas[i];
        int j=0;
        for(j=0; j<n-1; j++){
            if(currGas - cost[(i+j)%n] < 0) break;
            currGas -= cost[(i+j)%n];
            currGas += gas[(i+j+1)%n];
        }
        if(j==n-1) return i;
    }
    return -1;
}


// Optimal Solution
int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) {
    int totalGas = 0, totalCost = 0;
    int currentGas = 0, startIndex = 0;
    
    for (int i = 0; i < n; ++i) {
        totalGas += gas[i];
        totalCost += cost[i];
        currentGas += gas[i] - cost[i];
        
        if (currentGas < 0) {
            startIndex = i + 1;
            currentGas = 0;
        }
    }
    
    return (totalGas >= totalCost) ? startIndex : -1;
}
