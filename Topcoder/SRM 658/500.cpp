// Mutalisk Easy

#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<unsigned long long, int> memo;

unsigned long long find_hash(vector<int>& curr){
  unsigned long long mod = 1e9 + 7, lx = 1, hash = 0;
  for(auto it: curr){
      hash += it * lx;
      lx *= mod;
    }
  return hash;
}

vector<int> filter(vector<int> x){
  vector<int> filtered;
  for(auto it: x){
    if(it > 0) filtered.push_back(it);
  }
  return filtered;
}

int solve(vector<int> x){
  if(memo.find(find_hash(x)) != memo.end()) return memo[find_hash(x)];

  int ans = INT_MAX;
  if(x.size() == 0) ans = 0;
  else if(x.size() == 1){
    ans = 1 + solve(filter({x[0] - 9}));
  }
  else if(x.size() == 2){
    ans = min(ans, 1 + solve(filter({x[0] - 9, x[1] - 3})));
    ans = min(ans, 1 + solve(filter({x[0] - 3, x[1] - 9})));
  }
  else if(x.size() == 3){
    // 1 2 3, 1 3 2, 2 3 1, 2 1 3, 3 1 2, 3 2 1
    ans = min(ans, 1 + solve(filter({x[0] - 9, x[1] - 3, x[2] - 1})));
    ans = min(ans, 1 + solve(filter({x[0] - 9, x[1] - 1, x[2] - 3})));
    ans = min(ans, 1 + solve(filter({x[0] - 3, x[1] - 1, x[2] - 9})));
    ans = min(ans, 1 + solve(filter({x[0] - 3, x[1] - 9, x[2] - 1})));
    ans = min(ans, 1 + solve(filter({x[0] - 1, x[1] - 9, x[2] - 3})));
    ans = min(ans, 1 + solve(filter({x[0] - 1, x[1] - 3, x[2] - 9})));
  }

  memo[find_hash(x)] = ans;
  return ans;
}

class MutaliskEasy {
  public:
  int minimalAttacks(vector <int> x) {
    memo.clear();
    return solve(x);
  }
};

int main() {
  MutaliskEasy test;
  cout << test.minimalAttacks({55,60,53}) << endl;
}
