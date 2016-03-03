#include <iostream>

using namespace std;

int main() {
  long long N; cin >> N;
  cout << N - (N/2 + N/3 + N/5 + N/7 - N/6 - N/10 - N/14 - N/15 - N/21 - N/35 + N/(2*3*5) + N/(2*3*7) + N/(2*5*7) + N/(3*5*7) - N/(2*3*5*7)) << endl;
}
