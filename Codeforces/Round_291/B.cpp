// Han Solo and Lazer Gun

#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main() {
  int n, x, y; cin >> n >> x >> y;
  set<double> slopes;

  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    double slope;
    if(a - x == 0) slope = 9999999;
    else slope = (b - y)/double(a - x);
    slopes.insert(slope);
  }

  cout << slopes.size() << endl;
}
