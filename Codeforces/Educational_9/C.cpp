#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<string, string> > A;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    string S; cin >> S;
    string T = S;

    int x = S.size();
    for(int j = x; j < 100; j++) {
      S += S[j % x];
    }

    A.push_back({S, T});
  }

  sort(A.begin(), A.end());

  for(auto it: A) {
    cout << it.second;
  }
  cout << endl;
}
