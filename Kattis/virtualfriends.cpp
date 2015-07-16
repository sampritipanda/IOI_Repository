// Virtual Friends

#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int union_find[100010];
int sizes[100010];
map<string, int> dict;

int find_group(int x) {
  if (x == union_find[x]) return x;
  return union_find[x] = find_group(union_find[x]);
}

void merge_group(int a, int b) {
  a = find_group(a);
  b = find_group(b);
  if (a != b) {
    union_find[a] = b;
    sizes[b] += sizes[a];
    sizes[a] = 0;
  }
}

int main() {
  int T; cin >> T;

  while(T--) {
    dict.clear();
    for(int i = 0; i < 100010; i++) {
      union_find[i] = i;
      sizes[i] = 1;
    }

    int F; cin >> F;
    int N = 1;
    while(F--) {
      string from, to; cin >> from >> to;
      if(dict.find(from) == dict.end()) {
        dict[from] = N;
        N++;
      }
      if(dict.find(to) == dict.end()) {
        dict[to] = N;
        N++;
      }

      merge_group(dict[from], dict[to]);
      cout << sizes[find_group(dict[from])] << endl;
    }
  }
}
