// Vasya and Wrestling

#include <stdio.h>
#include <vector>

int main() {
  int N; scanf("%d", &N);
  int sum_first = 0, sum_second = 0;
  int a;
  std::vector<int> first, second;

  while(N--){
    scanf("%d", &a);
    if(a > 0){
      sum_first += a;
      first.push_back(a);
    }
    else {
      sum_second -= a;
      second.push_back(-a);
    }
  }

  if(sum_first > sum_second) printf("first\n");
  else if(sum_first < sum_second) printf("second\n");

  else {
    int len = std::min(first.size(), second.size());
    int comp = 0;
    for(int i = 0; i < len; i++){
      if(first[i] > second[i]){
        comp = 1;
        break;
      }
      else if(first[i] < second[i]){
        comp = -1;
        break;
      }
    }

    if(comp == 1) printf("first\n");
    else if(comp == -1) printf("second\n");

    else {
      if(first.size() > second.size()) printf("first\n");
      else if(first.size() < second.size()) printf("second\n");

      else {
        if(a > 0) printf("first\n");
        else if(a < 0) printf("second\n");
      }
    }
  }
}
