#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int K[1000], S[1000];
double EPS = 0.000001;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int D, N; cin >> D >> N;
    for(int i = 0; i < N; i++) cin >> K[i] >> S[i];

    double max_time = 0.0;
    for(int i = 0; i < N; i++) max_time = max(max_time, (D - K[i])/double(S[i]));
    double ans = D/max_time;

    cout << "Case #" << t << ": " << fixed << setprecision(8) << ans << endl;
  }
}
