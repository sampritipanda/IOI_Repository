// Prime Matrix

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  vector<int> sieve;
  sieve.push_back(2);
  sieve.push_back(3);
  for(int i = 5; i <= 100004; i++){
    int limit = sqrt(i);
    bool flag = true;
    for(int j = 2; j <= limit; j++){
      if(i % j == 0){
        flag = false;
        break;
      }
    }
    if(flag) sieve.push_back(i);
  }

  int N, M; scanf("%d %d", &N, &M);
  int matrix[N][M], table[N][M];

  int sumRows[N], sumColumns[M];
  for(int i = 0; i < N; i++) sumRows[i] = 0;
  for(int i = 0; i < M; i++) sumColumns[i] = 0;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      scanf("%d", &matrix[i][j]);
      table[i][j] = *lower_bound(sieve.begin(), sieve.end(), matrix[i][j]) - matrix[i][j];
      sumRows[i] += table[i][j];
      sumColumns[j] += table[i][j];
    }
  }

  unsigned int minSum = -1;
  for(int i = 0; i < N; i++){
    if(sumRows[i] < minSum) minSum = sumRows[i];
  }
  for(int i = 0; i < M; i++){
    if(sumColumns[i] < minSum) minSum = sumColumns[i];
  }

  printf("%d\n", minSum);
}
