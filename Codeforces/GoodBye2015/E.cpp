#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

using namespace std;

vector<int> T;
multiset<int> T2;
int A, B, C;

int check(int x) {
  T2.clear();
  for(auto it: T) T2.insert(it);

  while(!T2.empty() && *T2.rbegin() > B + C) {
    T2.erase(T2.find(*T2.rbegin()));
    x--;
  }

  map<string, int> freq;
  for(auto it: T2) {
    if(it <= A) freq["A"]++;
    else if(it <= B) freq["B"]++;
    else if(it <= C) freq["C"]++;
    else if(it <= A + B) freq["AB"]++;
    else if(it <= A + C) freq["AC"]++;
    else freq["BC"]++;
  }

  x -= freq["BC"]; freq["A"] -= min(freq["A"], freq["BC"]); freq["BC"] = 0;
  x -= freq["AC"]; freq["A"] -= min(max(freq["AC"] - freq["B"], 0), freq["A"]); freq["B"] -= min(freq["B"], freq["AC"]); freq["AC"] = 0;
  x -= freq["AB"]; freq["A"] -= min(max(freq["AB"] - freq["B"] - freq["C"], 0), freq["A"]); freq["B"] -= min(max(freq["AB"] - freq["C"], 0), freq["B"]); freq["C"] -= min(freq["C"], freq["AC"]); freq["AB"] = 0;

  x -= freq["C"]; freq["A"] -= min(freq["A"], freq["C"]); freq["B"] -= min(freq["B"], freq["C"]); freq["C"] = 0;
  cout << freq["A"] << " " << freq["B"] << " " << freq["C"] << endl;

  int count = ceil(freq["B"]/2.0); x -= count; freq["A"] -= min(freq["A"], count);
  x -= ceil(freq["A"]/3.0);

  if(x < 0) return 0;
  else return 1;
}

int main() {
  int N; cin >> N;
  vector<int> musk(3);
  cin >> musk[0] >> musk[1] >> musk[2];
  sort(musk.begin(), musk.end());
  A = musk[0], B = musk[1], C = musk[2];

  T.resize(N);
  for(int i = 0; i < N; i++) cin >> T[i];
  sort(T.begin(), T.end());

  bool pos = true;
  for(int i = 0; i < N; i++) {
    if(T[i] > A + B + C) {
      pos = false;
      break;
    }
  }

  if(pos) {
    int L = 0, R = 200000;
    while(L < R) {
      int mid = (L + R) >> 1;

      if(check(mid)) {
        R = mid;
      }
      else {
        L = mid + 1;
      }
    }

    cout << L << endl;
  }
  else {
    cout << -1 << endl;
  }
}
