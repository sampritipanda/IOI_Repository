#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#include <vector>

using namespace std;

struct query {
  int a, t, x;
};

map<int, int> compres;
map<int, int> updates[100000];
int F[335][100000];
vector<query> queries;

int main() {
  int Q; scanf("%d", &Q);

  for(int i = 0; i < Q; i++) {
    int a, t, x; scanf("%d %d %d", &a, &t, &x);

    compres[t];
    queries.push_back({a, t, x});
  }
  int N = 0;
  for(auto it: compres) {
    compres[it.first] = N++;
  }
  for(int i = 0; i < Q; i++) {
    queries[i].t = compres[queries[i].t];
  }

  compres.clear();

  for(int i = 0; i < Q; i++) {
    compres[queries[i].x];
  }
  int M = 0;
  for(auto it: compres) {
    compres[it.first] = M++;
  }
  for(int i = 0; i < Q; i++) {
    queries[i].x = compres[queries[i].x];
  }

  int BLOCK_SIZE = 300;

  for(auto q: queries) {
    int a = q.a, t = q.t, x = q.x;

    if(a == 1 || a == 2) {
      int b_id = t/BLOCK_SIZE;
      int b_st = b_id * BLOCK_SIZE;
      while(b_st < N) {
        int b_en = b_st + BLOCK_SIZE - 1;
        if(a == 1) F[b_id][x]++;
        else F[b_id][x]--;

        if(b_st <= t) {
          if(a == 1)
            updates[t][x]++;
          else
            updates[t][x]--;
        }

        b_st += BLOCK_SIZE;
        b_id++;
      }
    }
    else {
      int b_id = t/BLOCK_SIZE;
      int b_st = b_id * BLOCK_SIZE;
      int ans = 0;

      if(b_id > 0) ans += F[b_id - 1][x];
      for(int i = b_st; i <= t; i++) {
        if(updates[i].count(x))
          ans += updates[i][x];
      }

      printf("%d\n", ans);
    }
  }
}
