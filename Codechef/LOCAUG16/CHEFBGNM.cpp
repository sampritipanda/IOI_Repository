#include <iostream>
#include <algorithm>

using namespace std;

int div_3[10001];

int main() {
  for(int i = 1; i <= 10000; i++) {
    div_3[i] = div_3[i - 1] + i/3;
  }

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;

    long long P[3] = {1, 0, 0};
    int sum = 0;
    long long ans = 0;

    while(N--) {
      int D; long long F; cin >> F >> D;
      D %= 3;

      if(D == 0) ans += (F * (F + 1))/2 - F;
      else {
        ans += div_3[F] - F/3;
      }

      int cnt_1 = F/3 + (F % 3 >= 1 ? 1 : 0);
      int mod_1 = (sum + D) % 3;
      ans += 1LL * cnt_1 * P[mod_1];

      int cnt_2 = F/3 + (F % 3 >= 2 ? 1 : 0);
      int mod_2 = (sum + 2 * D) % 3;
      ans += 1LL * cnt_2 * P[mod_2];

      int cnt_3 = F/3;
      int mod_3 = sum;
      ans += 1LL * cnt_3 * P[mod_3];

      P[mod_1] += cnt_1;
      P[mod_2] += cnt_2;
      P[mod_3] += cnt_3;

      sum += (F * D) % 3;
      sum %= 3;
    }

    cout << ans << endl;
  }
}
