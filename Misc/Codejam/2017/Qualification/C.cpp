#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    long long N; cin >> N;
    long long K; cin >> K; K--;

    vector<pair<long long, long long>> curr; // {dist, freq}
    curr.push_back({N, 1});

    long long ans_dist = -1;
    while(K > 0) {
      vector<pair<long long, long long>> curr2;
      if(curr.size() == 1) {
        if(K < curr[0].second) {
          ans_dist = curr[0].first;
          break;
        }
        if(curr[0].first % 2 == 1) {
          curr2.push_back({curr[0].first/2, curr[0].second * 2});
        }
        else {
          curr2.push_back({curr[0].first/2 - 1, curr[0].second});
          curr2.push_back({curr[0].first/2, curr[0].second});
        }
        K -= curr[0].second;
      }
      else {
        if(K < curr[1].second) {
          ans_dist = curr[1].first;
          break;
        }
        map<long long, long long> temp;
        if(curr[1].first % 2 == 1) {
          temp[curr[1].first/2] += curr[1].second * 2;
        }
        else {
          temp[curr[1].first/2] += curr[1].second;
          temp[curr[1].first/2 - 1] += curr[1].second;
        }
        K -= curr[1].second;

        if(K < curr[0].second) {
          ans_dist = curr[0].first;
        }
        if(curr[0].first % 2 == 1) {
          temp[curr[0].first/2] += curr[0].second * 2;
        }
        else {
          temp[curr[0].first/2] += curr[0].second;
          temp[curr[0].first/2 - 1] += curr[0].second;
        }
        K -= curr[0].second;

        for(pair<long long, long long> it: temp) {
          curr2.push_back(it);
        }
      }

      sort(curr2.begin(), curr2.end());
      curr = curr2;
    }

    if(ans_dist == -1) {
      ans_dist = curr.back().first;
    }

    if(ans_dist % 2 == 0) {
      cout << "Case #" << t << ": " << ans_dist/2 << " " << (ans_dist/2 - 1) << endl;
    }
    else {
      cout << "Case #" << t << ": " << ans_dist/2 << " " << ans_dist/2 << endl;
    }
  }
}
