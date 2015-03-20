// No Right Turn

#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

struct state {
  int p;
  vector<int> previous = {};
  unsigned long long visited = 0;
};

// http://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}

bool check_intersect(state& S, vector<int>& x, vector<int>& y){
  int K = S.previous.size();
  if(K < 2) return false;
  Point p2; p2.x = x[S.previous[K - 1]]; p2.y = y[S.previous[K - 1]];
  Point q2; q2.x = x[S.p]; q2.y = y[S.p];
  for(int i = 0; i < (K - 1); i++){
    Point p1; p1.x = x[S.previous[i]]; p1.y = y[S.previous[i]];
    Point q1; q1.x = x[S.previous[i + 1]]; q1.y = y[S.previous[i + 1]];
    if(p2.x == q1.x && p2.y == q1.y) continue;
    if(doIntersect(p1, q1, p2, q2)) return true;
  }
  return false;
}

bool counter_clockwise(int a, int b, int c, vector<int>& x, vector<int>& y){
  long long value = (x[b] - x[a]) * (y[b] + y[a]);
  value += (x[c] - x[b]) * (y[c] * y[b]);
  value += (x[a] - x[c]) * (y[a] + y[c]);
  return (value < 0);
}

class NoRightTurnDiv2 {
  public:
  vector <int> findPath(vector <int> x, vector <int> y) {
    int N = x.size();
    queue<state> Q;
    for(int i = 0; i < N; i++){
      state curr; curr.p = i;
      Q.push(curr);
    }

    while(!Q.empty()){
      state S = Q.front();
      Q.pop();

      if(check_intersect(S, x, y)) continue;
      S.visited |= 1ULL << S.p;
      S.previous.push_back(S.p);
      if(__builtin_popcount(S.visited) == N) {
        return S.previous;
      }

      for(int i = 0; i < N; i++){
        if(!(S.visited & (1ULL << i))) {
          if(S.previous.size() >= 2 && !counter_clockwise(S.previous[S.previous.size() - 2], S.previous[S.previous.size() - 1], i, x, y)) continue;
          state next = S;
          next.p = i;
          Q.push(next);
        }
      }
    }

    vector<int> V;
    return V;
  }
};

int main() {
  vector<int> x = {0,0,-3,-3,3,3};
  vector<int> y = {-1,1,-3,3,-3,3};
  NoRightTurnDiv2 test;
  vector<int> ans = test.findPath(x, y);
  for(auto it: ans) cout << it << " ";
  cout << endl;
}

