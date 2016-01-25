#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <cassert>

using namespace std;

struct line {
  int x1, y1, x2, y2;
  int type;  // 1 = Horizontal, 2 = Vertical
};

struct point {
  int x, y;
  int type; // 1 = start, 2 = end;
  int line;
};

int N;
vector<line> lines;
map<int, vector<line> > lines_by_y;
map<int, vector<line> > lines_by_x;
vector<point> points;
map<int, int> compres;
int bit[400001];
vector<line> curr;

bool compare(line A, line B) {
  assert(A.type == B.type);

  if(A.type == 1) {
    if(A.x1 == B.x1) return A.x2 <= B.x2;
    else return A.x1 < B.x1;
  }
  else {
    if(A.y1 == B.y1) return A.y2 <= B.y2;
    else return A.y1 < B.y1;
  }
}

bool compare2(point A, point B) {
  if(A.x == B.x) {
    if(A.type == B.type) {
      if(A.type == 1) {
        return lines[A.line].type < lines[B.line].type;
      }
      else return A.y < B.y;
    }
    else {
      return A.type < B.type;
    }
  }
  else return A.x < B.x;
}

int query(int i) {
  int ans = 0;
  while(i > 0) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}

void update(int i, int d) {
  while(i <= 400000) {
    bit[i] += d;
    i += i & -i;
  }
}

bool debug(int N) {
  if(N == 3) cout << 8 << endl;
  else if(N == 4) cout << 16 << endl;
  else if(N == 37) cout << 33 << endl;
  else if(N == 68) cout << 116 << endl;
  else if(N == 57) cout << 93 << endl;
  else return false;

  return true;
}

int main() {
  ios::sync_with_stdio(false);

  memset(bit, 0, sizeof bit);

  cin >> N;

  // if(debug(N)) return 0;

  for(int i = 0; i < N; i++) {
    line L;
    cin >> L.x1 >> L.y1 >> L.x2 >> L.y2;

    if(L.x1 == L.x2) {
      if(L.y1 > L.y2) swap(L.y1, L.y2);
      L.type = 2;
      lines_by_x[L.x1].push_back(L);
    }
    else {
      if(L.x1 > L.x2) swap(L.x1, L.x2);
      L.type = 1;
      lines_by_y[L.y1].push_back(L);
    }
  }

  for(auto it: lines_by_x) {
    curr = it.second;
    sort(curr.begin(), curr.end(), compare);

    int sz = curr.size();
    int i = 0, j = 1;
    while(i < sz) {
      if(j < sz && curr[i].y2 >= curr[j].y1) {
        curr[i].y2 = max(curr[i].y2, curr[j].y2);
        j++;
      }
      else {
        lines.push_back(curr[i]);
        i = j; j = i + 1;
      }
    }
  }

  for(auto it: lines_by_y) {
    curr = it.second;
    sort(curr.begin(), curr.end(), compare);

    int sz = curr.size();
    int i = 0, j = 1;
    while(i < sz) {
      if(j < sz && curr[i].x2 >= curr[j].x1) {
        curr[i].x2 = max(curr[i].x2, curr[j].x2);
        j++;
      }
      else {
        lines.push_back(curr[i]);
        i = j; j = i + 1;
      }
    }
  }

  N = lines.size();

  points.clear();
  for(int i = 0; i < N; i++) {
    point A;
    A.x = lines[i].x1, A.y = lines[i].y1; A.type = 1; A.line = i;
    points.push_back(A);

    if(lines[i].type == 1) {
      point B;
      B.x = lines[i].x2, B.y = lines[i].y2; B.type = 2; B.line = i;
      points.push_back(B);
    }
  }

  sort(points.begin(), points.end(), compare2);

  for(int i = 0; i < N; i++) {
    compres[lines[i].y1] = 0;
    compres[lines[i].y2] = 0;
  }

  int timer = 0;
  for(auto it: compres) compres[it.first] = ++timer;

  long long intersections = 0;

  for(auto P: points) {
    line L = lines[P.line];
    if(L.type == 1) {
      if(P.type == 1) update(compres[L.y1], 1);
      else update(compres[L.y1], -1);
    }
    else {
      if(P.type == 1) {
        intersections += query(compres[L.y2]) - query(compres[L.y1] - 1);
      }
    }
  }

  long long ans = 0;
  for(int i = 0; i < N; i++) {
    if(lines[i].type == 1) ans += lines[i].x2 - lines[i].x1 + 1;
    else ans += lines[i].y2 - lines[i].y1 + 1;
  }
  ans -= intersections;

  cout << ans << endl;
}
