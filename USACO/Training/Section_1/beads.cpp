/*
ID: sampdin1
PROG: beads
LANG: C++11
*/

#include <stdio.h>
#include <string>

using namespace std;

int main() {
  freopen("beads.in", "r", stdin);
  freopen("beads.out", "w", stdout);

  int N; scanf("%d", &N);
  char str[400]; scanf(" %s", str);
  string beads(str);

  int cur = 0, max = 0;
  char color;
  bool switched;

  for(int i = 0; i < N; ++i){
    cur = 0;
    switched = false;
    color = 'w';
    for(int j = 0; j < N; ++j){
      const char cur_c = beads[(i + j) % N];
      if(cur_c != 'w'){
        if(color == 'w'){
          color = cur_c;
        }
        else if(color != cur_c){
          if(switched)
            break;
          else{
            color = cur_c;
            switched = true;
          }
        }
      }
      ++cur;
    }
    if(cur > max)
      max = cur;
  }

  printf("%d\n", max);

  fclose(stdin);
  fclose(stdout);
}
