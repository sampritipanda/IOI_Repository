// Vanya and Triangles

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
vector<pair<int, int> > points;

int main() {
  int N; cin >> N;
  points.resize(N);

  for(int i = 0; i < N; i++) {
    cin >> points[i].first >> points[i].second;
  }

  long long total = 0;
  if( N < 3) { cout << "0" << endl;return 0;}
  map<double, int> slopes;
  for(int i = 0; i < N; i++) {
    slopes.clear();
    long long temp = ( (N-1)*(N-2) )/2;
    long long sub  = 0 ;
    for(int j = i + 1; j < N; j++) {
      if(points[j].first == points[i].first) {
        slopes[10000000.0]++;
      }
      else {
        double curr_slope = (points[j].second - points[i].second)/(points[j].first - points[i].first);
        curr_slope = round(curr_slope * 100000.0)/100000.0;
        slopes[curr_slope]++;
      }
    }
    for(auto it : slopes){
      if(it.second > 1) sub = sub + ( ((it.second) * (it.second -1)) /2 );
    }
    total = total + ( (temp - sub));
  }
  cout << total/(N-1) << endl;
}
