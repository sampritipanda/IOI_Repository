#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solve(vector<int> A) {
  if(A.size() < 3) return A;

  vector<int> even, odd;
  for(int x: A) {
    if(x % 2 == 0) even.push_back(x/2);
    else odd.push_back(x/2);
  }
  even = solve(even);
  odd = solve(odd);

  vector<int> ans;

  for(int x: even) ans.push_back(2 * x);
  for(int x: odd) ans.push_back(2 * x + 1);

  return ans;
}

int main() {
  int N; cin >> N;
  vector<int> A;
  for(int i = 1; i <= N; i++) A.push_back(i);

  vector<int> ans = solve(A);
  for(int x: ans) cout << x << " ";
  cout << endl;
}
