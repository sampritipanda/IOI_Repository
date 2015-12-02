#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

struct node {
  int i;
  node* L = NULL;
  node* R = NULL;
};

long long dp[100001], size[100001];

void insert(node* root, int a) {
  if(a < root->i) {
    if(root->L != NULL) insert(root->L, a);
    else {
      root->L = new node;
      root->L->i = a;
      return;
    }
  }
  else {
    if(root->R != NULL) insert(root->R, a);
    else {
      root->R = new node;
      root->R->i = a;
      return;
    }
  }
}

void recur(node* root) {
  int i = root->i;
  size[i] = 1;
  if(root->L != NULL) {
    recur(root->L);
    size[i] += size[root->L->i];
  }
  if(root->R != NULL) {
    recur(root->R);
    size[i] += size[root->R->i];
  }

  if(size[i] == 1) dp[i] = 1;
  else if(root->L == NULL) dp[i] = dp[root->R->i];
  else if(root->R == NULL) dp[i] = dp[root->L->i];
  else {
    dp[i] = (dp[root->L->i] * dp[root->R->i]) % MOD;
    dp[i] = (dp[i] * 2) % MOD;
  }
}

int main() {
  ios::sync_with_stdio(false);
  node* root = new node;

  int N; cin >> N;
  int a; cin >> a;
  root->i = a;

  for(int i = 2; i <= N; i++) {
    cin >> a;
    insert(root, a);
  }

  for(int i = 0; i <= N; i++) dp[i] = size[i] = 0;

  recur(root);
  cout << dp[root->i] << endl;
}
