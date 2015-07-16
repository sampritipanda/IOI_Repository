// Chef and Piano Scales

#include <iostream>
#include <string>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    string s; cin >> s;
    int N; cin >> N;
    int per_scale = 0;
    for(auto c: s){
      if(c == 'T') per_scale += 2;
      else per_scale += 1;
    }
    int total = 12 * N;

    int ans = 0;
    for(int i = 1; i <= total; i++){
      int j = i + per_scale;
      while(j <= total){
        ans++;
        j += per_scale;
      }
    }

    cout << ans << endl;
  }
}
