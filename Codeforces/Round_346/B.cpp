#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<vector<pair<int, string> > > A;

int main() {
  int N, M; cin >> N >> M;

  A.resize(M + 1);

  while(N--) {
    string S; int reg, score; cin >> S >> reg >> score;
    A[reg].push_back({score, S});
  }

  for(int i = 1; i <= M; i++) {
    sort(A[i].begin(), A[i].end());
    reverse(A[i].begin(), A[i].end());
  }

  for(int i = 1; i <= M; i++) {
    if(A[i].size() > 2 && A[i][2].first == A[i][1].first) {
      cout << "?" << endl;
    }
    else {
      cout << A[i][0].second << " " << A[i][1].second << endl;
    }
  }
}
