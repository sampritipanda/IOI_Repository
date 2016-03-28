#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <cassert>

using namespace std;

typedef vector<vector<int>> face;
typedef vector<face> cube;


// 1. I/O Functions


vector<int> get_input(int N) {
  vector<int> flat(N);
  for(int i = 0; i < N; i++) cin >> flat[i];
  return flat;
}

vector<int> flatten(cube A) {
  vector<int> flat;
  for(auto it: A) {
    for(auto it2: it) {
      for(auto it3: it2) {
        flat.push_back(it3);
      }
    }
  }
  return flat;
}


// 2. Encoding/Decoding Functions


// 1,2,3 = top - row 1
// 4,5,6 = top - row 2
// 7,8,9 = top - row 3
//
// 10-18 = left
// 19-27 = front
// 28-36 = right
// 37-45 = back
//
// 46-54 = bottom
//
//
// level row 1 = (10), 11, 12, (19), 20, 21, (28), 29, 30, (37), 38, 39
// level row 2 = (13), 14, 15, ...
// level row 3 = (16), 17, 18, ...

long long cube_to_mask(vector<int> A) {
  int ptr = 0;
  long long mask = 0;

  // Face
  for(int i = 1; i <= 9; i++) {
    long long x = A[ptr++];
    mask |= (x << i);
  }

  // L, F, R, B
  for(int row_start = 10; row_start < 19; row_start += 3) {
    for(int face_start = row_start; face_start <= 45; face_start += 9) {
      for(int id = face_start; id < face_start + 3; id++) {
        long long x = A[ptr++];
        mask |= (x << id);
      }
    }
  }

  // Bottom
  for(int i = 46; i <= 54; i++) {
    long long x = A[ptr++];
    mask |= (x << i);
  }

  return mask;
}

long long cube_to_mask(cube A) {
  return cube_to_mask(flatten(A));
}

// { top { row1 {col1, col2, col3}, row2, row3 }, left, front, right, back, bottom }
cube mask_to_cube(long long mask) {
  cube A(6, face(3, vector<int>(3)));

  // Face
  for(int i = 1; i <= 9; i++) {
    int x = (mask & (1LL << i)) ? 1 : 0;
    A[0][(i - 1)/3][(i - 1) % 3] = x;
  }

  // L, F, R, B
  for(int row_start = 10, i = 0; row_start < 19; row_start += 3, i++) {
    for(int face_start = row_start, k = 1; face_start <= 45; face_start += 9, k++) {
      for(int id = face_start, j = 0; id < face_start + 3; id++, j++) {
        int x = (mask & (1LL << id)) ? 1 : 0;
        A[k][i][j] = x;
      }
    }
  }

  // Bottom
  for(int i = 46; i <= 54; i++) {
    int x = (mask & (1LL << i)) ? 1 : 0;
    int j = i - 46;
    A[0][j/3][j % 3] = x;
  }

  return A;
}


// 3. Helper Functions


// Print Cube
void print_cube(cube A) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      cout << A[0][i][j] << " ";
    }
    cout << endl;
  }

  for(int i = 0; i < 3; i++) {
    for(int k = 1; k <= 4; k++) {
      for(int j = 0; j < 3; j++) {
        cout << A[k][i][j] << " ";
      }
    }
    cout << endl;
  }

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      cout << A[5][i][j] << " ";
    }
    cout << endl;
  }
}

// Rotates a face by 90
face rotate_grid(face A) {
  int N = A.size(), M = A[0].size();
  assert(N == M);
  assert(N == 3);
  face B(3, vector<int>(3));


  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      B[j][3 - i - 1] = A[i][j];
    }
  }

  return B;
}


face rotate_grid_left(face A) {
  return rotate_grid(rotate_grid(rotate_grid(A)));
}


// 4. Basic Transitions

cube pitch_front(cube A) {
  // rotate left face
  A[1] = rotate_grid_left(A[1]);
  // rotate right face
  A[3] = rotate_grid_left(A[3]);

  face top = A[0], front = A[2], back = A[4], bottom = A[5];
  A[0] = back; swap(A[0][0], A[0][2]);
  A[2] = top;
  A[5] = front;
  A[4] = bottom; swap(A[4][0], A[4][2]);

  return A;
}

cube rotate_right(cube A) {
  // rotate front right
  A[2] = rotate_grid(A[2]);
  // rotate back left
  A[4] = rotate_grid_left(A[4]);

  face top = A[0], right = A[3], bottom = A[5], left = A[1];
  A[0] = left;
  A[3] = top;
  A[5] = right;
  A[1] = bottom;

  return A;
}

cube yaw_right(cube A) {
  // rotate top right
  A[0] = rotate_grid(A[0]);
  // rotate bottom right
  A[5] = rotate_grid(A[5]);

  face left = A[1], front = A[2], right = A[3], back = A[4];
  A[2] = left;
  A[3] = front;
  A[4] = right; for(int i = 0; i < 3; i++) swap(A[4][i][0], A[4][i][2]);
  A[1] = back; for(int i = 0; i < 3; i++) swap(A[4][i][0], A[4][i][2]);

  return A;
}

