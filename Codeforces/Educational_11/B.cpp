#include <iostream>
#include <algorithm>

using namespace std;

int A[101][5];
int P[401];

int main() {
  int N, M; cin >> N >> M;

  for(int i = 1; i <= M; i++) P[i] = i;

  int curr = 0;
  for(int i = 1; i <= N; i++) {
    A[i][0] = P[++curr];
    A[i][3] = P[++curr];
  }
  for(int i = 1; i <= N; i++) {
    A[i][1] = P[++curr];
    A[i][2] = P[++curr];
  }

  vector<int> ans;
  for(int i = 1; i <= N; i++) {
    ans.push_back(A[i][1]);
    ans.push_back(A[i][0]);
    ans.push_back(A[i][2]);
    ans.push_back(A[i][3]);
  }

  for(auto it: ans) {
    if(it != 0) cout << it << " ";
  }
  cout << endl;
}
