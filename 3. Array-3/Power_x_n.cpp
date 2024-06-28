class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        if(n < 0){x = 1/x;}
        double ans=1;
        // if(n > 0){
            while( n != 0){
                if(n%2){
                    ans*=x;
                    if(n>0) n--;
                    else n++;
                }
                x = x*x;
                n = n/2;
            }
            return ans;
    }
};
