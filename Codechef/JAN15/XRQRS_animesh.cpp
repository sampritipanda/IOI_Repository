#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000009
#define mbrc goldmedalist16
#define pb push_back
#define mp make_pair
#define ll long long
#define NMAX  500050
#define LN    19

using namespace std;

int res = 0;
vector<int> A;
int curr_index = -1, L = -1, R = -1;

struct trie{
  int left[NMAX];  // Left child is 0
  int right[NMAX]; // Right Child is 1
  set<int> indexes[NMAX * 20];
  int cur;
  trie(){
    cur = 1;
    for(int i = 0 ; i < NMAX ; i++) left[i] = right[i] = -1;
  }
  // We always traverse from most significant bit to least significant bit
  void insert(int val , int node , int i){
    if(i==-1)return;
    if(val & (1 << i)){ // If current bit is 1
      if (right[node] == -1) right[node] = cur++; // If right child is vacant , fill it
      indexes[node].insert(curr_index);
      insert(val,right[node],i-1);
    }
    else{  // Current bit is 0
      if(left[node] == -1)  left[node] = cur++; // If left child is vacant , fill it
      indexes[node].insert(curr_index);
      insert(val,left[node],i-1);
    }
  }

  void query(int val , int node , int i){
    if(i==-1)return;
    if(val & (1 << i)){ // If current bit is 1 , we will try to assign a 0
      if(left[node] == -1 || (i > 0 && indexes[left[node]].lower_bound(L) == indexes[left[node]].upper_bound(R))) {
        node = right[node];
        res |= 1 << i;
      }
      else node = left[node];
      query(val,node,i-1);
    }
    else{ // If current bit is 0 we will try to assign a 1
      if(right[node] == -1 || (i > 0 && indexes[right[node]].lower_bound(L) == indexes[right[node]].upper_bound(R))) node = left[node];
      else {
        node = right[node];
        res |= 1 << i;
      }
      query(val,node,i-1);
    }
  }

  void remove(int val, int node, int i) {
    if(i==-1)return;
    if(val & (1 << i)){ // If current bit is 1
      indexes[node].erase(curr_index);
      insert(val,right[node],i-1);
      if(indexes[node].size() == 0) right[node] = -1;
    }
    else{  // Current bit is 0
      indexes[node].erase(curr_index);
      insert(val,left[node],i-1);
      if(indexes[node].size() == 0) left[node] = -1;
    }

  }

} segTrie;

int main(){
  int M; scanf("%d",&M);

  while(M--) {
    int type; scanf("%d", &type);

    if(type == 0) {
      int x; scanf("%d", &x);
      A.push_back(x);
      curr_index = A.size() - 1;
      segTrie.insert(x, 0, LN);
    }
    else if(type == 1) {
      int x; scanf("%d %d %d", &L, &R, &x);
      L--; R--;
      res = 0;
      segTrie.query(x, 0, LN);
      printf("%d\n", res);
    }
    else if(type == 2) {
      int k; scanf("%d", &k);
      int curr_sz = A.size();
      for(int i = curr_sz - 1; i >= curr_sz - k; i++) {
        curr_index = i;
        segTrie.remove(A[i], 0, LN);
        A.pop_back();
      }
    }
    else if(type == 3) {
      int x; scanf("%d %d %d", &L, &R, &x);
      L--; R--;
      vector<int> new_arr; for(int m = L; m <= R; m++) new_arr.push_back(A[m]);
      sort(new_arr.begin(), new_arr.end());
      printf("%ld\n", upper_bound(new_arr.begin(), new_arr.end(), x) - new_arr.begin());
    }
    else {
      int k; scanf("%d %d %d", &L, &R, &k);
      L--; R--; k--;
      vector<int> new_arr; for(int m = L; m <= R; m++) new_arr.push_back(A[m]);
      sort(new_arr.begin(), new_arr.end());
      printf("%d\n", new_arr[k]);
    }
  }
}
