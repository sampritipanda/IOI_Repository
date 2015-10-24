// Special Vertex

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

vector<int> tree[1000001];
vector<int> node_list;
int memo[1000001];
int N;

int mv_count = 0;

int move(int curr) {
  if(memo[curr] != -1) return memo[curr];

  assert(mv_count < 33);
  assert(curr >= 1 && curr <= N);

  printf("%d\n", curr);
  fflush(stdout);
  scanf("%d", &memo[curr]);
  mv_count++;
  return memo[curr];
}

pair<int, int> find_end_of_chain(int curr, int previous) {
  if(tree[curr].size() == 1) return {curr, previous};
  else if(tree[curr].size() > 2) return {previous, curr};

  if(tree[curr][0] == previous) find_end_of_chain(tree[curr][1], curr);
  else find_end_of_chain(tree[curr][0], curr);
}

void create_node_list(int curr, int previous, int R) {
  node_list.push_back(curr);
  if(curr == R) return;

  if(tree[curr][0] == previous) create_node_list(tree[curr][1], curr, R);
  else create_node_list(tree[curr][0], curr, R);
}

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) memo[i] = -1;

  for(int i = 0; i < N - 1; i++) {
    int u, v; scanf("%d %d", &u, &v);
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> node(1, N);

  int curr = node(mt);
  int previous = -1;

  while(true) {
    if(curr == 0) break;

    if(tree[curr].size() == 1) previous = curr, curr = move(curr);
    else if(tree[curr].size() == 2) {
      if(previous == -1) {
        previous = curr;
        curr = move(curr);
      }
      else {
        int L = curr, L_previous = previous;
        auto chain_end = find_end_of_chain(curr, previous);
        int R = chain_end.first;
        int R_previous = chain_end.second;

        if(L == R) {
          curr = move(curr);
        }
        else {
          int R_next = move(R);
          if(R_next != R_previous) {
            if(R_next == 0) curr = 0;
            else curr = R_next;
          }
          else {
            node_list.clear();
            create_node_list(L, L_previous, R);

            int a = 0, b = N - 1;
            while(a <= b && curr != 0) {
              int mid = a + (b - a)/2;
              int result = move(node_list[mid]);

              if(result == 0) {
                curr = 0;
              }
              else {
                if(result == node_list[mid - 1]) b = mid - 1;
                else a = mid + 1;
              }
            }
          }
        }
      }
    }
    else {
      previous = curr;
      curr = move(curr);
    }
  }

  assert(curr == 0);
}
