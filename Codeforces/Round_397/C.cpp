#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> G;

int main() {
  long long K, A, B; cin >> K >> A >> B;
  long long ans = (A / K) + (B / K);
  bool rekt = false;
  if(A % K > 0 && B/K == 0) rekt = true;
  if(B % K > 0 && A/K == 0) rekt = true;
  if(ans == 0 || rekt) cout << -1 << endl;
  else cout << ans << endl;
}
