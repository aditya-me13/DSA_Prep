// Problem Link: https://www.naukri.com/code360/problems/find-all-triplets-with-zero-sum_873143?topList=top-google-coding-interview-questions&leftPanelTab=1

vector<vector<int>> findTriplets(vector<int>arr, int n) {
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;

	for(int i=0; i<n; i++){
		if(i && arr[i]==arr[i-1]) continue;
		int j = i+1;
		int k = n-1;

		while(j<k){
			long long sum = arr[i];
			sum+=arr[j];
			sum+=arr[k];

			if(sum == 0){
				ans.push_back({arr[i], arr[j], arr[k]});
				j++;
				k--;
				while(j<k && arr[j]==arr[j-1]) j++;
				while(j<k && arr[k]==arr[k+1]) k--;
			}
			else if(sum < 0){
				j++;
				while(j<k && arr[j]==arr[j-1]) j++;
			}
			else{
				k--;
				while(j<k && arr[k]==arr[k+1]) k--;
			}
		}
	}
	return ans;
}

