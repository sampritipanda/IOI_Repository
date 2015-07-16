// Load of the Roads

#include <iostream>
#include <cstring>

using namespace std;

int main() {
  int M; cin >> M;
  pair<int, int> ranges[M];

  for(int i = 0; i < M; i++){
    int L, R; cin >> L >> R;
    ranges[i] = {L, R};
  }

  int freq[M];
  memset(freq, 0, sizeof freq);

  int N; cin >> N;

  for(int i = 0; i < N; i++){
    int r; cin >> r;
    freq[r - 1]++;
  }

  for(int i = 0; i < M; i++){
    if(freq[i] < ranges[i].first){
      cout << "Green" << endl;
    }
    else if(freq[i] > ranges[i].second){
      cout << "Red" << endl;
    }
    else {
      cout << "Orange" << endl;
    }
  }
}
