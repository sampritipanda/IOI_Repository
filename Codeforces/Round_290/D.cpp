// Fox And Jumping

#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int N;
int L[301], C[301];

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) cin >> L[i];
  for(int i = 0; i < N; i++) cin >> C[i];

  set<pair<int, int> > S;
  unordered_map<int, int> D;
  S.insert({0, 0});

  while(!S.empty()){
    auto top = S.begin();
    S.erase(S.begin());
    int cost = top.first, curr = top.second;
  }
}
