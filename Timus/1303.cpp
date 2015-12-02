#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

vector<pair<int, int> > pairs;
vector<vector<pair<int, int> > > A;
vector<long long> dp;
vector<pair<int, int> > best;
vector<pair<int, int> > ans;

int main()
{
    int M; cin >> M;
    A.resize(M + 1);
    dp.resize(M + 1, INT_MAX);
    best.resize(M + 1, {0, 0});

    while(true) {
        int x, y; cin >> x >> y;
        if(x == 0 && y == 0) break;
        pairs.push_back({x, y});
    }

    int N = pairs.size();
    for(int i = 0; i < N; i++) {
        int x = pairs[i].first, y = pairs[i].second;
        if((x < 0 && y < 0) || (x > M && y > M) || x > y) continue;
        if(x < 0) x = 0;
        if(y > M) y = M;
        A[y].push_back({x, i});
    }

    for(int i = 0; i <= M; i++) {
        for(auto it: A[i]) {
            int j = it.first;
            for(int k = j; k <= i; k++) {
                if(k == 0) {
                  if(1LL < dp[i]) {
                    dp[i] = 1; best[i] = {-1, it.second};
                  }
                }
                else {
                  if(1 + dp[k] < dp[i]) {
                    dp[i] = 1 + dp[k]; best[i] = {k, it.second};
                  }
                }
            }
        }
    }

    //cout << dp[M] << endl;
    if(dp[M] == INT_MAX) cout << "No solution" << endl;
    else {
      pair<int, int> curr = best[M];
      while(true) {
        ans.push_back(pairs[curr.second]);
        if(curr.first == -1) break;
        else curr = best[curr.first];
      }

      sort(ans.begin(), ans.end());
      cout << ans.size() << endl;
      for(auto it: ans) cout << it.first << " " << it.second << endl;
    }

    return 0;
}
