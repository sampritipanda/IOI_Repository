// Xor Matrix

#include <iostream>

using namespace std;

unsigned long long L, R;

#define MOD 1000000007

unsigned long long dfs1(unsigned long long i, unsigned long long j, unsigned long long grid[500][500], unsigned long long curr){
  if(grid[i - L][j - L] != curr) return 0;
  if(i < L || i > R || j < L || j > R) return 0;

  unsigned long long curr_max = 0;
  curr_max = max(curr_max, dfs1(i + 1, j, grid, curr + 1));
  curr_max = max(curr_max, dfs1(i - 1, j, grid, curr + 1));
  curr_max = max(curr_max, dfs1(i, j + 1, grid, curr + 1));
  curr_max = max(curr_max, dfs1(i, j - 1, grid, curr + 1));

  return curr_max + 1;
}

unsigned long long dfs2(unsigned long long i, unsigned long long j, unsigned long long grid[500][500], unsigned long long K, unsigned long long curr){
  if(grid[i - L][j - L] != curr) return 0;
  if(i < L || i > R || j < L || j > R) return 0;

  if(curr == K) return 1;

  unsigned long long sum = 0;
  sum += dfs2(i + 1, j, grid, K, curr + 1);
  sum %= MOD;
  sum += dfs2(i - 1, j, grid, K, curr + 1);
  sum %= MOD;
  sum += dfs2(i, j + 1, grid, K, curr + 1);
  sum %= MOD;
  sum += dfs2(i, j - 1, grid, K, curr + 1);
  sum %= MOD;

  return sum;
}

int main() {
  int T; cin >> T;

  while(T--){
    cin >> L >> R;
    unsigned long long N = R - L + 1;
    unsigned long long grid[500][500];
    for(unsigned long long i = L; i <= R; i++){
      for(unsigned long long j = L; j <= R; j++){
        grid[i - L][j - L] = i ^ j;
      }
    }

    unsigned long long longest_walk = 0;
    for(unsigned long long i = L; i <= R; i++){
      for(unsigned long long j = L; j <= R; j++){
        if(grid[i - L][j - L] == 0){
          longest_walk = max(longest_walk, dfs1(i, j, grid, 0) - 1);
        }
      }
    }

    unsigned long long C = 0;
    for(unsigned long long i = L; i <= R; i++){
      for(unsigned long long j = L; j <= R; j++){
        if(grid[i - L][j - L] == 0){
          C += dfs2(i, j, grid, longest_walk, 0);
          C %= MOD;
        }
      }
    }

    cout << longest_walk << " " << C << endl;
    for(unsigned long long i = L; i <= R; i++){
      for(unsigned long long j = L; j <= R; j++){
        cout << grid[i - L][j - L] << " \n"[j == R];
      }
    }
  }
}
