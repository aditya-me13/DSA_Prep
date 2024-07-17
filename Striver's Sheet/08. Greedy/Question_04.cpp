#include <algorithm>
class Solution {
    public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // MOST IMP STEP
        sort(arr , arr+ n ,[](const auto &a , const auto &b){
            double x = static_cast<double>(a.value) / a.weight;
            double y = static_cast<double>(b.value) / b.weight;
            return  x > y;
        });
        
        double ans = 0.0; int i = 0;
        while(W > 0 && i < n){
            if(arr[i].weight <= W){
                W -= arr[i].weight;
                ans+= arr[i].value;
            }
            else{
                ans += (static_cast<double>(arr[i].value)/arr[i].weight)*W;
                W=0;
            }
            i++;
        }
        return ans;
    }
};
