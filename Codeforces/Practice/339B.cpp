// Xenia and Ringroad

#include <iostream>

using namespace std;

int main() {
  int n, m; cin >> n >> m;

  int prev = 1;
  long long time = 0;

  for(int i = 0; i < m; i++){
    int curr; cin >> curr;

    if(prev <= curr) time += curr - prev;
    else time += (n - prev) + curr;

    prev = curr;
  }

  cout << time << endl;
}
