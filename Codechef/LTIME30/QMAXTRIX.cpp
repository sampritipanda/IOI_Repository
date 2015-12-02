#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long R[100001], C[100002];
vector<pair<int, int> > A;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  memset(R, 0, sizeof R); memset(C, 0, sizeof C);

  int N; cin >> N;

  A.push_back({-1, -1});
  for(int i = 1; i <= N; i++) {
    int x, y; cin >> x >> y;
    A.push_back({x, y});
    R[i] = y - x + 1;
    C[x] += 1;
    C[y + 1] -= 1;
  }

  for(int i = 2; i <= N; i++) C[i] = C[i - 1] + C[i];

  long long sum = 0;
  for(int i = 1; i <= N; i++) sum += R[i];

  int Q; cin >> Q;

  while(Q--) {
    int x, y; cin >> x >> y;
    long long curr = sum - R[x] - C[y];
    if(y >= A[x].first && y <= A[x].second) curr++;

    cout << (curr % 2 ? 'O' : 'E') << endl;
  }
}
