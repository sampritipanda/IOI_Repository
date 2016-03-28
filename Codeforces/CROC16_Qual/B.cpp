#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>

using namespace std;

queue<vector<long long> > queries;  // entry time, duration, query_id
deque<vector<long long> > Q;        // start time (-1 = unstarted) , duration, query_id
vector<long long> ans;
set<long long> times;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N, B; cin >> N >> B; B++;
  ans.resize(N);

  for(int i = 0; i < N; i++) {
    int t, d; cin >> t >> d;

    queries.push({t, d, i});
    times.insert(t);
  }

  while(times.size() > 0) {
    long long t = *times.begin(); times.erase(times.begin());

    if(Q.size() > 0) {
      if(t == Q.front()[0] + Q.front()[1]) {
        ans[Q.front()[2]] = Q.front()[0] + Q.front()[1];
        Q.pop_front();
      }
    }

    if(Q.size() > 0 && Q.front()[0] == -1) {
      auto it = Q.front(); Q.pop_front();
      it[0] = t;
      Q.push_front(it);
      times.insert(it[0] + it[1]);
    }

    if(queries.size() > 0 && t == queries.front()[0]) {
      if(Q.size() >= B) {
        ans[queries.front()[2]] = -1;
      }
      else {
        Q.push_back({-1, queries.front()[1], queries.front()[2]});
      }
      queries.pop();
    }

    if(Q.size() > 0 && Q.front()[0] == -1) {
      auto it = Q.front(); Q.pop_front();
      it[0] = t;
      Q.push_front(it);
      times.insert(it[0] + it[1]);
    }
  }

  for(int i = 0; i < N; i++) cout << ans[i] << " "; cout << endl;
}
