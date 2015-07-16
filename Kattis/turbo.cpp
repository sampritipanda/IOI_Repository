// Turbo

#include <iostream>
#include <algorithm>
#include <utility>
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

int A[100010], pos[100010];

int main() {
  ordered_set X;
  int N; cin >> N;

  for(int i = 1; i <= N; i++) {
    cin >> A[i];
    pos[A[i]] = i;
    X.insert({i, A[i]});
  }

  int smallest = 1, largest = N;
  int curr_size = N;
  for(int phase = 1; phase <= N; phase++) {
    if(phase & 1) {
      cout << X.order_of_key({pos[smallest], smallest}) << endl;
      X.erase({pos[smallest], smallest});
      smallest++;
    }
    else {
      cout << curr_size - (X.order_of_key({pos[largest], largest}) + 1) << endl;
      X.erase({pos[largest], largest});
      largest--;
    }
    curr_size--;
  }
}
