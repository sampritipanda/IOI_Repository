#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// PQ[i] = PQ for slope i, {start severity}
priority_queue<int> PQ[101];

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    for(int i = 0; i <= 100; i++) {
      while(!PQ[i].empty()) {
        PQ[i].pop();
      }
    }

    int N; scanf("%d", &N);

    while(N--) {
      char t; scanf(" %c", &t);

      if(t == 'P') {
        int t0, s0, r; scanf(" %d %d %d", &t0, &s0, &r);
        PQ[r].push(s0 - (t0 * r));
      }
      else {
        int t; scanf(" %d", &t);
        int s = -1, r = -1;
        for(int i = 100; i >= 0; i--) {
          if(PQ[i].empty()) continue;

          int s0 = PQ[i].top();
          int curr_s = s0 + i * t;

          if(curr_s > s) {
            s = curr_s;
            r = i;
          }
        }

        printf("%d %d\n", s, r);
        PQ[r].pop();
      }
    }
  }
}
