#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool prime[1001];
vector<int> fact[1001];

int gcd(int a, int b) {
  if(b == 0) return a;

  return gcd(b, a % b);
}

bool check(set<int>& A, int x) {
  for(int y: A) {
    if(gcd(x, y) > 1) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  prime[1] = false;
  for(int i = 2; i <= 1000; i++) prime[i] = true;

  for(int i = 2; i <= 1000; i++) {
    if(!prime[i]) continue;

    for(int j = i + i; j <= 1000; j += i) {
      prime[j] = false;
      fact[j].push_back(i);
    }
  }

  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    int one_count = 0;
    set<int> A;
    set<int> B;
    for(int i = 0; i < N; i++) {
      int x; cin >> x;
      if(x == 1) {
        one_count++;
      }
      else {
        A.insert(x);
      }
    }

    for(int i = 1; i <= 1000; i++) {
      if(!prime[i] || A.count(i) == 0) continue;

      B.insert(i);
      for(int j = i; j <= 1000; j += i) {
        A.erase(j);
      }
    }

    for(int j = 2; j <= 5; j++) {
      for(int i = 1; i <= 1000; i++) {
        if(fact[i].size() == j && A.count(i) > 0) {
          bool pos = true;
          for(int k = 0; k < j; k++) {
            if(B.count(fact[i][k]) > 0) {
              pos = false;
              break;
            }
          }
          if(pos) {
            B.insert(i);
            for(int k = 0; k < j; k++) {
              for(int j = fact[i][k]; j <= 1000; j += fact[i][k]) {
                A.erase(j);
              }
            }
          }
          else {
            A.erase(i);
          }
        }
      }
    }

    cout << one_count + B.size() << endl;
  }
}
