#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > E;

int main() {
  int N; cin >> N;

  for(int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    E.push_back({b, a});
  }

  sort(E.begin(), E.end());

  int cnt = 0;
  int curr_end = 0;

  for(int i = 0; i < N; i++) {
    if(E[i].second > curr_end) {
      curr_end = E[i].first;
      cnt++;
    }
  }
  cout << cnt << endl;
}
