#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> G[1001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, K; cin >> N >> K;
  int a, b, c, d; cin >> a >> b >> c >> d;

  if(K < N + 1 || N == 4) {
    cout << -1 << endl;
  }
  else {
    vector<int> A;

    for(int i = 1; i <= N; i++) {
      if(i != a && i != b && i != c && i != d) {
        A.push_back(i);
      }
    }

    cout << a << " " << c << " "; for(int u: A) { cout << u << " "; } cout << d << " " << b << endl;
    cout << c << " " << a << " "; for(int u: A) { cout << u << " "; } cout << b << " " << d << endl;
  }
}
