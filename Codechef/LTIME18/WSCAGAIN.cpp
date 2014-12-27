// Deja Vu

#include <stdio.h>
#include <set>
#include <utility>

std::pair<int, int> sort(std::pair<int, int> a){
  if(a.first < a.second){
    return std::make_pair(a.first, a.second);
  }
  else {
    return std::make_pair(a.second, a.first);
  }
}

int main(){
  int T; scanf("%d", &T);
  int N, M, K;
  std::set<std::pair<int, int> > pairs;

  while(T--){
    scanf("%d", &N, &M, &K);
    for(int i = 0; i < M; i++){
      int X, Y;
      scanf("%d %d", &X, &Y);
      pairs.insert(sort(std::make_pair(X, Y)));
    }

    M = pairs.size();

    if(N == 1){
      printf("1\n");
    }
    if(N == 2){
      if(K == 1) printf("2\n");
      else printf("1\n");
    }
    else if(N == 3){
      if(M == 0) {
        if(K == 1) printf("3\n");
        if(K == 2) printf("2\n");
        else printf("1\n");
      }
      else if(M == 1) {
        if(K == 1) printf("3\n");
        if(K == 2) printf("2\n");
        if(K == 3) printf("1\n");
      }
      else if(M == 2) {
        if(K == 1) printf("3\n");
        if(K == 2) printf("2\n");
        if(K == 3) printf("1\n");
      }
      else if(M == 3) {
        if(K == 2) printf("2\n");
        if(K == 3) printf("1\n");
      }
    }

    pairs.clear();
  }
}
