class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m) return kthElement(arr2, arr1, m, n, k);
        int min1, min2, max1, max2, mid1, mid2;
        
        int low = max(0, k-m);
        int high = min(k, n);
        
        while(low <= high){
            mid1 = (low+high)>>1;
            mid2 = (k-mid1);
            
            min1 = mid1==0 ? INT_MIN : arr1[mid1-1];
            min2 = mid2==0 ? INT_MIN : arr2[mid2-1];
            max1 = mid1==n ? INT_MAX : arr1[mid1];
            max2 = mid2==m ? INT_MAX : arr2[mid2];
        
            if(min1 <= max2 && min2 <= max1) return max(min1, min2);
            if(min1 > max2) high = mid1 -1;
            else if(min2 > max1) low = mid1 + 1;
            
        }
        return -1;
    }
};