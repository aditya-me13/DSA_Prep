// Problem Link : https://leetcode.com/problems/sort-an-array/description/?envType=daily-question&envId=2024-07-25

class Solution {
private:
    void heapify(vector<int>&arr, int N, int i){
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if(l<N && arr[l]>arr[largest]){
            largest = l;
        }
        if(r<N && arr[r]>arr[largest]){
            largest = r;
        }

        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, N, largest);
        }
    }

    void heapsort(vector<int> &arr, int N){
        for(int i = N/2 -1; i>=0; i--){
            heapify(arr, N, i);
        }

        for(int i=N-1; i>=0; i--){
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        heapsort(nums, nums.size());
        return nums;
    }
};