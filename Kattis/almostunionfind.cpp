// Almost Union Find

#include <iostream>
#include <set>
#include <cassert>

using namespace std;

int union_find[100010];
set<int> children[100010];
int sizes[100010];
int sum[100010];

void check_validness(int i) {
  assert(sizes[i] >= 0);
  assert(sum[i] >= 0);

  if(sizes[i] > 0) assert(sum[i] >= i);
}

int find(int i) {
  if(i == union_find[i]) return i;

  int new_parent = find(union_find[i]);
  if(new_parent != union_find[i]) {
    children[union_find[i]].erase(i);
    children[new_parent].insert(i);
  }
  union_find[i] = new_parent;
  return union_find[i];
}

void merge_set(int a, int b) {
  a = find(a);
  b = find(b);
  if(a != b) {
    union_find[a] = b;
    children[b].insert(a);
    sizes[b] += sizes[a];
    sizes[a] = 0;
    sum[b] += sum[a];
    sum[a] = 0;
  }

  check_validness(b);
}

void move_set(int p, int q) {
  q = find(q);
  if(find(p) == q) return;

  if(union_find[p] == p) {
    if(!children[p].empty()) {
      auto it = children[p].begin();
      int leader = *it; union_find[leader] = leader;
      while(++it != children[p].end()) {
        union_find[*it] = leader;
        children[leader].insert(*it);
      }
      sizes[leader] = sizes[p] - 1;;
      sum[leader] = sum[p] - p;

      check_validness(leader);
    }
  }
  else {
    int leader = union_find[p];
    children[leader].erase(p);
    for(auto it: children[p]) {
      children[leader].insert(it);
      union_find[it] = leader;
    }
    sizes[find(leader)]--;
    sum[find(leader)] -= p;

    check_validness(find(leader));
  }

  union_find[p] = p;
  children[p].clear();
  sizes[p] = 1;
  sum[p] = p;

  merge_set(p, q);
}

int main() {
  int N, M; cin >> N >> M;

  while(!cin.eof()) {
    for(int i = 1; i <= N; i++) {
      union_find[i] = i;
      sizes[i] = 1;
      sum[i] = i;
      children[i].clear();
    }

    while(M--) {
      int type; cin >> type;

      if(type == 1) {
        int p, q; cin >> p >> q;
        merge_set(p, q);
      }
      else if (type == 2) {
        int p, q; cin >> p >> q;
        move_set(p, q);
      }
      else {
        int p; cin >> p;
        cout << sizes[find(p)] << " " << sum[find(p)] << endl;
      }
    }

    cin >> N >> M;
  }
}
