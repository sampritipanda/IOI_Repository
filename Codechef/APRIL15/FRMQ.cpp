// Chef and Array

#include <stdio.h>
#include <cmath>

using namespace std;

// Credits to http://web.ist.utl.pt/joao.carreira/rmqdp.html for sparse table approach

int table[20][100010];

inline int min(int i, int j){
  return i < j ? i : j;
}

inline int max(int i, int j){
  return i > j ? i : j;
}

inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
                c=getchar_unlocked();
            }
    while(c>='0'&&c<='9'){
                x=(x<<1)+(x<<3)+c-'0';
                c=getchar_unlocked();
            }
    return x;
}

int main() {
  int t_table[100001];
  int A[100001];

  register int N, N2; N = scan();
  N2 = N - 1;
  for(int i = 0; i < N; i++) A[i] = scan();

  for(int i = 0; i < N; i++) table[0][i] = A[i];

  for(int i = 1;(1 << i) <= N; i++) {
    for (int j = 0; j + (1 << i) - 1 < N; j++) {
      table[i][j] = max(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
    }
  }

  for(int i = 0; i <= N; i++){
    t_table[i] = 31 -__builtin_clz(i);
  }

  register int M = scan(), x = scan(), y = scan();
  register int i, j, t, a, b, swap_temp;
  register long long sum = 0;
  if(M <= 10000000){
    for(int c = 1; c <= M; c++){
      int i = min(x, y), j = max(x, y);
      int t = (int)(log(j - i + 1) / log(2));
      int p = 1 << t;
      sum += max(table[t][i], table[t][j - p + 1]);

      x = (x + 7) % (N - 1);
      y = (y + 11) % N;
    }
  }
  else {
    while(M--){
      i = x, j = y;
      if(i > j){
        swap_temp = j;
        j = i;
        i = swap_temp;
      }
      t = t_table[j - i + 1];
      a = j - (1 << t) + 1;
      sum += (table[t][i] > table[t][a] ? table[t][i] : table[t][a]);

      x += 7;
      if(x >= N2) x -= N2;
      y += 11;
      if(y >= N) y -= N;
    }
  }

  printf("%lld\n", sum);
}
