class Solution {
public:
    void merge(vector<int> & nums, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid+1;
        while(left <= mid && right <= high){
            if((long)nums[left] < (long)nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = 0; i<high-low+1; i++){
            nums[low+i] = temp[i];
        }
    }

    int count_merge(vector<int> &nums, int low, int high, int count){
        
        if(low >= high){
            return count;
        }
        int cur = count;
        int mid = (low + high)/2;
        count += count_merge(nums, low, mid, cur);
        count += count_merge(nums, mid+1, high, cur);

        int right = mid+1;
        for(int left = low; left <= mid; left++){
            while(right <= high && nums[left] > 2*(long long)nums[right]){
                right++;
            }
            count = count + right - (mid + 1);
        }
        
        merge(nums, low, mid, high);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        // int count;
        return count_merge(nums, 0, nums.size() -1, 0);
    }
};
