// Hamro and tools

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long box_hash[100001];
unordered_map<long long, vector<int> > boxes;
int box_id[100001];
int timer = 0;

int main() {
  int N, Q; cin >> N >> Q;

  for(int i = 1; i <= N; i++) {
    boxes[i].push_back(i);
    box_hash[i] = ++timer;
  }

  while(Q--) {
    int s, t; cin >> s >> t;
    if(box_hash[t] == -1) {
      box_hash[t] = ++timer;
      boxes[box_hash[t]] = {};
    }
    long long s_hash = box_hash[s], t_hash = box_hash[t];

    if(boxes[t_hash].empty()) box_hash[t] = s_hash, box_hash[s] = -1;
    else {
      for(auto it: boxes[s_hash]) boxes[t_hash].push_back(it);
      boxes.erase(s_hash);
      box_hash[s] = -1;
    }
  }

  for(int i = 1; i <= N; i++) {
    for(auto j: boxes[box_hash[i]]) {
      box_id[j] = i;
    }
  }

  for(int i = 1; i <= N; i++) cout << box_id[i] << " ";
  cout << endl;
}
