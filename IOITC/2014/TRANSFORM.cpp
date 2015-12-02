// Transform

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int, int> > steps;

inline int abs(int a) {
	return (a < 0 ? -a : a);
}

void solve(int i, int j, int multiple){
	for(int k = 0; k <= 30; k++){
		if(multiple & (1 << k)){
			steps.push_back(make_tuple(i, j, k));
		}
	}
}

int reduce(int a, int b, int i, int j) {
	while(a % b != 0){
		int a_sign = a/abs(a), b_sign = b/abs(b);
		a = abs(a); b = abs(b);
		
		if(a < b){
			int d = b/a;
			b %= a;
			if(b == 0) {
				b = a;
				d--;
			}
			solve(j, i, d);
		}
		else {
			int d = a/b;
			a %= b;
			solve(i, j, d);
		}
		
		a *= a_sign;
		b *= b_sign;
	}
	
	solve(i, j, abs(a)/abs(b));
	return b;
}

int main() {
  int N; cin >> N;
  int A[N]; for(int i = 0; i < N; i++) cin >> A[i];
  vector<int> positive, negative;

  int zero = 0;
  for(int i = 0; i < N; i++){
    if(A[i] < 0) negative.push_back(i);
    else if(A[i] > 0) positive.push_back(i);
    else zero++;
  }

  if(zero == (N - 1)) cout << 1 << endl << 0 << endl;
  else if(zero == N || positive.size() == 0 || negative.size() == 0) cout << 0 << endl;
  else {
	cout << 1 << endl;
	while(!positive.empty() && !negative.empty()){
		// i = Number to be changed to 0. j = number to used.
		int i = positive.back(), j = negative.back();
		if(negative.size() > positive.size()) {
			swap(i, j);
			negative.pop_back();
		}
		else {
			positive.pop_back();
		}
		A[j] = reduce(A[i], A[j], i + 1, j + 1);
		A[i] = 0;
	}
	
	cout << steps.size() << endl;
	for(auto it: steps){
		cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << endl;
	}
  }
}
