// Problem Link: https://www.naukri.com/code360/problems/jump-game_893178?topList=top-google-coding-interview-questions&leftPanelTab=1&leftPanelTabValue=PROBLEM

int minJumps(vector<int> &arr,int n){

    int maxsum=0;
    // check if possible to reach the end
    for(int i=0; i < arr.size();i++){
        if(i>maxsum)return -1;
        maxsum=max(maxsum,i+arr[i]);
    }

    int jump=0;
    int l=0;
    int r=0;
    while (r<n-1){
        int farthermost=0;
        for(int i=l;i<=r;i++){
            farthermost=max(farthermost,i+arr[i]);
        }
        l=r+1;
        r=farthermost;
        jump+=1;
    }
    return jump;
}