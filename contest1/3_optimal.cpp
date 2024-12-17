#include<bits/stdc++.h>
using namespace std;

void perform(vector<vector<int> > arr){
	int sum = INT_MIN;
	for(int i = 0; i < arr[0].size(); ++i){
		int t = 0;
		for(int j = 0; j < arr[0].size(); ++j){
			t += max(arr[0][j], arr[1][j]);
			if(i == j) t += min(arr[0][j], arr[1][j]);
		}
		sum = max(sum, t);
	}
	cout << sum << endl;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin>>n;
		vector<vector<int> > arr;
		for(int i = 0; i < 2; ++i){
			vector<int> temp;
			for(int j = 0; j < n; ++j){
				int t; cin>>t;
				temp.push_back(t);
			}
			arr.push_back(temp);
		}
		perform(arr);
	}
}
