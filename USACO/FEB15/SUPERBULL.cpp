// Superbull

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

int vals[2000][2000];
vector<pair<int, pair<int, int> > > matches;
unordered_map<int, set<int> > played;
set<int> current;

bool sort_compare(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
  return a.first > b.first;
}

int main() {
  freopen("superbull.in", "r", stdin);
  freopen("superbull.out", "w", stdout);

  int N; scanf("%d", &N);
  int teams[N];
  for(int i = 0; i < N; i++) {
    scanf("%d", &teams[i]);
    current.insert(teams[i]);
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      vals[i][j] = teams[i] ^ teams[j];
      if(i >= j) vals[i][j] = 0;
      if(vals[i][j] > 0) {
        matches.push_back({vals[i][j], {i, j}});
      }
    }
  }

  sort(matches.begin(), matches.end(), sort_compare);

  long long total_score = 0;
  for(int i = 0; i < (N - 1); i++){
    if(played[matches[i].second.first].empty() && played[matches[i].second.second].empty()){
      total_score += matches[i].first;
    }
    else if(played[matches[i].second.first].size() > 0){
      played[matches[i].second.first].insert(matches[i].second.second);
      for(auto c: played[matches[i].second.first]) current.erase(c);
      total_score += matches[i].first;
    }
    else if(played[matches[i].second.second].size() > 0){
      played[matches[i].second.second].insert(matches[i].second.first);
      for(auto c: played[matches[i].second.second]) current.erase(c);
      total_score += matches[i].first;
    }
  }

  printf("%lld\n", total_score);

  fclose(stdin);
  fclose(stdout);
}
