#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int S[500001];
int Q[500001];
vector<pair<double, int> > U;
priority_queue<pair<double, int> > chosen;
bool A[500001];

int main() {
  int N; double W; scanf("%d %lf", &N, &W);
  W += 1e-6;

  for(int i = 1; i <= N; i++) {
    scanf("%d %d", &S[i], &Q[i]);
    U.push_back({S[i]/double(Q[i]), i});
  }

  sort(U.begin(), U.end());

  double Q_sum = 0.0;
  double min_cost = 1e11;
  int max_size = 0;
  int chosen_i = -1;

  for(int i = 0; i < N; i++) {
    int j = U[i].second;
    chosen.push({Q[j], j});
    Q_sum += Q[j];

    bool current_popped = false;

    while(Q_sum * U[i].first > W) {
      if(chosen.top().second == j) current_popped = true;
      Q_sum -= chosen.top().first;
      chosen.pop();
    }

    if(!current_popped) {
      if(chosen.size() > max_size || (chosen.size() == max_size && (Q_sum * U[i].first < min_cost))) {
        max_size = chosen.size();
        min_cost = Q_sum * U[i].first;
        chosen_i = i;
      }
    }
  }

  while(!chosen.empty()) chosen.pop();

  Q_sum = 0.0;
  for(int i = 0; i <= chosen_i; i++) {
    int j = U[i].second;
    chosen.push({Q[j], j});
    A[j] = true;
    Q_sum += Q[j];
  }
  while(Q_sum * U[chosen_i].first > W) {
    Q_sum -= chosen.top().first;
    A[chosen.top().second] = false;
    chosen.pop();
  }

  printf("%d\n", max_size);
  for(int i = 1; i <= N; i++) {
    if(A[i]) printf("%d\n", i);
  }
}
