#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int N, Q;
map<pair<char, char>, char> queries;
int ans = 0;
string S = "";

void solve(int i) {
  if(i == N) {
    string T = S;
    while(T.length() > 1) {
      if(queries.count({T[0], T[1]}) == 0) break;
      else {
        char repl = queries[{T[0], T[1]}];
        T = T.substr(2);
        T = repl + T;
      }
    }

    if(T == "a") {
      ans++;
    }
    return;
  }

  for(int j = 0; j < 6; j++) {
    S += char('a' + j);
    solve(i + 1);
    S.pop_back();
  }
}

int main() {
  cin >> N >> Q;

  for(int i = 0; i < Q; i++) {
    string A, B; cin >> A >> B;
    queries[{A[0], A[1]}] = B[0];
  }

  solve(0);

  cout << ans << endl;
}
