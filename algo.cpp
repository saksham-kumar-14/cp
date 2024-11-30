#include<bits/stdc++.h>
using namespace std;


// generate subsets
vector<vector<int> > subsets(vector<int> arr, int ptr){
	vector<vector<int> > res;
	if(ptr == arr.size()-1){
		vector<int> t;
		res.push_back(t);
		t.push_back(arr[ptr]);
		res.push_back(t);
		return res;
	}

	res = subsets(arr, ptr+1);
	int len = res.size();
	for(int i = 0; i < len; ++i){
		vector<int> t = res[i];
		t.push_back(arr[ptr]);
		res.push_back(t);
	}

	return res;
}

// generate permutations
vector<vector<int> >  permutations(vector<int> arr, int ptr){
	vector<vector<int> > res;
	if(ptr == arr.size()-1){
		vector<int> t;
		t.push_back(arr[ptr]);
		res.push_back(t);
		return res;
	}

	res = permutations(arr, ptr+1);
	vector<vector<int> > ans;

	int m = res.size(), n = res[0].size();
	for(int i = 0; i < m; ++i){
		for(int j = 0; j <= n; ++j){
			vector<int> t = res[i];
			t.insert(t.begin()+j, arr[ptr]);
			ans.push_back(t);
		}
	}

	return ans;
}


//cyclic sort
int missing_no(vector<int> arr, int n){
	int i = 0;
	while(i!=arr.size()){
		int correctIdx = arr[i]-1;
		if(arr[i] == arr[correctIdx] || arr[i] == arr.size()) ++i;
		else{
			int t = arr[i];
			arr[i] = arr[correctIdx];
			arr[correctIdx] = t;
		}
	}

	for(int i = 0; i < arr.size(); ++i){
		if(arr[i] != i+1) return i+1;
	}

	return arr.size();
}


int kadanes_algo(vector<int> a){
	int max_sum = 0;
	int csum = 0;

	for(int i = 0; i < a.size(); ++i){
		csum += a[i];
		if(max_sum < csum) max_sum = csum;
		if(csum < 0) csum = 0;
	}

	return max_sum;
}

vector<int> merge(vector<int> a1, vector<int> a2){
	vector<int> r;
	int s1 = 0, s2 = 0;
	int e1 = a1.size(), e2 = a2.size();
	int i = s1, j = s2;

	while(i < e1 && j < e2){
		if(a1[i] > a2[j]){
			r.push_back(a2[j]);
			++j;
		}else{
			r.push_back(a1[i]);
			++i;
		}
	}

	while(i < e1){ r.push_back(a1[i]); ++i; }
	while(j < e2){ r.push_back(a2[j]); ++j; }

	return r;
}

vector<int> merge_sort(vector<int> arr){

	if(arr.size() < 2) return arr;

	int s = 0, e = arr.size();
	int m = (s + e)/2;
	vector<int> arr1;
	vector<int> arr2;
	for(int i = s; i < e; ++i){
		if(i < m) arr1.push_back(arr[i]);
		else arr2.push_back(arr[i]);
	}

	arr1 = merge_sort(arr1);
	arr2 = merge_sort(arr2);
	return merge(arr1, arr2);
}

vector<int> quick_sort(vector<int> arr, int s, int e){

	if(s >= e) return arr;

	int i = s, j = e;
	int p = (i + j)/2;

	while(i <= j){
		while(arr[i] < arr[p]) ++i;
		while(arr[j] > arr[p]) --j;
		
		if(i <= j) {
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
			++i;
			--j;
		}
	}

	arr = quick_sort(arr, s, j);
	arr = quick_sort(arr, i, e);

	return arr;
}


int main(){

	int n; cin>>n;
	vector<int> v;
	for(int i = 0; i < n; ++i){
		int t; cin >> t;
		v.push_back(t);
	}

	vector<vector<int> > r = permutations(v, 0);

	cout << r.size() << endl;
	for(int i = 0; i < r.size(); ++i){
		for(int j = 0; j < r[i].size(); ++j){
			cout << r[i][j] << " ";
		}cout << endl;
	}
}
