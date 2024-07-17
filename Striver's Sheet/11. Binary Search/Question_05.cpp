class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        // to ensure that the first array is smaller
        if(n1 > n2){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int low = 0;
        int high = n1;
        
        int min1, min2,max1, max2;
        int mid1, mid2;
        
        while(low <= high){
            mid1 = (low+high)/2;
            mid2 = (n1+n2+1)/2 - mid1;     // The most important line of the code
            
            min1 = (mid1 == 0)? INT_MIN : nums1[mid1 -1];
            min2 = (mid2 == 0)? INT_MIN : nums2[mid2 -1];            
            max1 = (mid1 == n1)? INT_MAX : nums1[mid1];
            max2 = (mid2 == n2)? INT_MAX : nums2[mid2];
            
            if(min1 <= max2 && min2 <= max1){
                if((n1+n2)%2){
                    return double(max(min1, min2));
                }
                else{
                    return (double(max(min1, min2)) + double(min(max1, max2))) / 2.0;
                }
            }
            else if(min1 > max2){
                high = mid1 - 1;
            }
            else{
                low = mid1 + 1;
            }
            
        }
        return 0; // Arrays were not sorted.
    }
};
