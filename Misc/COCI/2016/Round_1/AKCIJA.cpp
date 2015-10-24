#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

vector<int> C;

int main() {
  int N; cin >> N;
  C.resize(N);

  for(int i = 0; i < N; i++) cin >> C[i];

  sort(C.begin(), C.end(), greater<int>());

  long long ans = 0;
  for(int i = 0; i < N; i++) {
    if(i % 3 != 2) ans += C[i];
  }
  cout << ans << endl;
}
