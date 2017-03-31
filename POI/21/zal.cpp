#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int N, S;
int T[1000001];
int D[1000001];

int main() {
  scanf("%d %d", &N, &S);
  for(int i = 0; i < N; i++) scanf("%d", &T[i]);

  for(int i = 0, curr = 0; i < N; i++, curr++) {
    if(T[i] > curr) {
      curr = T[i];
    }
    else {
      T[i] = curr;
    }
  }
  T[N] = T[N - 1];

  for(int i = 0; i < N; i++) {
    D[i] = T[i + 1] - T[i];
  }

  int time = T[0], buffer = 0;
  for(int i = 0; i < N; i++) {
    buffer++;
    if(T[i + 1] - time >= S) {
      int avl = 0;
      for(int j = i + 1; j < N - 1; j++) {
        avl += D[j] - 1;
      }
      avl += T[i + 1] - time;
      avl -= S; // current train reaching dest time
      avl -= S; // one train come back time
      if(avl >= 0) {
        avl = min(avl, buffer - 1);
        time += S;
        time += avl + S;
        buffer -= avl + 1;
      }
    }
    time = max(time, T[i + 1]);
  }
  if(buffer > 0) {
    time += S;
    time += S + (buffer - 1);
  }
  printf("%d\n", time);
}
