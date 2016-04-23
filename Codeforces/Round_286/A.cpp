// Mr. Kitayuta, the Treasure Hunter

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int islands[30001] = {0};
bool calculated[30001][500] = {0};
int memo[30001][500] = {0};
int N, d, last_island = 0;

long long solve(int curr, int l){
  int jump = d + l;
  if(curr > last_island || jump == 0) return 0;
  if(curr == last_island) return islands[curr];

  if(calculated[curr][l + 250]) return memo[curr][l + 250];

  calculated[curr][l + 250] = true;
  long long ans1 = 0, ans2 = 0, ans3 = 0;
  if(curr + jump - 1 <= last_island && jump > 1){
    ans1 = solve(curr + jump - 1, l - 1);
  }
  if(curr + l){
    ans2 = solve(curr + jump, l);
  }
  if(curr + l + 1 <= last_island){
    ans3 = solve(curr + jump + 1, l + 1);
  }
  long long ans = islands[curr] + max(ans1, max(ans2, ans3));
  memo[curr][l + 250] = ans;
  return ans;
}

int main() {
  cin >> N >> d;

  for(int i = 0; i < N; i++){
    int p; cin >> p;
    islands[p]++;
    if(p > last_island) last_island = p;
  }

  cout << solve(d, 0) << endl;
}
