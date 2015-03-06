// A and B and Team Training

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N, M; cin >> N >> M;

  cout << min(min(N, M), (N + M)/3) << endl;
}
