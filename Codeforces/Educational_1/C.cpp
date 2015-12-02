#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<long double, int> > A;

#define PI 3.14159265358979

int main() {
  int N; cin >> N;

  for(int i = 0; i < N; i++) {
    long double x, y; cin >> x >> y;
    A.push_back({atan2(y, x) * 180/PI, i + 1});
  }

  sort(A.begin(), A.end());

  pair<int, int> point; long double angle = 10101101;

  for(int i = 0; i < N - 1; i++) {
    if(abs(A[i + 1].first - A[i].first) < angle) {
      angle = abs(A[i + 1].first - A[i].first);
      point = {A[i + 1].second, A[i].second};
    }
  }

  if(360 - abs(A[N - 1].first - A[0].first) < angle) {
    point = {A[0].second, A[N - 1].second};
  }

  cout << point.first << " " << point.second << endl;
}
