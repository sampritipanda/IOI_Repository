#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <fstream>

using namespace std;

int C[23][70][100];
int D[70][600];

int main() {
  vector<char> A = {'a', 'b', 'c', 'd', 'e', 'g', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'y', 'z'};

  for(int i = 0; i < 23; i++) {
    string file = "l/alphabet/";
    file += A[i];
    file += ".in";
    ifstream in(file);

    for(int j = 0; j < 70; j++) {
      for(int k = 0; k < 100; k++) {
        in >> C[i][j][k];
        if(C[i][j][k] < 100) C[i][j][k] = 0;
        else C[i][j][k] = 1;
      }
    }
  }

  for(int x = 1; x <= 1; x++) {
    string file = to_string(x);
    while(file.length() < 3) file = "0" + file;
    file = "l/l1/" + file;
    file += ".in";

    ifstream in(file);

    for(int j = 0; j < 70; j++) {
      for(int k = 0; k < 600; k++) {
        in >> D[j][k];
        if(D[j][k] < 100) D[j][k] = 0;
        else D[j][k] = 1;
      }
    }

    for(int k = 0; k < 600; k += 100) {
      int best_char = -1;
      int max_count = -1;
      for(int c = 0; c < 23; c++) {
        int best_here = 0;
        for(int h_s = 0; h_s <= 20; h_s++) {
          for(int h_v = 0; h_v <= 20; h_v++) {
            int curr = 0;
            for(int i = 0; i < 70; i++) {
              if(i + h_s >= 70) break;
              for(int j = k; j < k + 100; j++) {
                if(j + h_v >= k + 100) break;
                if(C[c][i][j] == 0 && C[c][i][j] == D[i + h_s][j + h_v]) curr++;
              }
            }
            best_here = max(best_here, curr);
          }
        }
        if(best_here > max_count) {
          max_count = best_here;
          best_char = c;
        }
      }
      cout << A[best_char] << " " << max_count << endl;
    }
  }

  // for(int i = 0; i < 70; i++) {
  //   for(int j = 100; j < 200; j++) {
  //     if(D[i][j] == 1) cout << ' ';
  //     else cout << '.';
  //   }
  //   cout << endl;
  // }
}
