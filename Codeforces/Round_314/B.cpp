// Berland National Library

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int previous_size[101];
vector<pair<char, int> > events;

int main() {
  set<int> visitors;
  int N; cin >> N;
  int max_size = 0;
  int curr_size = 0;
  for(int i = 0; i <= N; i++) previous_size[i] = 0;

  events.push_back({'x', -1});

  for(int i = 1; i <= N; i++) {
    char event; int r; cin >> event >> r;
    events.push_back({event, r});

    if(event == '-' && visitors.count(r) == 0) {
      for(int j = 0; j < i; j++) previous_size[j]++;
    }
    if(event == '+') visitors.insert(r);
    else visitors.erase(r);
  }

  visitors.clear();
  for(int i = 1; i <= N; i++) {
    char event = events[i].first;
    int r = events[i].second;

    if(event == '+') {
      visitors.insert(r);
      curr_size++;
    }
    else {
      if(visitors.count(r) > 0) curr_size--;
      visitors.erase(r);
    }

    max_size = max(max_size, curr_size + previous_size[i]);
  }
  max_size = max(max_size, previous_size[0]);

  cout << max_size << endl;
}
