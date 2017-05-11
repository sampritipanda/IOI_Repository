#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

pair<int, int> A[100000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    int s, t; cin >> s >> t;
    A[i] = {s + t, t - s};
  }
  sort(A, A + N);

  vector<int> lds;
  for(int i = 0; i < N; i++) {
    if(lds.empty() || -A[i].second > lds.back()) lds.push_back(-A[i].second);
    else {
      *lower_bound(lds.begin(), lds.end(), -A[i].second) = -A[i].second;
    }
  }
  cout << lds.size() << endl;
}
