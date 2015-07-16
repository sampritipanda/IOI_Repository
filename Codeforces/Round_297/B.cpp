#include <iostream>
#include <string>

using namespace std;

int* fenwick_tree;
int N;

long long query(int p){
  long long sum = 0;
  while(p > 0){
      sum += fenwick_tree[p];
      p -= p & -p;
    }
  return sum;
}

void update(int k, int v){
  while(k <= N){
      fenwick_tree[k] += v;
      k += k & -k;
    }
}

void range_update(int l, int r, int k){
  update(l, k);
  update(r + 1, -k);
}

int main() {
  string S; cin >> S;
  int m; cin >> m;
  N = S.length();
  fenwick_tree = new int[N + 1]();
  for(int i = 0; i < m; i++){
    int a; cin >> a;
    range_update(a, N - a + 1, 1);
  }

  for(int i = 0; i < (N/2); i++){
    if(query(i + 1) % 2 == 1) {
      char t = S[N - i - 1]; S[N - i - 1] = S[i]; S[i] = t;
    }
  }

  cout << S << endl;
  delete[] fenwick_tree;
}
