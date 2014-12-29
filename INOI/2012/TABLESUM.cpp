// Table Sum

#include <stdio.h>

inline int max(int a, int b){
  return (a > b) ? a : b;
}

int main() {
  int N; scanf("%d", &N);
  int row[N];

  int max_index = 0, max_2_index = 0;
  int max_1 = -1, max_2 = -2;
  for(int i = 0; i < N; i++) {
    scanf("%d", &row[i]);
    if(row[i] > max_1){
      max_index = i;
      max_1 = row[i];
    }
    else if(row[i] > max_2_index){
      max_2_index = i;
      max_2 = row[i];
    }
  }

  for(int i = 0; i < N; i++){
    int bottom_1 = (i + max_index + 1) % N;
    int bottom_2 = (i + max_2_index + 1) % N;
    if(bottom_1 == 0) bottom_1 = 4;
    if(bottom_2 == 0) bottom_2 = 4;
    printf("%d ", max(row[max_index] + bottom_1, row[max_2_index] + bottom_2));
  }
  printf("\n");
}
