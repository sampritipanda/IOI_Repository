// Chef and Red Black Tree

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

inline int lg(int a){
  return floor(log(a)/log(2));
}

void sort(int* x, int* y){
  if(*x > *y){
    int temp = *x;
    *x = *y;
    *y = temp;
  }
}

int getLargestCommonAncestor(int x, int y){
  if(x == 1 || y == 1) return 1;
  std::vector<int> ancestors_x;
  std::vector<int> ancestors_y;
  std::vector<int> ancestors_common(30);

  ancestors_x.push_back(x);
  while(x > 1){
    x /= 2;
    ancestors_x.push_back(x);
  }

  ancestors_y.push_back(y);
  while(y > 1){
    y /= 2;
    ancestors_y.push_back(y);
  }
  std::sort(ancestors_x.begin(), ancestors_x.end());
  std::sort(ancestors_y.begin(), ancestors_y.end());
  std::vector<int>::iterator it = std::set_intersection(ancestors_x.begin(), ancestors_x.end(), ancestors_y.begin(), ancestors_y.end(), ancestors_common.begin());
  ancestors_common.resize(it - ancestors_common.begin());
  return ancestors_common.back();
}

int main(){
  int Q; scanf("%d", &Q);
  char command[3];
  bool default_order = true;
  int x, y;

  while(Q--){
    scanf("%s ", command);
    int common_ancestor, count = 0;

    if(command[0] == 'Q' && command[1] == 'i'){
      default_order = !default_order;
    }
    else if(command[0] == 'Q' && command[1] == 'b'){
      scanf("%d %d", &x, &y);
      sort(&x, &y);
      common_ancestor = getLargestCommonAncestor(x, y);
      if((lg(x) % 2 == 0 && default_order) || (lg(x) % 2 == 1 && !default_order)) count++;

      if(x != y){
        if((lg(y) % 2 == 0 && default_order) || (lg(y) % 2 == 1 && !default_order)) count++;
        if(common_ancestor != x && common_ancestor != y) {
          if((lg(common_ancestor) % 2 == 0 && default_order) || (lg(common_ancestor) % 2 == 1 && !default_order)) count++;
        }
        while(x /= 2){
          if(x <= common_ancestor) break;
          if((lg(x) % 2 == 0 && default_order) || (lg(x) % 2 == 1 && !default_order)) count++;
        }
        while(y /= 2){
          if(y <= common_ancestor) break;
          if((lg(y) % 2 == 0 && default_order) || (lg(y) % 2 == 1 && !default_order)) count++;
        }
      }
      printf("%d\n", count);
    }
    else if(command[0] == 'Q' && command[1] == 'r'){
      scanf("%d %d", &x, &y);
      sort(&x, &y);
      common_ancestor = getLargestCommonAncestor(x, y);
      if((lg(x) % 2 == 1 && default_order) || (lg(x) % 2 == 0 && !default_order)) count++;

      if(x != y){
        if((lg(y) % 2 == 1 && default_order) || (lg(y) % 2 == 0 && !default_order)) count++;
        if(common_ancestor != x && common_ancestor != y) {
          if((lg(common_ancestor) % 2 == 1 && default_order) || (lg(common_ancestor) % 2 == 0 && !default_order)) count++;
        }
        while(x /= 2){
          if(x <= common_ancestor) break;
          if((lg(x) % 2 == 1 && default_order) || (lg(x) % 2 == 0 && !default_order)) count++;
        }
        while(y /= 2){
          if(y <= common_ancestor) break;
          if((lg(y) % 2 == 1 && default_order) || (lg(y) % 2 == 0 && !default_order)) count++;
        }
      }
      printf("%d\n", count);
    }
    else{
    }
  }
}
