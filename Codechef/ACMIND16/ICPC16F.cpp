#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N, M, L, R; cin >> N >> M >> L >> R;

    if((N * L > M) || (N * R < M)) cout << -1 << endl;
    else {
      set<pair<int, int> > S;
      vector<int> A;
      int temp = M;
      for(int i = 0; i < (N - 1); i++) {
        temp -= M/N;
        A.push_back(M/N);
        S.insert({M/N, i});
      }
      A.push_back(temp);
      S.insert({temp, N - 1});
      sort(A.begin(), A.end());

      for(int i = 0; i < N; i++) {
        vector<pair<int, int> > temp;
        for(int j = 0; j < A[i]; j++) {
          auto it = *S.rbegin(); S.erase(it);
          cout << (i + 1) << " " << (it.second + 1) << endl;
          it.first--;
          if(it.first > 0) temp.push_back(it);
        }
        for(auto it: temp) S.insert(it);
      }
    }
  }
}
