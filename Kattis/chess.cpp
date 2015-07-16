// Chess

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool valid(int X_1, int X_2){
  return X_1 >= 'A' && X_1 <= 'H' && X_2 >= 1 && X_2 <= 8;
}

bool same_line(int X_1, int X_2, int Y_1, int Y_2){
  return (abs(Y_1 - X_1) == abs(Y_2 - X_2));
}

int main() {
  int N; cin >> N;

  while(N--){
    char X_1, Y_1; int X_2, Y_2;
    cin >> X_1 >> X_2 >> Y_1 >> Y_2;

    int color_1, color_2;         // 0 = White, 1 = Black
    if((X_1 - 'A') % 2 == 1 && X_2 % 2 == 1) color_1 = 0;
    else if((X_1 - 'A') % 2 == 0 && X_2 % 2 == 0) color_1 = 0;
    else color_1 = 1;

    if((Y_1 - 'A') % 2 == 1 && Y_2 % 2 == 1) color_2 = 0;
    else if((Y_1 - 'A') % 2 == 0 && Y_2 % 2 == 0) color_2 = 0;
    else color_2 = 1;

    if(color_1 != color_2) cout << "Impossible" << endl;
    else {
      if(X_1 == Y_1 && X_2 == Y_2) cout << 0 << " " << Y_1 << " " << Y_2 << endl;
      else if(same_line(X_1, X_2, Y_1, Y_2)) cout << 1 << " "  << X_1 << " " << X_2 << " " << Y_1 << " " << Y_2 << endl;
      else {
        cout << 2 << " " << X_1 << " " << X_2;
        for(int i = 1; i < 8; i++){
          if(valid(X_1 + i, X_2 + i) && same_line(X_1 + i, X_2 + i, Y_1, Y_2)){
            cout << " " << char(X_1 + i) << " " << X_2 + i << " ";
            break;
          }
          else if(valid(X_1 - i, X_2 - i) && same_line(X_1 - i, X_2 - i, Y_1, Y_2)){
            cout << " " << char(X_1 - i) << " " << X_2 - i << " ";
            break;
          }
          else if(valid(X_1 + i, X_2 - i) && same_line(X_1 + i, X_2 - i, Y_1, Y_2)){
            cout << " " << char(X_1 + i) << " " << X_2 - i << " ";
            break;
          }
          else if(valid(X_1 - i, X_2 + i) && same_line(X_1 - i, X_2 + i, Y_1, Y_2)){
            cout << " " << char(X_1 - i) << " " << X_2 + i << " ";
            break;
          }
        }
        cout << Y_1 << " " << Y_2 << endl;
      }
    }
  }
}
