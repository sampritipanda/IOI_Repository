// How to Repaint a Fence

#include <iostream>

using namespace std;

int* fenwick_tree;
int N;

int query(int p){
  int sum = 0;
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
  int T; cin >> T;

  while(T--){
    int K; cin >> N >> K;
    string C; cin >> C;
    fenwick_tree = new int[N + 1]();

    int count = 0;
    for(int i = 0; i < N; i++){
      char curr = (query(i + 1) % 2 == 0 ? C[i] : (C[i] == 'R' ? 'G' : 'R'));
      if(curr == 'G') continue;
      count++;
      range_update(i + 1, i + K, 1);
    }

    cout << count << endl;
    delete[] fenwick_tree;
  }
}
