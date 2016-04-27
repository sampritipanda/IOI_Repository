#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool valid[2001]; // Does Police not contain any other police inside
vector<int> vis[2001];   // Police who visit this Hideout
bool uniq[2001];  // Does Policeman have point not visited by anyone else
bool processed[2001];
vector<int> r_vis[2001];

long long criminalEstimate(int N, int M, int* A, int* B) {
  for(int i = 0; i <= 2000; i++) {
    valid[i] = true;
    vis[i].clear();
    r_vis[i].clear();
    uniq[i] = false;
  }

  for(int i = 0; i < M; i++) {
    for(int j = A[i]; j <= B[i]; j++) {
      vis[j].push_back(i);
    }
  }

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < M; j++) {
      if(j == i) continue;

      if(A[i] <= A[j] && B[j] <= B[i]) {
        valid[i] = false;
        break;
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    r_vis[vis[i].size()].push_back(i);
  }

  int ans = 0;
  for(int cnt = 0; cnt <= N; cnt++) {
    for(int i: r_vis[cnt]) {
      bool pos = true, valid_exist = false;
      for(int j: vis[i]) {
        if(valid[j]) valid_exist = true;
        if(valid[j] && processed[j]) {
          pos = false;
          break;
        }
      }
      if(pos && valid_exist) {
        ans++;
        for(int j: vis[i]) {
          processed[j] = true;
        }
      }
    }
  }

  for(int i = 0; i < M; i++) {
    if(valid[i] && !processed[i]) return -1;
  }

  return ans;
}
