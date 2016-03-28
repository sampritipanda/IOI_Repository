#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> A;
int N;

bool check() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        int x = A[i], y = A[j], z = A[k];
        int diff1 = abs(y - x), diff2 = abs(z - x), diff3 = abs(z - y);

        if(diff1 > 0 && diff1 <= 2 && diff2 > 0 && diff2 <= 2 && diff3 > 0 && diff3 <= 2) return true;
      }
    }
  }
  return false;
}

int main() {
  cin >> N;
  A.resize(N);
  for(int i = 0; i < N; i++) cin >> A[i];

  if(check()) cout << "YES" << endl;
  else cout << "NO" << endl;
}
