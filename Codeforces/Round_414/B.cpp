#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int N, h; cin >> N >> h;

  double A = 1/2.0 * h;

  cout << fixed << setprecision(12);
  for(int i = 1; i < N; i++) {
    double A2 = A/N * i;
    double h_rat = sqrt(A2/A);
    double h_prime = h * h_rat;
    cout << h_prime << " ";
  }
  cout << endl;
}
