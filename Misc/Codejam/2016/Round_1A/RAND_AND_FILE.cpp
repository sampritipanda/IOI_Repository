#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int N; cin >> N;

    vector<vector<int> > A(2*N - 1);
    for(int i = 0; i < 2*N - 1; i++) {
      A[i].resize(N);
      for(int j = 0; j < N; j++) cin >> A[i][j];
    }
    sort(A.begin(), A.end());

    vector<vector<int> > A_N(N, vector<int> (N));

    int i = 0;
    for(int x = 0; x < 2*N - 1; x++) {
      bool check = (i < N);
      for(int y = 0; i < N && y < N && A_N[i][y] != 0; y++) {
        if(A_N[i][y] != A[x][y]) {
          check = false;
          break;
        }
      }
      if((x == 0 || A[x][0] != A[x - 1][0]) && check) {
        for(int y = 0; y < N; y++) {
          A_N[i][y] = A[x][y];
        }
        i++;
      }
      else {
        for(int j = 0; j < N; j++) {
          check = true;
          for(int y = 0; y < N && A_N[y][j] != 0; y++) {
            if(A_N[y][j] != A[x][y]) {
              check = false;
              break;
            }
          }
          if(!check) continue;
          for(int y = 0; y < N; y++) {
            A_N[y][j] = A[x][y];
          }
        }
      }
    }

    multiset<vector<int>> M;
    for(int i = 0; i < N; i++) {
      vector<int> curr;
      for(int j = 0; j < N; j++) {
        curr.push_back(A_N[i][j]);
      }
      M.insert(curr);
    }
    for(int j = 0; j < N; j++) {
      vector<int> curr;
      for(int i = 0; i < N; i++) {
        curr.push_back(A_N[i][j]);
      }
      M.insert(curr);
    }

    for(auto it: A) {
      M.erase(M.find(it));
    }

    cout << "Case #" << t << ": ";
    vector<int> ans = *M.begin();

    for(int i = 0; i < N; i++) {
      cout << ans[i];
      cout << (i == N - 1 ? "\n" : " ");
    }
  }
}
