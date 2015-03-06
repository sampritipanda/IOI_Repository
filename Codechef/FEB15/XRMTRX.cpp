// Xor Matrix

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

unsigned long long L, R;

#define MOD 1000000007

struct node {
  unsigned long long x, y, curr_dist = 0;
  long long num_ways = 1;
};

int main() {
  int T; scanf("%d", &T);

  while(T--){
    scanf("%llu %llu", &L, &R);
    unsigned long long N = R - L + 1;

    if(N <= 301) {
      long long dist[N][N], ways[N][N];
      bool visited[N][N];
      for(long long i = 0; i < N; i++){
        for(long long j = 0; j < N; j++){
          dist[i][j] = -1;
          ways[i][j] = 0;
          visited[i][j] = false;
        }
      }

      queue<node> Q;
      for(unsigned long long i = 0; i < N; i++){
        node N; N.x = i + L; N.y = i + L;
        Q.push(N);
      }

      while(!Q.empty()){
        node curr = Q.front();
        Q.pop();

        if((curr.x ^ curr.y) != curr.curr_dist) continue;
        ways[curr.x - L][curr.y - L] = (ways[curr.x - L][curr.y - L] + 1) % MOD;
        if(visited[curr.x - L][curr.y - L]) continue;

        visited[curr.x - L][curr.y - L] = true;
        dist[curr.x - L][curr.y - L] = curr.curr_dist;

        if(curr.x < R){
          node N; N.x = curr.x + 1; N.y = curr.y; N.curr_dist = curr.curr_dist + 1;
          Q.push(N);
        }
        if(curr.x > L){
          node N; N.x = curr.x - 1; N.y = curr.y; N.curr_dist = curr.curr_dist + 1;
          Q.push(N);
        }
        if(curr.y < R){
          node N; N.x = curr.x; N.y = curr.y + 1; N.curr_dist = curr.curr_dist + 1;
          Q.push(N);
        }
        if(curr.y > L){
          node N; N.x = curr.x; N.y = curr.y - 1; N.curr_dist = curr.curr_dist + 1;
          Q.push(N);
        }
      }

      long long K = -1, C = 0;
      for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
          K = max(K, dist[i][j]);
        }
      }

      for(unsigned long long i = 0; i < N; i++){
        node N; N.x = i + L; N.y = i + L;
        Q.push(N);
      }
      for(long long i = 0; i < N; i++){
        for(long long j = 0; j < N; j++){
          visited[i][j] = false;
        }
      }

      while(!Q.empty()){
        node curr = Q.front();
        Q.pop();

        if((curr.x ^ curr.y) != curr.curr_dist) continue;
        if(visited[curr.x - L][curr.y - L]) continue;

        visited[curr.x - L][curr.y - L] = true;
        curr.num_ways = (curr.num_ways * ways[curr.x - L][curr.y - L]) % MOD;
        if(curr.curr_dist == K) {
          C += curr.num_ways;
          C %= MOD;
          continue;
        }

        if(curr.x < R){
          node N; N.x = curr.x + 1; N.y = curr.y; N.curr_dist = curr.curr_dist + 1; N.num_ways = curr.num_ways;
          Q.push(N);
        }
        if(curr.x > L){
          node N; N.x = curr.x - 1; N.y = curr.y; N.curr_dist = curr.curr_dist + 1; N.num_ways = curr.num_ways;
          Q.push(N);
        }
        if(curr.y < R){
          node N; N.x = curr.x; N.y = curr.y + 1; N.curr_dist = curr.curr_dist + 1; N.num_ways = curr.num_ways;
          Q.push(N);
        }
        if(curr.y > L){
          node N; N.x = curr.x; N.y = curr.y - 1; N.curr_dist = curr.curr_dist + 1; N.num_ways = curr.num_ways;
          Q.push(N);
        }
      }

      for(long long i = 0; i < N; i++){
        for(long long j = 0; j < N; j++){
          // printf("%lld%c", dist[i][j], " \n"[j == N - 1]);
        }
      }

      printf("%lld %lld\n", K, 0);
    }
    else {
      unsigned long long K = 0, C = 0;
      unsigned long long curr = pow(2, floor(log2(R)) + 1), count = 0;
      for(; curr >= 1; curr /= 2){
        double a = (L+1)/double(curr/2), b = R/double(curr/2);
        unsigned long long ceil_a  = ceil(a), ceil_b = ceil(b);
        bool flag = false;
        for(unsigned long long t = ceil_a; t <= b; t++){
          if(t > b) break;
          if(t & 1){
            flag = true;
            break;
          }
        }
        if(flag) count++;

        if(count == 2 || (log2(L) == ceil(log2(L)) && (R < L*2) && count == 1) || (log2(R + 1) == ceil(log2(R + 1)) && count == 1) || (((L & R) == L) && count == 1)) break;
      }
      K = curr - 1;

      printf("%llu %llu\n", K, C);
    }
  }
}
