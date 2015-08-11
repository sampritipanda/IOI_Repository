// Devu And Churu

#include <cstdio>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

int A[1000000];
map<int, int> B;
unordered_map<int, int> compres_map;
int k1[1000000];
int B_arr[1000005];
stack<int> V;

inline int scan(){
  char c = getchar_unlocked();
  int x = 0;
  while(c<'0'||c>'9'){
    c=getchar_unlocked();
  }
  while(c>='0'&&c<='9'){
    x=(x<<1)+(x<<3)+c-'0';
    c=getchar_unlocked();
  }
  return x;
}

int main() {
  int N = scan(), M = scan();

  for(int i = 0; i < N; i++) A[i] = scan();

  for(int i = 0; i < N; i++) {
    while(!V.empty() && A[V.top()] < A[i]) {
      V.pop();
    }

    if(V.empty()) k1[i] = 0;
    else k1[i] = V.top() + 1;

    k1[i] = i - k1[i] + 1;

    V.push(i);
  }

  while(!V.empty()) V.pop();

  for(int i = N - 1; i >= 0; i--) {
    while(!V.empty() && A[V.top()] <= A[i]) {
      V.pop();
    }

    int curr;
    if(V.empty()) curr = N - 1;
    else curr = V.top() - 1;
    k1[i] *= (curr - i + 1);

    V.push(i);
  }

  for(int i = 0; i < N; i++) {
    B[A[i]] += k1[i];
  }

  int counter = 1;
  for(auto it: B) {
    B_arr[counter] = it.second;
    compres_map[it.first] = counter;
    counter++;
  }
  B_arr[0] = 0;
  for(int i = 1; i < counter; i++) {
    B_arr[i] += B_arr[i - 1];
  }

  while(M--) {
    char C;
    do {
      C = getchar_unlocked();
    } while(C != '>' && C != '<' && C != '=');
    int K = scan();
    char X;
    do {
      X = getchar_unlocked();
    } while(X != 'C' && X != 'D');

    char X_opp = (X == 'C' ? 'D' : 'C');

    int nums = 0;
    if(C == '=') {
      int x = compres_map[K];
      if(x == 0) nums = 0;
      else nums = B_arr[x] - B_arr[x - 1];
    }
    else if(C == '<') {
      auto it = B.lower_bound(K);
      if(it == B.begin()) nums = 0;
      else {
        --it;
        nums = B_arr[compres_map[it->first]];
      }
    }
    else {
      auto it = B.upper_bound(K);
      if(it == B.end()) nums = 0;
      else nums = B_arr[counter - 1] - B_arr[compres_map[it->first] - 1];
    }

    if(nums & 1) printf("%c", X);
    else printf("%c", X_opp);
  }

  printf("\n");
}

