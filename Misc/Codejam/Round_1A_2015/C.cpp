// Logging

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <climits>

using namespace std;

set<pair<int, int> > originalConvexHull;

int orientation(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
    int val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

set<pair<int, int> > findConvexHull(vector<pair<int, int> > points){
  int n = points.size();
  set<pair<int, int> > result;

  if (n < 3) {
    for(auto it: points) result.insert(it);
    return result;
  }

  // Initialize Result
  int next[n];
  for (int i = 0; i < n; i++)
    next[i] = -1;

  // Find the leftmost point
  int l = 0;
  for (int i = 1; i < n; i++)
    if (points[i].first < points[l].first)
      l = i;

  // Start from leftmost point, keep moving counterclockwise
  // until reach the start point again
  int p = l, q;
  do
  {
    // Search for a point 'q' such that orientation(p, i, q) is
    // counterclockwise for all points 'i'
    q = (p+1)%n;
    for (int i = 0; i < n; i++)
      if (orientation(points[p], points[i], points[q]) == 2)
        q = i;

    next[p] = q;  // Add q to result as a next point of p
    p = q; // Set p as q for next iteration
  } while (p != l);

  // Print Result
  for (int i = 0; i < n; i++)
  {
    if (next[i] != -1) result.insert(points[i]);
  }

  return result;
}

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++){
    int N; cin >> N;
    vector<pair<int, int> > points;
    for(int i = 0; i < N; i++){
      int a, b; cin >> a >> b;
      points.push_back({a, b});
    }

    originalConvexHull = findConvexHull(points);

    cout << "Case #" << t << ":" << endl;

    for(auto it: points) cout << "(" << it.first << "," << it.second << ")" << " ";
    cout << endl;
    for(auto it: originalConvexHull) cout << "(" << it.first << "," << it.second << ")" << " ";
    cout << endl;
    for(int i = 0; i < N; i++){
      if(originalConvexHull.find(points[i]) != originalConvexHull.end()) cout << 0 << endl;
      else {
        int ans = INT_MAX;
        for(int mask = 0; mask < (1 << N); mask++){
          if(!(mask & (1 << i))) continue;
          vector<pair<int, int> > newPoints;
          for(int j = 0; j < N; j++){
            if(mask & (1 << j)) newPoints.push_back(points[j]);
          }
          if(findConvexHull(newPoints).count(points[i]) > 0) ans = min(ans, N - __builtin_popcount(mask));
        }
        cout << ans << endl;
      }
    }
  }
}
