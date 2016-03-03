#include <iostream>
#include <algorithm>

using namespace std;

int A[40], B[40];
int C[40];

inline bool zero() {
  for(int i = 39; i >= 0; i--) {
    if(C[i] != 0) return false;
  }
  return true;
}

inline void halfA() {
  int carry = 0;
  for(int i = 0; i < 40; i++) {
    int dev = carry * 10 + A[i];
    A[i] = dev/2;
    carry = dev % 2;
  }
}

inline void halfB() {
  int carry = 0;
  for(int i = 0; i < 40; i++) {
    int dev = carry * 10 + B[i];
    B[i] = dev/2;
    carry = dev % 2;
  }
}

inline void halfC() {
  int carry = 0;
  for(int i = 0; i < 40; i++) {
    int dev = carry * 10 + C[i];
    C[i] = dev/2;
    carry = dev % 2;
  }
}

int level() {
  int ans = 0;
  while(!zero()) {
    ans++;
    halfC();
  }
  return ans;
}

inline bool unequal() {
  for(int i = 39; i >= 0; i--) {
    if(A[i] != B[i]) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int Q; cin >> Q;

  while(Q--) {
    for(int i = 0; i < 40; i++) A[i] = B[i] = C[i] = 0;

    string u, v; cin >> u >> v;

    for(int i = u.size() - 1, j = 39; i >= 0; i--, j--) A[j] = u[i] - '0';
    for(int i = v.size() - 1, j = 39; i >= 0; i--, j--) B[j] = v[i] - '0';

    for(int i = 0; i < 40; i++) C[i] = A[i];
    int u_level = level();
    for(int i = 0; i < 40; i++) C[i] = B[i];
    int v_level = level();

    int ans = 0;
    if(v_level > u_level) {
      while(v_level > u_level) {
        ans++;
        v_level--;
        halfB();
      }
    }
    else {
      while(u_level > v_level) {
        ans++;
        u_level--;
        halfA();
      }
    }

    while(unequal()) {
      ans += 2;
      halfA(); halfB();
    }

    cout << ans << endl;
  }
}
