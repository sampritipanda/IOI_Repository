#include <iostream>

using namespace std;

int F[1000001];

int main() {
  int N; cin >> N;

  int max_freq = 0, max_elem = 0;
  while(N--) {
    int x; cin >> x;
    F[x]++;
    if(max_freq < F[x]) {
      max_freq = F[x];
      max_elem = x;
    }
  }

  cout << max_elem << endl;
}
