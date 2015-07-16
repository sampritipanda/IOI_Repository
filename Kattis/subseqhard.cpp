// Counting Subsequences (Hard)

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int A[1000010];
long long prefix[1000010];
map<long long, vector<int> > prefix_index_map;
set<int> prefixes;

int main() {
  int T; cin >> T;

  while(T--) {
    prefix_index_map.clear();
    prefixes.clear();

    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    long long curr_pref_sum = 0;
    for(int i = 0; i < N; i++) {
      curr_pref_sum += A[i];
      prefix[i] = curr_pref_sum;
      prefix_index_map[curr_pref_sum].push_back(i);
      prefixes.insert(curr_pref_sum);
    }

    for(auto it: prefixes) {
      sort(prefix_index_map[it].begin(), prefix_index_map[it].end());
    }

    int count = 0;
    for(int i = 0; i < N; i++) {
      long long required = prefix[i] - 47;
      if(required == 0) count++;
      vector<int> indexes = prefix_index_map[required];
      if(lower_bound(indexes.begin(), indexes.end(), 0) != lower_bound(indexes.begin(), indexes.end(), i)) {
        count += (lower_bound(indexes.begin(), indexes.end(), i) - indexes.begin());
      }
    }

    cout << count << endl;
  }
}