cube rotate_front_right(cube A) {
  A[2] = rotate_grid(A[2]);

  face top = A[0], left = A[1], right = A[3], bottom = A[5];
  A[3][0][0] = top[2][0];
  A[3][1][0] = top[2][1];
  A[3][2][0] = top[2][2];

  A[5][0][0] = right[2][0];
  A[5][0][1] = right[1][0];
  A[5][0][2] = right[0][0];

  A[1][0][2] = bottom[0][0];
  A[1][1][2] = bottom[0][1];
  A[1][2][2] = bottom[0][2];

  A[0][2][0] = left[2][2];
  A[0][2][1] = left[2][1];
  A[0][2][2] = left[2][0];

  return A;
}


// 5. Derived Transitions

cube rotate_left(cube A) {
  return rotate_right(rotate_right(rotate_right(A)));
}

cube pitch_back(cube A) {
  return pitch_front(pitch_front(pitch_front(A)));
}

cube yaw_left(cube A) {
  return yaw_right(yaw_right(yaw_right(A)));
}

cube rotate_front_left(cube A) {
  return rotate_front_right(rotate_front_right(rotate_front_right(A)));
}

cube rotate_back_right(cube A) {
  A = rotate_right(rotate_right(A));
  return rotate_front_right(A);
}

cube rotate_back_left(cube A) {
  A = rotate_right(rotate_right(A));
  return rotate_front_left(A);
}

cube pitch_left_front(cube A) {
  A = rotate_right(A);
  return rotate_front_right(A);
}

cube pitch_left_back(cube A) {
  A = rotate_right(A);
  return rotate_front_left(A);
}

cube pitch_right_front(cube A) {
  A = rotate_left(A);
  return rotate_front_left(A);
}

cube pitch_right_back(cube A) {
  A = rotate_left(A);
  return rotate_front_right(A);
}

cube rotate_top_right(cube A) {
  A = pitch_front(A);
  return rotate_right(A);
}

cube rotate_top_left(cube A) {
  A = pitch_front(A);
  return rotate_left(A);
}

cube rotate_bottom_right(cube A) {
  A = pitch_back(A);
  return rotate_right(A);
}

cube rotate_bottom_left(cube A) {
  A = pitch_back(A);
  return rotate_left(A);
}

// 6. Main


queue<pair<long long, int> > Q;
map<long long, int> dist;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int rotations; cin >> rotations;
  long long S = cube_to_mask(get_input(54));
  cube A = mask_to_cube(S);

  Q.push({S, 0});

  while(!Q.empty()) {
    long long i = Q.front().first, d = Q.front().second; Q.pop();

    if(dist.count(i) > 0) continue;
    dist[i] = d;

    int bitnct = __builtin_popcountll(i);

    cube A = mask_to_cube(i);

    // Possible Transitions  ( x == base )
    // Cube Rotate =>
    // x  a. pitch_front
    //    b. pitch_back
    // x  c. rotate_right
    //    d. rotate_left
    // x  e. yaw_right
    //    f. yaw_left
    // Face Rotate =>
    // x  a. rotate_front_right, rotate_front_left
    //    b. rotate_back_right, rotate_back_right
    //    c. pitch_left_front, pitch_left_back
    //    d. pitch_right_front, pitch_right_back
    //    e. rotate_top_right, rotate_top_left
    //    f. rotate_bottom_right, rotate_bottom_left

    Q.push({cube_to_mask(pitch_front(A)), d + 1});
    Q.push({cube_to_mask(pitch_back(A)), d + 1});

    Q.push({cube_to_mask(rotate_right(A)), d + 1});
    Q.push({cube_to_mask(rotate_left(A)), d + 1});

    Q.push({cube_to_mask(yaw_right(A)), d + 1});
    Q.push({cube_to_mask(yaw_left(A)), d + 1});

    Q.push({cube_to_mask(rotate_front_right(A)), d + 1});
    Q.push({cube_to_mask(rotate_front_left(A)), d + 1});

    Q.push({cube_to_mask(rotate_back_right(A)), d + 1});
    Q.push({cube_to_mask(rotate_back_left(A)), d + 1});

    Q.push({cube_to_mask(pitch_left_front(A)), d + 1});
    Q.push({cube_to_mask(pitch_left_back(A)), d + 1});

    Q.push({cube_to_mask(pitch_right_front(A)), d + 1});
    Q.push({cube_to_mask(pitch_right_back(A)), d + 1});

    Q.push({cube_to_mask(rotate_top_right(A)), d + 1});
    Q.push({cube_to_mask(rotate_top_left(A)), d + 1});

    Q.push({cube_to_mask(rotate_bottom_right(A)), d + 1});
    Q.push({cube_to_mask(rotate_bottom_left(A)), d + 1});
  }

  int M; cin >> M;
    M = 0;

  while(M--) {
    long long mask = cube_to_mask(get_input(54));
    if(dist.count(mask) == 0) cout << -1 << endl;
    else cout << dist[mask] << endl;
  }
}
