#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    vector<pair<long double, int> > areas;

    for(int i = 0; i < N; i++) {
      int M; cin >> M;
      long long X[M], Y[M]; for(int j = 0; j < M; j++) cin >> X[j] >> Y[j];
      long double area = 0;
      for(int j = 0; j < (M - 1); j++) {
        area += (X[j] * Y[j + 1] - Y[j] * X[j + 1])/2.0;
      }
      area += (X[M - 1] * Y[0] - Y[M - 1] * X[0])/2.0;
      area = abs(area);
      areas.push_back({area, i + 1});
    }

    sort(areas.begin(), areas.end());
    int ans[N + 1];
    for(int j = 0; j < N; j++) {
      ans[areas[j].second] = j;
    }
    for(int i = 1; i <= N; i++) cout << ans[i] << " ";
    cout << endl;
  }
}
