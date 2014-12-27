// Physics Class

#include <stdio.h>
#include <map>
#include <array>

int main()
{
  int N, M; scanf("%d %d", &N, &M);
  int id, attr, value, priority;

  std::map<int, std::map<int, std::array<int, 2> > > dom;

  while(N--) {
    scanf("%d %d %d %d", &id, &attr, &value, &priority);
    if(dom[id].count(attr) == 0){
      dom[id][attr] = {value, priority};
    }
    else{
      if(priority >= dom[id][attr][1]) {
        dom[id][attr] = {value, priority};
      }
    }
  }

  while(M--){
    scanf("%d %d", &id, &attr);
    printf("%d\n", dom[id][attr][0]);
  }
}
