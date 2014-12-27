// Chef and Words

#include <stdio.h>
#include <cstring>
#include <math.h>

void matrixSqr(long double matrix[][26]) {
  long double temp[26][26];
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      temp[i][j] = matrix[i][j];
      matrix[i][j] = 0;
    }
  }

  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      for (int k = 0; k < 26; ++k) matrix[i][j] += temp[i][k]*temp[k][j];
    }
  }
}

void matrixMul(long double matrix[][26], long double n[][26]) {
  long double temp[26][26];
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      temp[i][j] = matrix[i][j];
      matrix[i][j] = 0;
    }
  }

  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      for (int k = 0; k < 26; ++k)  matrix[i][j] += temp[i][k]*n[k][j];
    }
  }
}

void matrixExp(long double matrix[][26], long double result[][26], int K) {
  while (K--) {
    matrixMul(result, matrix);
  }
}

int main(){
  int T; scanf("%d", &T);
  int N, K;
  char S[10];
  char curr_s[10];
  long double table[26][26], new_table[26][26];

  while(T--){
    scanf("%d %d", &N, &K);
    scanf("%s", S);
    int len = strlen(S);

    for(int i = 0; i < 26; i++){
      for(int j = 0; j < 26; j++){
        scanf("%Lf", &table[i][j]);
        if(i == j){
          new_table[i][j] = 1;
        }
        else {
          new_table[i][j] = 0;
        }
      }
    }

    matrixExp(table, new_table, K);

    long double total = 0.0;
    while(N--){
      long double total_curr = 1.0;
      scanf("%s", curr_s);
      if(strlen(curr_s) == len){
        for(int i = 0; i < len; i++){
          total_curr *= new_table[S[i] - 'a'][curr_s[i] - 'a'];
        }
        total += total_curr;
      }
    }
    printf("%Lf\n", total);
  }
}
