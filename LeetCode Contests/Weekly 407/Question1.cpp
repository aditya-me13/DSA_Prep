// Problem Link : https://leetcode.com/contest/weekly-contest-407/problems/number-of-bit-changes-to-make-two-integers-equal/

class Solution {
public:
    int minChanges(int n, int k) {
        int count = 0;
        for(int i=0; i<32; i++){
            int bitn = n & (1<<i);
            int bitk = k & (1<<i);

            if(bitn==0 && bitk) return -1;
            else if(bitn && bitk == 0) count++;
        }
        return count;
    }
};