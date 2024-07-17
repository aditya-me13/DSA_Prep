class MinHeap{
private:
    vector<int> list;
public:
    MinHeap(){
        list.clear();
        list.push_back(-1);
    }

    void insert_(int val){
    list.push_back(val);
    int valInd = list.size()-1;
    int comInd;
    while(valInd>1){
        comInd = valInd>>1;
        if(list[comInd] <= list[valInd]){
            break;
        }
        else{
            swap(list[comInd], list[valInd]);
            valInd = comInd;
            }
        }
    }

    int delete_() {
        int n = list.size();
        if (n == 1) return -1; 
        swap(list[1], list[n - 1]);
        int to_return = list[n - 1];
        list.pop_back();
        n = list.size();
        int currInd = 1;
        int left, right;
        
        while (currInd < n) {
            left = currInd * 2;
            right = currInd * 2 + 1;
            int smallest = currInd;

            if (left < n && list[left] < list[smallest]) {
                smallest = left;
            }
            if (right < n && list[right] < list[smallest]) {
                smallest = right;
            }
            if (smallest != currInd) {
                swap(list[currInd], list[smallest]);
                currInd = smallest;
            } else {
                break;
            }
        }
        return to_return;
    }
};
vector<int> minHeap(int n, vector<vector<int>>& q) {
    MinHeap* mh = new MinHeap();
    vector<int> ans;
    for(auto query:q){
        if(query[0]==0) mh->insert_(query[1]);
        else ans.push_back(mh->delete_());
    }
    return ans;
}
