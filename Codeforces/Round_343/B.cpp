#include <iostream>
#include <algorithm>

using namespace std;

int M[367], F[367];

int main() {
  int N; cin >> N;

  while(N--) {
    char ch; int A, B; cin >> ch >> A >> B;

    for(int i = A; i <= B; i++) {
      if(ch == 'M') M[i]++;
      else F[i]++;
    }
  }

  int ans = 0;
  for(int i = 1; i <= 366; i++) {
    ans = max(ans, min(F[i], M[i]));
  }

  cout << 2*ans << endl;
}
