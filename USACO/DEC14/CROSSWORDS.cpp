// Crosswords

#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

int main() {
  freopen("crosswords.in", "r", stdin);
  freopen("crosswords.out", "w", stdout);

  int N, M; scanf("%d %d", &N, &M);
  bool clear[N][M];
  vector<pair<int, int> > clues;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      char a; scanf(" %c", &a);
      if(a == '.') clear[i][j] = true;
      else if(a == '#') clear[i][j] = false;
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(clear[i][j]){
        if((j == 0 || !clear[i][j - 1]) && ((j + 2) < M && clear[i][j + 1] && clear[i][j + 2])) {
          clues.push_back(make_pair(i, j));
        }
        else if((i == 0 || !clear[i - 1][j]) && ((i + 2) < N && clear[i + 1][j] && clear[i + 2][j])) {
          clues.push_back(make_pair(i, j));
        }
      }
    }
  }

  unsigned long size = clues.size();
  printf("%lu\n", size);
  for(int i = 0; i < size; i++){
    printf("%d %d\n", clues[i].first + 1, clues[i].second + 1);
  }

  fclose(stdin);
  fclose(stdout);
}
