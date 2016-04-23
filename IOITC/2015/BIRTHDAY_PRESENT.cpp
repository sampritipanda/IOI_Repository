#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>

using namespace std;

string S;
int F[26][10000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  cin >> S;

  F[S[0] - 'a'][0]++;
  for(int i = 1; i < N; i++) {
    for(int j = 0; j < 26; j++) F[j][i] = F[j][i - 1];
    F[S[i] - 'a'][i]++;
  }

  int Q; cin >> Q;

  while(Q--) {
    int T; cin >> T;

    int ans[27];
    int ind[27];
    memset(ans, 0, sizeof ans);
    memset(ind, 0, sizeof ind);

    for(int i = 0; i < N; i++) {
      set<int> indexes;
      for(int j = 0; j < 26; j++) {
        int pref_add = (i == 0 ? 0 : F[j][i - 1]);
        while(ind[j] < N && F[j][ind[j]] < T + pref_add) ind[j]++;
        if(ind[j] != N) indexes.insert(ind[j]);
      }

      int K = 0, sum_sub = 0;
      for(int j: indexes) {
        ans[K] += j - i - sum_sub;
        sum_sub += j - i - sum_sub;
        K++;
      }
      if(indexes.size() == 0) {
        ans[0] += N - i;
      }
      else {
        ans[K] += N - *indexes.rbegin();
      }
    }
    for(int i = 0; i <= 26; i++) cout << ans[i] << " ";
    cout << endl;
  }
}
