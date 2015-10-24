#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

vector<pair<long long, long long> > C;

long long solve(int i, int j) {
}

int main() {
  int N; cin >> N;

  C.resize(N);
  for(int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    C[i] = {a, b};
  }

  sort(C.begin(), C.end(), greater<pair<int, int> >());

  cout << max(solve(0, 0), solve(0, 1)) << endl;
}
