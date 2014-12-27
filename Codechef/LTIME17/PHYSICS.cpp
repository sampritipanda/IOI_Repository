// Physics Class

#include <stdio.h>
#include <algorithm>
#include <map>

int main()
{
  int T; scanf("%d", &T);
  int N, F, h;
  std::map<int, int> heights;

  while(T--){
    heights.clear();

    scanf("%d %d", &N, &F);
    for(int i = 0; i < N; i++){
      scanf("%d", &h);
      while(h % F == 0) {
        h /= F;
      }
      heights[h]++;
    }

    int count = 0;

    for (std::map<int,int>::iterator it=heights.begin(); it!=heights.end(); ++it){
      int val = it->second;
      count += (val*(val-1))/2;
    }

    printf("%d\n", count);
  }
}
