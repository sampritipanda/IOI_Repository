// Candidate walk

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<unsigned long long, long long> memo;

unsigned long long find_hash(vector<int>& curr){
  unsigned long long mod = 1e9 + 7, lx = 1, hash = 0;
  for(auto it: curr){
    hash += it * lx;
    lx *= mod;
  }
  return hash;
}

bool is_end(vector<int>& curr, int D){
  bool flag = true;
  for(auto it: curr){
    if(it != D - 1){
      flag = false;
      break;
    }
  }
  return flag;
}

long long find_sum(vector<int>& curr){
  long long sum = 0;
  for(auto it: curr){
    sum += it;
  }

  return sum;
}

long long find_value(vector<int>& curr){
  long long xor_sum = 0;
  for(auto it: curr){
    xor_sum ^= it;
  }

  return find_sum(curr) * xor_sum;
}

long long dfs(vector<int> curr, int N, int D){
  unsigned long long hash = find_hash(curr);

  if(memo.count(hash) > 0) {
    return memo[hash];
  }

  if(is_end(curr, D)){
    return find_value(curr);
  }

  long long min_num = -1;
  for(int i = 0; i < N; i++){
    if(curr[i] + 1 < D){
      curr[i]++;
      long long next_val = dfs(curr, N, D);
      curr[i]--;
      if(min_num == -1 || next_val < min_num) min_num = next_val;
    }
  }

  long long ans = min_num + find_value(curr);
  memo[hash] = ans;
  return ans;
}

int main() {
  int T; cin >> T;

  while(T--){
    int N, D; cin >> N >> D;
    vector<int> start(N, 0);
    cout << dfs(start, N, D) << endl;
    memo.clear();
  }
}
