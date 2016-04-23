#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
#include <map>

using namespace std;

multiset<int> A;
set<int> G[1000001];
bool sieve[2000001];

int main() {
  memset(sieve, true, sizeof sieve);
  sieve[0] = sieve[1] = false;
  for(int i = 2; i <= 2000000; i++) {
    if(!sieve[i]) continue;

    for(int j = i + i; j <= 2000000; j += i) {
      sieve[j] = false;
    }
  }

  int N; cin >> N;

  int one_cnt = 0;
  set<int> rest;
  for(int i = 1; i <= N; i++) {
    int x; cin >> x;
    if(x == 1) one_cnt++;
    else rest.insert(x);
  }

  multiset<int> ans1;
  for(int i = 0; i < one_cnt; i++) {
    ans1.insert(1);
  }
  for(auto it: rest) {
    if(sieve[it + 1]) {
      ans1.insert(it);
      break;
    }
  }

  for(auto it: rest) A.insert(it);
  N = A.size();

  for(auto it: A) {
    for(auto it2: A) {
      if(it == it2) continue;
      if(sieve[it + it2]) continue;
      if(it > it2) continue;

      G[it].insert(it2);
      G[it2].insert(it);
    }
  }

  while(true) {
    int sum = 0;
    for(auto it: A) {
      sum += G[it].size();
    }
    if(sum == 0) break;

    int max_conn = 0, max_el = 0;
    for(auto it: A) {
      if(G[it].size() > max_conn) {
        max_conn = G[it].size();
        max_el = it;
      }
    }

    for(auto it: G[max_el]) {
      G[it].erase(max_el);
    }
    G[max_el].clear();
    A.erase(max_el);
  }

  if(ans1.size() > A.size()) A = ans1;

  cout << A.size() << endl;
  for(auto it: A) cout << it << " ";
  cout << endl;
}
