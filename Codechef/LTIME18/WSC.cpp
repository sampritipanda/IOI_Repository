// A wolf, a sheep and cabbage

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
  int N, M;
  std::set<std::pair<int, int> > pairs;

  while(T--){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
      int X, Y;
      scanf("%d %d", &X, &Y);
      pairs.insert(sort(std::make_pair(X, Y)));
    }

    bool flag = false;
    // for(int i = 1; i <= N; i++){
    //   bool flag2 = true;
    //   for (std::set<std::pair<int, int> >::iterator it=pairs.begin(); it!=pairs.end(); ++it) {
    //     if(it -> first != i && it -> second != i){
    //       flag2 = false;
    //       break;
    //     }
    //   }
    //   if(flag2){
    //     flag = true;
    //     break;
    //   }
    // }
    //

    int num_pairs = pairs.size();
    if(N == 1 && num_pairs == 0) printf("YES\n");
    else if(N == 2 && num_pairs == 0) printf("YES\n");
    else if(N == 3 && num_pairs <= 2) printf("YES\n");
    else printf("NO\n");

    pairs.clear();
  }
}
