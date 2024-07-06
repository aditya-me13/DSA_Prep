// Problem Link: https://leetcode.com/problems/pass-the-pillow/description/?envType=daily-question&envId=2024-07-06

class Solution {
public:
    int passThePillow(int n, int time) {
        int q = time / (n-1) ;
        int r = time % (n-1);

        if(q % 2) return n-r;
        return r+1;

    }
};