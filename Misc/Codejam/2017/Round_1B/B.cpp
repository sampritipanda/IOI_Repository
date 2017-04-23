#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int N, R, O, Y, G, B, V; cin >> N >> R >> O >> Y >> G >> B >> V;
    vector<pair<pair<int, int>, char> > A = {{{R, 0}, 'R'}, {{Y, 0}, 'Y'}, {{B, 0}, 'B'}};

    string ans = "";
    while(N--) {
      sort(A.begin(), A.end()); reverse(A.begin(), A.end());
      if(ans == "" || A[0].second != ans.back()) {
        if(ans == "") A[0].first.second++;
        ans += A[0].second;
        A[0].first.first--;
      }
      else if(A[1].first.first > 0 && A[1].second != ans.back()) {
        ans += A[1].second;
        A[1].first.first--;
      }
      else if(A[2].first.first > 0 && A[2].second != ans.back()) {
        ans += A[2].second;
        A[2].first.first--;
      }
      else {
        ans = "IMPOSSIBLE";
        break;
      }
    }
    if(ans[0] == ans.back()) ans = "IMPOSSIBLE";
    cout << "Case #" << t << ": " << ans << endl;
  }
}
