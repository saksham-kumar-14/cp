#include<bits/stdc++.h>
using namespace std;

int perform(vector<int> arr, int n){
	
	int ans = 0;
	int k = 0;
	int r = 1;
	for (int i = 0; i < n; ++i){
		int flag = 0;
		k += arr[i];

		if (!flag && k == r) {
			++ans;
			flag = 1;
		}

		if (k >= r){
			int t = r;
			t += sqrt(t)*2 + (sqrt(t)+2)*2;
			if(!flag && k == t) {
				++ans;
				flag = 1;
			}
			while(k >= t){
				t += sqrt(t)*2 + (sqrt(t)+2)*2;
				if(!flag && k == t){
					++ans;
					flag = 1;
				}
			}
			r = t;
		}
	}

	return ans;
}


int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr;
		for(int i = 0; i < n; ++i){
			int t; cin>>t;
			arr.push_back(t);
		}

		cout << perform(arr, n) << endl;;
	}
}