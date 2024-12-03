#include<bits/stdc++.h>
using namespace std;

int cal_max_cost(vector<vector<int> > m, int i, int j, int cost){
	cost += m[i][j];
	if(i == m.size()-1 && j == m[0].size()-1) return cost;
	if(i == m.size()-1){
		cost = cal_max_cost(m, i, j+1, cost);
	}else if(j == m[0].size()-1){
		cost = cal_max_cost(m, i+1, j, cost);
	}else{
		int c1 = cal_max_cost(m, i+1, j, cost);
		int c2 = cal_max_cost(m, i, j+1, cost);
		cost = c1 > c2 ? c1 : c2;
	}
	return cost;
}

vector<vector<vector<int> > > permutation(vector<vector<int> > m, int col){
	vector<vector<vector<int> > > res;
	if(col == m[0].size()-1){
		vector<vector<int> > t;
		vector<int> a, b;
		a.push_back(m[0][col]);
		b.push_back(m[1][col]);
		t.push_back(a); t.push_back(b);
		res.push_back(t);
		return res;
	}

	res = permutation(m, col+1);
	vector<vector<vector<int> > > ans;
	for (int i = 0; i < res.size(); ++i){
		for (int j = 0; j <= res[i][0].size(); ++j){
			vector<vector<int> > t = res[i];
			t[0].insert(t[0].begin()+j, m[0][col]);
			t[1].insert(t[1].begin()+j, m[1][col]);
			ans.push_back(t);
		}
	}

	return ans;
}

int perform(vector<vector<int> > matrix){
	vector<vector<vector<int> > > p = permutation(matrix, 0);

	int ans_cost = INT_MIN;
	for (int i = 0; i < p.size(); ++i){
		int cost = cal_max_cost(p[i], 0, 0, 0);
		if (cost > ans_cost){
			ans_cost = cost;
		}
	}

	return ans_cost;
}

int main(){
	int t; cin >> t;
	while(t--){
		int col; cin >> col;
		vector<vector<int> > matrix;
		for (int i = 0; i < 2; ++i){
			vector<int> t;
			for (int j = 0; j < col; ++j){
				int k; cin>>k; t.push_back(k);
			}
			matrix.push_back(t);
		}

		cout << perform(matrix) << endl;
	}
}