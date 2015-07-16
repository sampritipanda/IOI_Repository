#include <iostream>
#include <algorithm>
#include <set>

#define MOD 1000000007

using namespace std;

int union_find_man[10000];
int union_find_woman[10000];
vector<pair<int, int> > couples;

int find_man(int a) {
  if(union_find_man[a] == a) return a;
  return union_find_man[a] = find_man(union_find_man[a]);
}

void merge_man(int a, int b) {
  union_find_man[find_man(a)] = find_man(b);
}

int find_woman(int a) {
  if(union_find_woman[a] == a) return a;
  return union_find_woman[a] = find_woman(union_find_woman[a]);
}

void merge_woman(int a, int b) {
  union_find_woman[find_woman(a)] = find_woman(b);
}


int main() {
  int T; cin >> T;

  while(T--) {
    int N, Q; cin >> N >> Q;
    for(int i = 1; i <= N; i++) union_find_man[i] = union_find_woman[i] = i;
    couples.clear();

    long long sum = 0;
    for(int q = 1; q <= Q; q++) {
      int t, a, b; cin >> t >> a >> b;

      if(t == 1) {
        merge_man(a, b);
      }
      else {
        merge_woman(a, b);
      }

      long long ans = 0;
      for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
          if(find_man(i) == find_man(j) && find_woman(i) == find_woman(j)) ans++;
        }
      }
      ans = (ans * q) % MOD;
      sum = (sum + ans) % MOD;
    }
    cout << sum << endl;
  }
}
