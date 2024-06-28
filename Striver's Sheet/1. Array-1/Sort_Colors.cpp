class Solution {
public:
    void sortColors(vector<int>& A) {
        int n0=0, n1=0, n2=0;
        int n = A.size();
        for (int i = 0; i < n; i ++){
            switch(A[i]){
                case 0: 
                    n0 ++;
                case 1: 
                    n1 ++;
                case 2: 
                    n2 ++; 
            }
        }
        for (int i = 0; i<n0; i ++){A[i] = 0;}
        for (int i = n0; i<n1; i ++){A[i] = 1;}
        for (int i = n1; i<n2; i ++){A[i] = 2;}
    }
};
