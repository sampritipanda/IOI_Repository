// Prizes, Prizes, more Prizes

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int N; cin >> N;
  long long P[N];
  for(int i = 0; i < N; i++) cin >> P[i];

  long long ans[] = {0, 0, 0, 0, 0};

  vector<pair<long long, int> > prizes;
  for(int i = 0; i < 5; i++) {
    int a; cin >> a;
    prizes.push_back({a, i});
  }
  sort(prizes.begin(), prizes.end(), greater<pair<int, int> >());

  long long pool = 0;
  for(int i = 0; i < N; i++) {
    pool += P[i];
    for(auto prize: prizes) {
      ans[prize.second] += pool/prize.first;
      pool %= prize.first;
    }
  }

  for(int i = 0; i < 5; i++) cout << ans[i] << " ";
  cout << endl;
  cout << pool << endl;
}
