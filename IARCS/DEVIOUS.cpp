// The Devious Minister

#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
  int N; scanf("%d", &N);
  int A[N];
  for(int i = 0; i < N; i++) scanf("%d", &A[i]);

  long long closest_ending_here = A[0], closest_sum = A[0];
  for(int i = 1; i < N; i++){
    if(abs(A[i]) < abs(closest_ending_here + A[i])){
      closest_ending_here = A[i];
    }
    else {
      closest_ending_here += A[i];
    }

    if(abs(closest_ending_here) < abs(closest_sum)){
      closest_sum = closest_ending_here;
    }
  }

  printf("%lld\n", closest_sum);
}
