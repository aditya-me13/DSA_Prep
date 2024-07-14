// Problem Link: https://leetcode.com/problems/minimum-cost-for-cutting-cake-ii/

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hC, vector<int>& vC) {
        sort(hC.begin(), hC.end());
        sort(vC.begin(), vC.end());
        int hCutE = 0; // horizontal cuts encountered in path
        int vCutE = 0; // vertical cuts encountered in path

        int hM = m-2; // index of maximum value of Hcut
        int vM = n-2; // index of maximum value of Vcut

        long long int ans=0;

        while(hM >= 0 && vM >= 0){
            // cut horizontally
            if(hC[hM] > vC[vM]){
                ans += hC[hM] * (1+vCutE);
                hCutE++;
                hM--;
            }
            // cur vertically
            else{
                ans += vC[vM] * (hCutE+1);
                vCutE++;
                vM--;
            }
        }
        
        while(hM >= 0){
            // cut horizontally for the rest if any
            ans += hC[hM]*(vCutE+1);
            hCutE++;
            hM--;
        }

        while(vM >= 0){
            // cut vertically for the rest if any
            ans += vC[vM] * (hCutE+1);
            vCutE++;
            vM--;
        }

        return ans;
    }
};