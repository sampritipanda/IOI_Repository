#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int P, K;
long long cnt = 0;
vector<int> A;

void solve(int i) {
  if(i == P) {
    bool ok = true;
    for(int x = 0; x < P; x++) {
      if((K * A[x]) % P != A[(K * x) % P]) {
        ok = false;
        break;
      }
    }

    if(ok) {
      // for(int i = 0; i < P; i++) cout << A[i] << " "; cout << endl;
      cnt++;
    }
    return;
  }

  for(int x = 0; x < P; x++) {
    A[i] = x;
    solve(i + 1);
  }
}

int main() {
  cin >> P >> K;
  A.resize(P);

  solve(0);

  cout << cnt << endl;
}
