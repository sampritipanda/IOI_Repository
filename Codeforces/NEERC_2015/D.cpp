#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long T[1001], S[1001], F[1001];
long long ans[1001];

// http://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/

struct Point
{
  long long x;
  long long y;
};

bool onSegment(Point p, Point q, Point r)
{
  if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
      q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
    return true;

  return false;
}

long long orientation(Point p, Point q, Point r)
{
  long long val = (q.y - p.y) * (r.x - q.x) -
    (q.x - p.x) * (r.y - q.y);

  if (val == 0) return 0;

  return (val > 0)? 1: 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
  long long o1 = orientation(p1, q1, p2);
  long long o2 = orientation(p1, q1, q2);
  long long o3 = orientation(p2, q2, p1);
  long long o4 = orientation(p2, q2, q1);

  if (o1 != o2 && o3 != o4)
    return true;

  if (o1 == 0 && onSegment(p1, p2, q1)) return true;

  if (o2 == 0 && onSegment(p1, q2, q1)) return true;

  if (o3 == 0 && onSegment(p2, p1, q2)) return true;

  if (o4 == 0 && onSegment(p2, q1, q2)) return true;

  return false;
}

int main() {
  int N; cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> T[i] >> S[i] >> F[i];
  }
  for(int i = 1; i <= N; i++) ans[i] = 0;

  for(int i = 1; i <= N; i++) {
    for(int j = i + 1; j <= N; j++) {
      struct Point p1 = {T[i], S[i]}, q1 = {T[i] + abs(F[i] - S[i]), F[i]};
      struct Point p2 = {T[j], S[j]}, q2 = {T[j] + abs(F[j] - S[j]), F[j]};

      if(doIntersect(p1, q1, p2, q2)) {
        ans[i]++;
        ans[j]++;
      }
    }
  }

  for(int i = 1; i <= N; i++) cout << ans[i] << " ";
  cout << endl;
}
