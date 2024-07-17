#define PII pair<int, pair<int, int>>

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    vector<int> ans(C);
    
	// Sorted in Descending order
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
	// Max Heap
    priority_queue<PII> q;
	
	// Pushed all elements of A wrt the largest element of B
    for(int i = 0; i < n; i++)
        q.push({A[i]+B[0], {i, 0}});
        
    PII t;
    int ind = 0;
    while(ind < C){
        t = q.top();
        ans[ind++] = t.first;
        q.pop();
        int i = t.second.first, j = t.second.second;
		// Only have to push the Sum of current largest element of A wrt the next largest element of B
        q.push({A[i] + B[j+1], {i, j+1}});
    }    
    return ans;
}