// Drazil and His Happy Friends

#include <iostream>

using namespace std;

int main () {
  int n, m; cin >> n >> m;
  bool boys[n], girls[m];
  for(int i = 0; i < n; i++) boys[i] = false;
  for(int i = 0; i < m; i++) girls[i] = false;

  int b; cin >> b;
  for(int i = 0; i < b; i++) {
    int x; cin >> x; boys[x] = true;
  }

  int g; cin >> g;
  for(int i = 0; i < g; i++) {
    int y; cin >> y; girls[y] = true;
  }

  long long i = 0;
  bool changed = false;
  while(true){
    if(i % 1000000 == 0 && i != 0){
      if(!changed) break;
      changed = false;
    }
    if(boys[i % n] ^ girls[i % m]){
      boys[i % n] = girls[i % m] = true;
      changed = true;
    }
    i++;
  }
  bool flag = true;
  for(int i = 0; i < n; i++){
    if(!boys[i]) flag = false;
  }
  for(int i = 0; i < m; i++){
    if(!girls[i]) flag = false;
  }

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
