// Cookie Selection

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
  pair<int, int>,
  null_type,
  less<pair<int, int> >,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

int main() {
  ordered_set X;

  char str[20];
  int set_size = 0;
  int timer = 0;
  while(scanf("%s", str) != EOF){
    if(str[0] == '#') {
      pair<int, int> output = (set_size & 1) ? (*X.find_by_order((set_size + 1)/2 - 1)) : (*X.find_by_order(set_size/2));
      printf("%d\n", output.first);
      X.erase(output);

      set_size--;
    }
    else {
      int d = atoi(str);
      X.insert({d, timer++});
      set_size++;
    }
  }
}
