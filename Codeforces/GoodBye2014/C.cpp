// New Year Book Reading

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  int W[N], B[M], count[N];
  memset(count, 0, sizeof count);

  for(int i = 0; i < N; i++) cin >> W[i];
  for(int i = 0; i < M; i++) {
    cin >> B[i]; B[i]--;
  }

  vector<int> pile;
  for(int i = 0; i < M; i++) {
    if(count[B[i]] == 0) pile.push_back(B[i]);
    count[B[i]]++;
  }

  int ans = 0;
  for(int i = 0; i < M; i++) {
    auto it = pile.begin();
    while(*it != B[i]) {
      ans += W[*it];
      it++;
    }
    int value = *it;
    pile.erase(it);
    pile.insert(pile.begin(), value);
  }
  cout << ans << endl;
}
