// Saving a gift of love

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int T; cin >> T;

  while(T--){
    map<int, pair<bool, int> > coordinates;    // key = coordinate, value = { dish?, index }
    int N; cin >> N;
    int B; cin >> B;
    long long X[B], Y[B];
    for(int i = 0; i < B; i++) {
      cin >> X[i] >> Y[i];
      coordinates[X[i]] = { true, i };
    }

    int C; cin >> C;
    long long P[C], Q[C], R[C];
    for(int i = 0; i < C; i++) {
      cin >> P[i] >> Q[i] >> R[i];
      coordinates[P[i]] = { false, i };
    }

    long long ans_first = 1;
    for(int i = 0; i < B; i++){
      ans_first += Y[i];
    }

    long long ans_second = 0, remain = 0;
    long long last_dish_i = -1;
    for(auto it: coordinates){
      if(it.second.first){
        long long require = Y[it.second.second];
        if(require < remain) {
        }
      }
      else {
      }
    }
  }
}
