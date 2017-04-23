#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int A[100001];
int rev_A[100001];
int vis[100001];
set<int> avl;

int main() {
  int T; cin >> T;

  while(T--) {
    int N; cin >> N;
    avl.clear();
    for(int i = 1; i <= N; i++) {
      avl.insert(i);
      A[i] = rev_A[i] = vis[i] = 0;
    }

    for(int i = 1; i <= N; i++) {
      cin >> A[i];
      rev_A[A[i]] = i;
      if(A[i] != 0) avl.erase(A[i]);
    }

    int ans = 0;

    for(int i = 1; i <= N; i++) {
      if(vis[i]) continue;

      int start = i;
      int end_point = start;
      while(true) {
        if(rev_A[end_point] == 0) break;
        end_point = rev_A[end_point];
        if(rev_A[end_point] == start) break;
      }
      avl.erase(end_point);

      int curr = i;
      while(true) {
        ans++;
        vis[curr] = true;
        if(A[curr] == 0) {
          if(avl.size() == 0) A[curr] = end_point;
          else {
            A[curr] = *avl.begin();
            avl.erase(avl.begin());
          }
        }
        curr = A[curr];
        if(curr == start) break;
      }
      ans--;
    }


    cout << ans << endl;
    for(int i = 1; i <= N; i++) cout << A[i] << " "; cout << endl;
  }
}
