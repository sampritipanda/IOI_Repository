#include <iostream>

using namespace std;

bool row[51], col[51];

int main() {
  int N; cin >> N;
  for(int i = 1; i <= N; i++) row[i] = col[i] = false;

  for(int i = 0; i < N*N; i++) {
    int h, v; cin >> h >> v;
    if(!row[h] && !col[v]) {
      row[h] = true; col[v] = true;
      cout << i + 1 << " ";
    }
  }
  cout << endl;
}
