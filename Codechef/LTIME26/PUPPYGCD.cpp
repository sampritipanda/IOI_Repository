// Puppy and GCD

#include <iostream>
#include <algorithm>

using namespace std;

long long phi[1000010];
long long prefix_phi[1000010];

int main() {
  for (int i = 0; i < 1000000; i++) {
    phi[i] = i;
  }
  for (int i = 1; i < 1000000; i++) {
    for (int j   = 2 * i; j < 1000000; j += i){
      phi[j] -= phi[i];
    }
  }

  prefix_phi[1] = phi[1];
  for(int i = 2; i <= 1000000; i++) {
    prefix_phi[i] = prefix_phi[i - 1] + phi[i];
  }

  int T; cin >> T;

  while(T--) {
    int N, D; cin >> N >> D;

    cout << prefix_phi[N/D] << endl;
  }
}
