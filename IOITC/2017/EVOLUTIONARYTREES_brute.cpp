#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, M;
vector<vector<int> > A;

bool solve(vector<set<int> > cands) {
	if(cands.size() <= 1) return true;
	
	set<int> pos;
	for(int i = 0; i < cands.size(); i++) {
		for(int x: cands[i]) {
			pos.insert(x);
		}
	}
	
	for(int i: pos) {
		bool possible = true;
		set<int> not_there, there;
		for(int j = 0; j < cands.size(); j++) {
			if(cands[j].count(i) == 0) {
				for(int x: cands[j]) {
					if(there.count(x) > 0) {
						possible = false;
						break;
					}
					not_there.insert(x);
				}
			}
			else {
				for(int x: cands[j]) {
					if(not_there.count(x) > 0) {
						possible = false;
						break;
					}
					there.insert(x);
				}
			}
			if(!possible) break;
		}
		
		if(possible) {
			vector<set<int> > left, right;
			for(int j = 0; j < cands.size(); j++) {
				if(cands[j].count(i) == 0) {
					left.push_back(cands[j]);
				}
				else {
					cands[j].erase(i);
					right.push_back(cands[j]);
				}
			}
			return solve(left) && solve(right);
		}
	}
	
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin >> N >> M;
	A.resize(N, vector<int>(M));
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> A[i][j];	
		}
	}
	
	vector<set<int> > cands(N - 1);
	for(int i = 1; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(A[0][j] != A[i][j]) cands[i - 1].insert(j);
		}
	}
	
	if(solve(cands)) cout << "Yes" << endl;
	else cout << "No" << endl;
}
