// Pasha and Tea

#include <cstdio>
#include <algorithm>

using namespace std;

double A[200010];

int main() {
  int N; double W; scanf("%d %lf", &N, &W);

  for(int i = 1; i <= 2 * N; i++) scanf("%lf", &A[i]);
  sort(A, A + (2*N));

  double tmp = W/(3*N);
  if(A[1] <= tmp) tmp = A[1];
  if(A[N + 1] <= (2 * tmp)) tmp = A[N + 1]/2;

  printf("%.7f\n", 3 * N * tmp);
}
