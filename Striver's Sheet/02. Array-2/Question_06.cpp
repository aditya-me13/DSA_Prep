#include <bits/stdc++.h> 

int merge(long long *arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr
    int count=0;
    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            count += (mid-left+1);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return count;
}

int mergeSort(long long *arr, int low, int high) {
    if (low >= high) return 0;

    int mid = (low + high) / 2 ;
    int nlow = mergeSort(arr, low, mid);  // left half
    int nhigh = mergeSort(arr, mid + 1, high); // right half
    return merge(arr, low, mid, high) + nlow + nhigh;  // merging sorted halves
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n-1);
}