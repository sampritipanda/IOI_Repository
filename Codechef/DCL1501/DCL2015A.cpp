// The Garage Sale

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

bool prime(int N){
  for(int i = 2; i*i <= N; i++){
    if(N % i == 0) return false;
  }

  return true;
}

int main() {
  int T; cin >> T;

  while(T--){
    string s; cin >> s;
    map<char, int> freq;
    for(auto c: s) freq[c]++;

    int max_freq = 0;
    for(auto it: freq) max_freq = max(max_freq, it.second);

    bool is_prime = prime(max_freq);
    int cost = 0;
    for(auto it: freq){
      int curr = it.second;
      if(curr == 1) cost += curr;
      else {
        if(!(prime(curr) ^ is_prime)) cost += curr - curr/2;
        else cost += curr;
      }
    }

    cout << cost << endl;
  }
}
