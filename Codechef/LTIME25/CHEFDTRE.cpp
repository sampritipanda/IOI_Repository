// Chef and Sets

#include <iostream>
#include <map>
#include <string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>  tree_map_t;

map<int, tree_map_t> trees;
map<int, int> index_map;

int main() {
  tree_map_t* blank = new tree_map_t;

  int N, Q; cin >> N >> Q;
  int curr_index = N + 1;

  while(Q--) {
    string type; int a, b; cin >> type >> a >> b;

    if(type == "UNION") {
      if(a <= N && b <= N) {
        trees[curr_index].insert(a);
        trees[curr_index].insert(b);

        index_map[curr_index] = curr_index;
      }
      else if(a <= N) {
        index_map[curr_index] = b;
        trees[index_map[b]].insert(a);
      }
      else if(b <= N) {
        index_map[curr_index] = a;
        trees[index_map[a]].insert(b);
      }
      else {
        index_map[curr_index] = a;

        trees[index_map[a]].join(trees[index_map[b]]);
      }

      curr_index++;
    }
    else {
      if(a > N) {
        cout << *trees[index_map[a]].find_by_order(b - 1) << endl;
      }
      else {
        cout << a << endl;
      }
    }
  }
}
