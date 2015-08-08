// N Boy and Sum

#include <iostream>

using namespace std;

long long series[100001];

int main() {
  ios::sync_with_stdio(false);

  series[0] = 0;
  series[1] = 1;
  for(int i = 2; i <= 100000; i++) {
    if(i & 1) series[i] = series[i - 1] + i;
    else series[i] = series[i - 1] - i;
  }

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    cout << series[N] << endl;
  }
}
