#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int N; cin >> N;

  if(N == 1) {
    cout << -1 << endl;
  }
  else if(N == 2) {
    int x1, y1; cin >> x1 >> y1;
    int x2, y2; cin >> x2 >> y2;
    if(x1 != x2 && y1 != y2) {
      cout << abs(x1 - x2) * abs(y1 - y2) << endl;
    }
    else cout << -1 << endl;
  }
  else if(N == 3) {
    vector<int> x(N), y(N);
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int X, Y;
    if(x[0] == x[1]) X = abs(x[2] - x[1]);
    else X = abs(x[0] - x[1]);
    if(y[0] == y[1]) Y = abs(y[2] - y[1]);
    else Y = abs(y[0] - y[1]);

    cout << X * Y << endl;
  }
  else {
    vector<int> x(N), y(N);
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    cout << abs(x[0] - x[3]) * abs(y[0] - y[3]) << endl;
  }
}
