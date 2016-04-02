#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int R[16], M[16];

bool wash(int D) {
  for(int i = 0; i < N; i++) {
    if(D % M[i] == R[i]) return true;
  }
  return false;
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) cin >> M[i];
  for(int i = 0; i < N; i++) cin >> R[i];

  int cnt1 = 0;
  for(int i = 0; i < 100000; i++) {
    if(wash(i)) cnt1++;
  }
  int cnt2 = cnt1;
  if(wash(100000)) cnt2++;

  double ans1 = double(cnt1)/100000;
  double ans2 = ans1;//double(cnt2)/100001;

  cout << fixed << setprecision(8) << (ans1 + ans2)/2 << endl;
}
