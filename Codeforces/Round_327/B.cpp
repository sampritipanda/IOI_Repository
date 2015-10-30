#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> A[26];
vector<int> B;
string S;

int main() {
  ios::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  string S; cin >> S;

  for(int i = 0; i < 26; i++) A[i].push_back(i);

  while(M--) {
    char x, y; cin >> x >> y;
    int a = x - 'a', b = y - 'a';
    swap(A[a], A[b]);
  }

  B.resize(26);
  for(int i = 0; i < 26; i++) {
    for(auto j: A[i]) {
      B[j] = i;
    }
  }

  for(int i = 0; i < N; i++) {
    S[i] = char(B[S[i] - 'a'] + 'a');
  }

  cout << S << endl;
}
