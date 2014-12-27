// k-Multiple Free Set

#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  int N, K; scanf("%d %d", &N, &K);
  int A[N];
  set<int> subset;

  for(int i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  sort(A, A + N);

  int length = 0;
  for(int i = 0; i < N; i++){
    if(A[i] >= K && (A[i] % K) == 0 && subset.find(A[i]/K) != subset.end()){
    }
    else {
      subset.insert(A[i]);
      length++;
    }
  }

  printf("%d\n", length);
}
