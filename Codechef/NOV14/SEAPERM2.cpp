// Sereja and Permutations

#include <stdio.h>
#include <set>

int main() {
  int T; scanf("%d", &T);

  while(T--){
    int N; scanf("%d", &N);
    int q[N][N-1];
    std::set<int> numbers, perm;

    for(int i = 0; i < N; i++){
      for(int j = 0; j < N - 1; j++){
        scanf("%d", &q[i][j]);
        numbers.insert(q[i][j]);
      }
    }
  }
}
