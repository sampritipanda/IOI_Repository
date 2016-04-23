#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
  int cnt = 0;
  node* children[2] = {NULL, NULL};
};

const int MAX_BIT = 29;
int A[1000001];
int P[1000001];
int K;

void insert(node* root, int X) {
  root->cnt++;
  for(int i = MAX_BIT; i >= 0; i--) {
    int bit = (X & (1 << i)) ? 1 : 0;
    if(root->children[bit] == NULL) {
      root->children[bit] = new node;
    }
    root = root->children[bit];
    root->cnt++;
  }
}

inline int count(node* root, int child=-1) {
  if(child == -1) return root->cnt;

  if(root->children[child] == NULL) return 0;
  return root->children[child]->cnt;
}

int search(node* root, int X) {
  int ans = 0;
  for(int i = MAX_BIT; i >= 0; i--) {
    if(K & (1 << i)) {  // => current bit NEEDS to be set
      if(X & (1 << i)) {  // => chosen bit will 0
        if(root->children[0] == NULL) return ans;
        root = root->children[0];
      }
      else {
        if(root->children[1] == NULL) return ans;
        root = root->children[1];
      }
    }
    else {  // => current bit may/may not be set
      if(X & (1 << i)) {
        ans += count(root, 0);
        if(root->children[1] == NULL) return ans;
        root = root->children[1];
      }
      else {
        ans += count(root, 1);
        if(root->children[0] == NULL) return ans;
        root = root->children[0];
      }
    }
  }

  ans += root->cnt;
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N >> K;
  for(int i = 1; i <= N; i++) cin >> A[i];

  for(int i = 1; i <= N; i++) P[i] = P[i - 1] ^ A[i];

  node* root = new node;

  long long ans = 0;
  for(int i = N; i >= 1; i--) {
    insert(root, P[i]);
    ans += search(root, P[i - 1]);
  }
  cout << ans << endl;
}
