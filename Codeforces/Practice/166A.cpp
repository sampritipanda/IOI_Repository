// Rank List

#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool sort_compare(pair<int, int> a, pair<int, int> b){
  if(a.first > b.first) return true;
  else if(a.first == b.first) return (a.second < b.second);
  else return false;
}

int main() {
  int N, K; scanf("%d %d", &N, &K);
  vector<pair<int, int> > teams;

  for(int i = 0; i < N; i++){
    int p, t; scanf("%d %d", &p, &t);
    teams.push_back(make_pair(p, t));
  }

  sort(teams.begin(), teams.end(), sort_compare);

  printf("%ld\n", count(teams.begin(), teams.end(), teams[K - 1]));
}

