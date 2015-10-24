#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[100000];
int S[100000];
vector<int> ans;

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  S[N - 1] = A[N - 1];
  for(int i = N - 1; i >= 0; i--) S[i] = max(S[i + 1], A[i]);
  ans.push_back(0);
  for(int i = N - 2; i >= 0; i--) {
    if(A[i] > S[i + 1]) ans.push_back(0);
    else ans.push_back(S[i + 1] + 1 - A[i]);
  }
  reverse(ans.begin(), ans.end());
  for(auto it: ans) cout << it << " ";
  cout << endl;
}
