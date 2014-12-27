// Removing Columns

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M; scanf("%d %d", &N, &M);
  vector<vector<char> > columns(M);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      char c; scanf(" %c", &c);
      columns[j].push_back(c);
    }
  }

  if(N == 1) printf("0\n");
  else {
    int operations = 0;
    bool previousDeleted = true;
    for(int i = 0; i < M; i++){
      if(previousDeleted){
        if(!is_sorted(columns[i].begin(), columns[i].end())){
          operations++;
          previousDeleted = true;
        }
        else {
          previousDeleted = false;
        }
      }
      else {
      }
    }

    printf("%d\n", operations);
  }
}
