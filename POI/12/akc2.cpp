// Trying out shitty memory optimizations

#include <cstdio>
// #include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;

#define EPS 1e-6
#define PI 3.1415926535

int circle_circle_intersection(float x0, float y0, float r0,
    float x1, float y1, float r1,
    float *xi, float *yi,
    float *xi_prime, float *yi_prime)
{
  float a, dx, dy, d, h, rx, ry;
  float x2, y2;

  /* dx and dy are the vertical and horizontal distances between
   * the circle centers.
   */
  dx = x1 - x0;
  dy = y1 - y0;

  /* Determine the straight-line distance between the centers. */
  //d = sqrt((dy*dy) + (dx*dx));
  d = hypot(dx,dy); // Suggested by Keith Briggs

  /* Check for solvability. */
  if (d - (r0 + r1) > EPS)
  {
    /* no solution. circles do not intersect. */
    return 0;
  }
  if (d - fabs(r0 - r1) <= EPS)
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

inline float angle(float x, float y) {
  float ang = atan2(y, x) * 180/PI;
  if(ang < -EPS) ang = 360 + ang;
  return ang;
}

struct Real {
  float X;

  Real(float _X) {
    X = _X;
  }

  bool operator < (const Real R) const {
    return (X - R.X) < -EPS;
  }
};

float X[2001], Y[2001], R[2001];
int sz[2001];
float I[2001][2001][2];
short I_C[2001][2001][2];
bool skip[2001];
map<Real, int> C;
short segtree[2001][4001];
short lazy[2001][4001];

void propagate(int j, int L, int R, int i) {
  if(lazy[j][i] > 0) {
    segtree[j][i] += lazy[j][i];
    if(L != R) {
      lazy[j][2*i + 1] += lazy[j][i];
      lazy[j][2*i + 2] += lazy[j][i];
    }
    lazy[j][i] = 0;
  }
}

void update(int j, int L, int R, int i, int qL, int qR) {
  propagate(j, L, R, i);

  if(L > qR || R < qL) return;
  if(qL <= L && R <= qR) {
    lazy[j][i] += 1;
    propagate(j, L, R, i);
    return;
  }

  int mid = (L + R)/2;
  update(j, L, mid, 2*i + 1, qL, qR);
  update(j, mid + 1, R, 2*i + 2, qL, qR);
  segtree[j][i] = max(segtree[j][2*i + 1], segtree[j][2*i + 2]);
}

void update_helper(int i, int L, int R) {
  if(L >= R) {
    update(i, 1, sz[i], 0, R, L);
  }
  else {
    update(i, 1, sz[i], 0, 1, L);
    update(i, 1, sz[i], 0, R, sz[i]);
  }
}

int main() {
  int N; scanf("%d", &N);

  for(int i = 1; i <= N; i++) {
    scanf("%f %f %f", &X[i], &Y[i], &R[i]);
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j < i; j++) {
      if(i == j) continue;

      if(R[j] <= R[i] && (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]) <= (R[i] - R[j]) * (R[i] - R[j])) {
        skip[i] = true;
        break;
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    if(skip[i]) continue;
    C.clear();
    for(int j = 1; j <= N; j++) {
      if(i == j) continue;
      if(skip[j]) continue;

      float p_x1, p_y1, p_x2, p_y2;

      int res = circle_circle_intersection(X[i], Y[i], R[i],
          X[j], Y[j], R[j],
          &p_x1, &p_y1,
          &p_x2, &p_y2);

      I[i][j][0] = angle(p_x1 - X[i], p_y1 - Y[i]);
      I[i][j][1] = angle(p_x2 - X[i], p_y2 - Y[i]);

      if(res == 0) {
        I[i][j][0] = I[i][j][1] = -1.000;
        continue;
      }
      else if(res == -1) {
        I[i][j][0] = 360.0;
        I[i][j][1] = 0.0;
      }

      C[I[i][j][0]];
      C[I[i][j][1]];
    }

    C[0.0];
    C[360.0];

    int timer = 0;
    for(map<Real, int>::iterator it = C.begin(); it != C.end(); it++) {
      C[it->first] = ++timer;
    }

    for(int j = 1; j <= N; j++) {
      if(i == j) continue;
      if(I[i][j][0] == -1.000) continue;

      I_C[i][j][0] = C[I[i][j][0]];
      I_C[i][j][1] = C[I[i][j][1]];
    }

    sz[i] = C.size();
  }

  int ans = -1;
  int skip_count = 0;
  for(int i = 1; i <= N; i++) {
    if(skip[i]) {
      skip_count++;
      continue;
    }
    bool found = false;
    for(int j = 1; j < i; j++) {
      if(I[i][j][0] == -1.000) continue;
      if(skip[j]) continue;

      int qL = I_C[i][j][0], qR = I_C[i][j][1];
      update_helper(i, qL, qR);

      if(I[j][i][0] == 360.0 && I[j][i][1] == 0.0 && R[j] >= R[i]) continue;

      qL = I_C[j][i][0], qR = I_C[j][i][1];
      update_helper(j, qL, qR);

      if(segtree[j][0] == i - 1 - skip_count) {
        found = true;
      }
    }
    if(segtree[i][0] == i - 1 - skip_count) {
      found = true;
    }

    if(!found) {
      ans = i;
      break;
    }
  }

  if(ans == -1) printf("NIE\n");
  else printf("%d\n", ans);
  //
  // int ans2 = 0;
  // for(int i = 1; i <= N; i++) {
  //   ans2 = max(ans2, sz[i]);
  // }
  // cerr << ans2 << endl;
}
