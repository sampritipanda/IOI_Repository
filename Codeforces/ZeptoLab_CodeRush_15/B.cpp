// Om Nom and Dark Park

#include <iostream>
#include <queue>

using namespace std;

int main() {
  int N; cin >> N;
  int num_lights = (1 << (N + 1)) - 1;
  int A[num_lights + 1]; for(int i = 2; i <= num_lights; i++) cin >> A[i];
  int subtree[num_lights + 1];
  for(int i = 0; i <= num_lights; i++) subtree[i] = 0;

  int ans = 0;
  for(int l = N; l >= 1; l--){
    for(int i = 1 << l; i < 1 << (l + 1); i += 2){
      A[i] += subtree[i];
      A[i + 1] += subtree[i + 1];
      int m = max(A[i], A[i + 1]);
      ans += (m - A[i]) + (m - A[i + 1]);
      subtree[i/2] = m;
    }
  }
  cout << ans << endl;
}
