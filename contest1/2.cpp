#include<bits/stdc++.h>
using namespace std;

int is_present(string s, char a){
	for(int i = 0; i < s.length(); ++i){
		if (a == s[i]) return 1;
	}
	return 0;
}

int fac(int n){
	if(n == 0) return 1;
	return n*fac(n-1);
}

int cal(string s){
	int k = 0;
	string a = "";
	vector<int> v;
	for(int i = 0; i < s.length(); ++i){
		if(!is_present(a, s[i])){
			a += s[i];
		}
	}

	for (int i = 0; i < a.length(); ++i){
		int t = 0;
		for(int j = 0; j < s.length(); ++j){
			if(s[j] == a[i]) ++t;
		}
		v.push_back(t);
	}

	int num = fac(s.length());
	int den = 1;
	for(int i = 0; i < v.size(); ++i){
		den *= fac(v[i]);
	}

	return num/den;
}

string perform(string s, int n){

	string ans = s;
	int pmin = INT_MAX;

	for (int i = 0; i < n; ++i){
		string t = s;
		for (int j = 0; j < n; ++j){
			t[i] = t[j];
			int p = cal(t);
			if(p < pmin){
				pmin = p;
				ans = t;
			}
		}
	}

	return ans;
}

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		string s; cin>>s;
		cout << perform(s, n) << endl;
	}
}