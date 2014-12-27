// Matched Brackets 2

#include <stdio.h>

int main(){
  int N; scanf("%d", &N);
  int alt_depth = 1, max_alt_depth = 0;
  int nesting_1 = 0, curr_nesting_len_1 = 0, max_nesting_len_1 = 0;
  int nesting_2 = 0, curr_nesting_len_2 = 0, max_nesting_len_2 = 0;
  int previous = -1;

  for(int i = 0; i < N; i++){
    int curr;
    scanf("%d", &curr);

    if(nesting_1 > 0) curr_nesting_len_1++;
    if(nesting_2 > 0) curr_nesting_len_2++;

    if(curr == 1){
      nesting_1++;
      if(previous == 3) alt_depth++;
    }
    else if(curr == 2){
      nesting_1--;
      if(nesting_1 == 0){
        if(curr_nesting_len_1 > max_nesting_len_1) max_nesting_len_1 = curr_nesting_len_1 + 1;
        curr_nesting_len_1 = 0;
      }
    }
    else if(curr == 3){
      nesting_2++;
      if(previous == 1) alt_depth++;
    }
    else if(curr == 4){
      nesting_2--;
      if(nesting_2 == 0){
        if(curr_nesting_len_2 > max_nesting_len_2) max_nesting_len_2 = curr_nesting_len_2 + 1;
        curr_nesting_len_2 = 0;
      }
    }

    if(alt_depth > max_alt_depth) max_alt_depth = alt_depth;
    if(nesting_1 == 0 && nesting_2 == 0) { alt_depth = 0; previous = -1; }
    previous = curr;
  }

  printf("%d %d %d\n", max_alt_depth, max_nesting_len_1, max_nesting_len_2);
}
