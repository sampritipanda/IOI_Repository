// Amr and Chemistry

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>

using namespace std;

int A[100010];
set<pair<int, int> > values[100010];
int cost[200010];
long long test_sum[200010];

int main() {
  int N; cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];
  int max_value = *max_element(A + 1, A + N + 1);

  for(int i = 1; i <= N; i++) {
    int temp = A[i];
    int operations = 0;
    while(temp >= 0) {
      values[i].insert({temp, operations});
      temp /= 2;
      operations++;
      if(temp == 0) break;
    }
    temp = A[i], operations = 0;
    while(temp <= 2 * max_value) {
      values[i].insert({temp, operations});
      temp *= 2;
      operations++;
    }
  }

  for(int i = 0; i <= 200000; i++) cost[i] = 0;
  for(int i = 0; i <= 200000; i++) test_sum[i] = 0;

  for(int i = 1; i <= N; i++) {
    for(auto j: values[i]) {
      cost[j.first] += j.second;
      test_sum[j.first] += i;
    }
  }

  int min_cost = INT_MAX;
  for(int i = 1; i <= 200000; i++) {
    if(test_sum[i] != ((long long)N * (N + 1))/2) continue;

    min_cost = min(min_cost, cost[i]);
  }
  cout << min_cost << endl;
}
