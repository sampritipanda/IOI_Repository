// Fish Weight

#include <iostream>
#include <set>
#include <map>

using namespace std;

map<int, int> A, B;
set<int> types;

int main() {
  ios::sync_with_stdio(false);

  A.clear(); B.clear();
  types.clear();

  int N, M, K; cin >> N >> M >> K;
  for(int i = 0; i < N; i++) {
    int a; cin >> a;
    types.insert(a);
    A[a]++;
  }
  for(int i = 0; i < M; i++) {
    int a; cin >> a;
    types.insert(a);
    B[a]++;
  }

  for(auto it: types) {
    int x = min(A[it], B[it]);
    A[it] -= x; B[it] -= x;
  }

  int count_A = 0, count_B = 0;

  bool possible = false;

  for(auto it = types.rbegin(); it != types.rend(); it++) {
    count_A += A[*it]; count_B += B[*it];

    if(count_A > count_B) {
      possible = true;
      break;
    }
  }

  if(possible) cout << "YES" << endl;
  else cout << "NO" << endl;
}
