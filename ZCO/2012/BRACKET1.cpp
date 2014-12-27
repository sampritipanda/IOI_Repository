// Matched Brackets 1

#include <stdio.h>

int main(){
  int N; scanf("%d", &N);
  int nesting = 0, max_nesting = 0, nesting_pos = 0;
  int curr_brackets = 0, max_brackets = 0, brackets_pos = 0;

  for(int i = 0; i < N; i++){
    int curr;
    scanf("%d", &curr);
    curr_brackets++;
    if(curr == 1){
      nesting++;
      if(nesting > max_nesting){
        max_nesting = nesting;
        nesting_pos = i;
      }
    }
    else {
      nesting--;
    }
    if(nesting == 0){
      if(curr_brackets > max_brackets) {
        max_brackets = curr_brackets;
        brackets_pos = i;
      }
      curr_brackets = 0;
    }
  }

  printf("%d %d %d %d\n", max_nesting, nesting_pos + 1, max_brackets, brackets_pos - (max_brackets - 1) + 1);
}
