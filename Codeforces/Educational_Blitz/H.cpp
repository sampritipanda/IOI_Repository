#include <iostream>

using namespace std;

int main() {
  long long N; cin >> N;
  long long f_way = N * (N - 1) * (N - 2) * (N - 3) * (N - 4);
  cout << f_way/120 * f_way << endl;
}
