// Average

#include <stdio.h>
#include <map>

int main() {
  int N; scanf("%d", &N);
  int A[N];
  std::map<int, bool> hashmap;
  int average_count = 0;

  for(int i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }

  for(int i = 0; i < N; i++){
    int sum = A[i] * 2;
    for(int j = 0; j < N; j++){
      int temp = sum - A[j];
      if(hashmap[temp] == 1) average_count++;
      hashmap[A[j]] = 1;
    }
    hashmap.clear();
  }

  printf("%d\n", average_count);
}
