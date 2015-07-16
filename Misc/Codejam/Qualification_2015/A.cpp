// Standing Ovation

#include <iostream>

using namespace std;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++){
    int S; cin >> S;
    string str; cin >> str;
    int K[S + 1]; for(int i = 0; i <= S; i++) K[i] = str[i] - '0';

    int ans = 0;
    int curr_standing = K[0];
    for(int i = 1; i <= S; i++){
      if(curr_standing < i){
        ans += i - curr_standing;
        curr_standing = i;
      }
      curr_standing += K[i];
    }

    cout << "Case #" << t << ": " << ans << endl;
  }
}
