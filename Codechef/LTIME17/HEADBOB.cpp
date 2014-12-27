// Tanu and Head-Bob

#include <stdio.h>

int main()
{
  int T; scanf("%d", &T);
  int N;

  while(T--){
    scanf("%d", &N);
    char gesture[N];
    scanf("%s", gesture);
    bool not_sure = true;

    for(int i = 0; i < N; i++){
      if(gesture[i] == 'Y'){
        not_sure = false;
        printf("NOT INDIAN\n");
        break;
      }
      else if(gesture[i] == 'I'){
        not_sure = false;
        printf("INDIAN\n");
        break;
      }
    }

    if(not_sure) printf("NOT SURE\n");
  }
}
