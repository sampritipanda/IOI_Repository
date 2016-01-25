#include <iostream>
#include <set>

using namespace std;

int main() {
  int N, M; cin >> N >> M;

  set<int> S;

  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    while(x--) {
      int a; cin >> a;
      S.insert(a);
    }
  }

  bool pos = true;
  for(int i = 1; i <= M; i++) {
    if(S.count(i) == 0) {
      pos = false;
      break;
    }
  }

  if(pos) cout << "YES" << endl;
  else cout << "NO" << endl;
}
