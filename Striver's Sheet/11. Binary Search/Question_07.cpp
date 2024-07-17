#include<bits/stdc++.h>

bool helper(vector<int>&books, int ans, int students){
    int std = 1;
    int pages = 0;

    for(int i = 0; i<books.size(); i++){
        if(books[i] > ans) return false;
        if(pages + books[i] > ans){
            std++;
            pages = books[i];
        }
        else{
            pages += books[i];
        }
    }
    return (std <= students);
}
    
int Solution::books(vector<int> &A, int B) {
    if(B >A.size()) return -1;
    int low = *max_element(A.begin(), A.end());
    int high = accumulate(A.begin(), A.end(), 0);
    int mid;
    
    while(low <= high){
        mid = (low + high)/2;
        
        if(helper(A, mid, B)){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
