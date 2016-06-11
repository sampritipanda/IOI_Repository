#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

#define EPS 1e-6

int circle_circle_intersection(double x0, double y0, double r0,
    double x1, double y1, double r1,
    double *xi, double *yi,
    double *xi_prime, double *yi_prime)
{
  double a, dx, dy, d, h, rx, ry;
  double x2, y2;

  /* dx and dy are the vertical and horizontal distances between
   * the circle centers.
   */
  dx = x1 - x0;
  dy = y1 - y0;

  /* Determine the straight-line distance between the centers. */
  //d = sqrt((dy*dy) + (dx*dx));
  d = hypot(dx,dy); // Suggested by Keith Briggs

  /* Check for solvability. */
  if (d > (r0 + r1))
  {
    /* no solution. circles do not intersect. */
    return 0;
  }
  if (d < fabs(r0 - r1))
  {
    /* no solution. one circle is contained in the other */
    return -1;
  }

  /* 'point 2' is the point where the line through the circle
   * intersection points crosses the line between the circle
   * centers.  
   */

  /* Determine the distance from point 0 to point 2. */
  a = ((r0*r0) - (r1*r1) + (d*d)) / (2.0 * d) ;

  /* Determine the coordinates of point 2. */
  x2 = x0 + (dx * a/d);
  y2 = y0 + (dy * a/d);

  /* Determine the distance from point 2 to either of the
   * intersection points.
   */
  h = sqrt((r0*r0) - (a*a));

  /* Now determine the offsets of the intersection points from
   * point 2.
   */
  rx = -dy * (h/d);
  ry = dx * (h/d);

  /* Determine the absolute intersection points. */
  *xi = x2 + rx;
  *xi_prime = x2 - rx;
  *yi = y2 + ry;
  *yi_prime = y2 - ry;

  return 1;
}

int X[2001], Y[2001], R[2001];

bool compare(int A, int B) {
  return R[A] < R[B];
}

double distance(double x1, double y1, double x2, double y2) {
  return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool check_point(double x, double y, vector<int>& A) {
  for(int i = 0; i < A.size(); i++) {
    int x1 = X[A[i]], y1 = Y[A[i]], r1 = R[A[i]];
    double dist = (x - x1) * (x - x1) + (y - y1) * (y - y1);
    if(dist - (r1 * r1) > EPS) return false;
  }
  return true;
}

bool check(int N) {
  vector<int> temp;
  vector<int> A;
  for(int i = 1; i <= N; i++) temp.push_back(i);
  sort(temp.begin(), temp.end(), compare);

  for(int i = 0; i < temp.size(); i++) {
    int x1 = X[temp[i]], y1 = Y[temp[i]], r1 = R[temp[i]];
    bool pos = true;
    for(int j = 0; j < A.size(); j++) {
      int x2 = X[A[j]], y2 = Y[A[j]], r2 = R[A[j]];

      if(distance(x1, y1, x2, y2) - (r1 - r2) * (r1 - r2) <= EPS) {
        pos = false;
        break;
      }
    }
    if(pos) A.push_back(temp[i]);
  }

  if(A.size() == 1) return true;

  for(int i = 0; i < A.size(); i++) {
    int x1 = X[A[i]], y1 = Y[A[i]], r1 = R[A[i]];
    for(int j = i + 1; j < A.size(); j++) {
      int x2 = X[A[j]], y2 = Y[A[j]], r2 = R[A[j]];
      double p_x1, p_y1, p_x2, p_y2;

      int res = circle_circle_intersection(x1, y1, r1,
          x2, y2, r2,
          &p_x1, &p_y1,
          &p_x2, &p_y2);

      assert(res >= 0);
      if(res == 0) return false;

      if(check_point(p_x1, p_y1, A)) return true;
      if(check_point(p_x2, p_y2, A)) return true;
    }
  }

  return false;
}

int main() {
  int N; scanf("%d", &N);

  for(int i = 1; i <= N; i++) {
    scanf("%d %d %d", &X[i], &Y[i], &R[i]);
  }

  int L = 1, R = N;
  while(L <= R) {
    int mid = (L + R)/2;
    if(!check(mid)) {
      if(L == R) break;
      R = mid;
    }
    else {
      L = mid + 1;
    }
  }

  if(L == N + 1) printf("NIE\n");
  else printf("%d\n", L);
}
