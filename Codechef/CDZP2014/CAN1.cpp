// Candy Rush

#include <stdio.h>
#include <set>
#include <string.h>

int main() {
  int T; scanf("%d", &T);
  char belt[101];

  while(T--){
    scanf("%s", belt);
    std::set<char> candy_list;
    int max = 0, curr_count = 0;
    int L = strlen(belt);
    int i = 0;

    while(i < L){
      candy_list.insert(belt[i]);
      if(candy_list.size() > 2){
        candy_list.clear();
        if(curr_count > max) max = curr_count;
        curr_count = 0;
      }
      else {
        curr_count++;
        i++;
      }
    }
    printf("%d\n", max);
  }
}
