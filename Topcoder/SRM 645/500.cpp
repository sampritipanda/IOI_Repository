// Connecting Cars

#include <vector>
#include <algorithm>

using namespace std;

class ConnectingCars {
  public:
  long long minimizeCost(vector <int> positions, vector <int> lengths){
    int N = positions.size();
    vector<pair<long long, long long> > intervals;
    for(int i = 0; i < N; i++){
      intervals.push_back({positions[i], positions[i] + lengths[i]});
    }
    sort(intervals.begin(), intervals.end());

    vector<long long> distances(N);
    distances[0] = 0;
    for(int i = 1; i < N; i++){
      distances[i] = intervals[i].first - intervals[i - 1].second;
    }

    unsigned long long min_effort = -1;
    for(int i = 0; i < N; i++){
      unsigned long long effort = 0, curr_start = intervals[i].first;
      for(int j = i - 1; j >= 0; j--){
        effort += curr_start - intervals[j].second;
        curr_start = intervals[j].first + (curr_start - intervals[j].second);
      }
      curr_start = intervals[i].second;
      for(int j = i + 1; j < N; j++){
        effort += intervals[j].first - curr_start;
        curr_start = intervals[j].second - (intervals[j].first - curr_start);
      }

      if(effort < min_effort) min_effort = effort;
    }

    return min_effort;
  }
};

