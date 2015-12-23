#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// #define in cin
// #define out cout

int A[3][100001];

int main() {
  ifstream in("bcount.in");
  ofstream out("bcount.out");

  int N, Q; in >> N >> Q;

  memset(A, 0, sizeof A);

  for(int i = 1; i <= N; i++) {
    A[0][i] = A[0][i - 1];
    A[1][i] = A[1][i - 1];
    A[2][i] = A[2][i - 1];

    int x; in >> x;
    A[x - 1][i]++;
  }

  while(Q--) {
    int a, b; in >> a >> b;
    out << A[0][b] - A[0][a - 1] << " " << A[1][b] - A[1][a - 1] << " "  << A[2][b] - A[2][a - 1] << endl;
  }
}
