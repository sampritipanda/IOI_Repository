#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// #define in cin
// #define out cout

int main() {
  ifstream in("highcard.in");
  ofstream out("highcard.out");

  int N; in >> N;

  vector<int> A(N), B;
  for(int i = 0; i < N; i++) {
    in >> A[i];
  }
  sort(A.begin(), A.end());

  for(int i = 1; i <= 2*N; i++) {
    if(!binary_search(A.begin(), A.end(), i)) B.push_back(i);
  }

  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());

  int i = 0, j = 0;
  int ans = 0;
  while(i < N && j < N) {
    if(B[j] > A[i]) {
      ans++;
      j++;
    }
    i++;
  }

  out << ans << endl;
}
