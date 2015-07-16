#include <iostream>
#include<stdio.h>
using namespace std;
 
int man[1 << 18];
int j, C, N;
 

 int measure(int i);
int main() 
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    cin >> j >> C >> N;
 
    int best = j * C * N * 100;
    for (int i = 1; i < (1 << (j * C)); i++)
    {
      man[i] = man[i - (i & -i)] + 1;
      if (man[i] == N) best = min(best, measure(i));
    }
    printf("Case #%d: %d\n", t, best);
  }
}
int measure(int i)
{
  int ans = 0;
  for (int r = 0; r < j; r++)
  {
    for (int c = 0; c < C; c++)
    {
      if (c > 0 and (i & (1 << (r * C + c))) and (i & (1 << (r * C + c - 1))))
        ans++;
      if (r > 0 and (i & (1 << (r * C + c))) and (i & (1 << (r * C + c - C))))
        ans++;
    }
  }
  return ans;
}
