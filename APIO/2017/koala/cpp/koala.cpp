#include "koala.h"
#include <cstring>
#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int B[100];
int R[100];

int minValue(int N, int W) {
  memset(B, 0, sizeof B);
  memset(R, 0, sizeof R);

  // assert(N == 100);
  // assert(W == 100);

  B[0] = W - 2;
  B[1] = 2;
  playRound(B, R);

  int curr_min = -1;
  for(int i = 1; i < N; i++) {
    if(R[i] <= B[i]) {
      curr_min = i;
      break;
    }
  }

  int start = (curr_min == 1 ? 2 : 1);
  memset(B, 0, sizeof B);
  memset(R, 0, sizeof R);
  B[start] = W - 2;
  B[start + 1] = 2;
  playRound(B, R);

  for(int i = 0; i < N; i++) {
    if(i == start) continue;
    if(R[i] <= B[i]) {
      return i;
    }
  }
}

int maxValue(int N, int W) {
  vector<int> cands;

  memset(B, 0, sizeof B);
  memset(R, 0, sizeof R);
  for(int i = 0; i < N; i++) B[i] = 1;
  playRound(B, R);
  for(int i = 0; i < N; i++) {
    if(R[i] == 2) cands.push_back(i);
  }

  memset(B, 0, sizeof B);
  memset(R, 0, sizeof R);
  for(int i: cands) {
    B[i] = 2;
  }
  cands.clear();
  playRound(B, R);
  for(int i = 0; i < N; i++) {
    if(R[i] == 3) cands.push_back(i);
  }

  memset(B, 0, sizeof B);
  memset(R, 0, sizeof R);
  for(int i: cands) {
    B[i] = 4;
  }
  cands.clear();
  playRound(B, R);
  for(int i = 0; i < N; i++) {
    if(R[i] == 5) cands.push_back(i);
  }

  memset(B, 0, sizeof B);
  memset(R, 0, sizeof R);
  for(int i: cands) {
    B[i] = 11;
  }
  for(int i = 0; i < N; i++) {
    if(B[i] == 0) {
      B[i] = 1;
      break;
    }
  }
  cands.clear();
  playRound(B, R);
  for(int i = 0; i < N; i++) {
    if(R[i] == 12) cands.push_back(i);
  }

  assert(cands.size() == 1);
  return cands[0];
}

int greaterValue(int N, int W) {
  memset(B, 0, sizeof B);
  memset(R, 0, sizeof R);

  B[0] = 8;
  B[1] = 8;
  B[99] = 84;
  playRound(B, R);

  if(R[0] > R[1]) return 0;
  else if(R[0] < R[1]) return 1;

  memset(B, 0, sizeof B);
  memset(R, 0, sizeof R);

  B[0] = 4;
  B[1] = 4;
  B[99] = 92;
  playRound(B, R);

  if(R[0] > R[1]) return 0;
  else if(R[0] < R[1]) return 1;

  memset(B, 0, sizeof B);
  memset(R, 0, sizeof R);

  B[0] = 2;
  B[1] = 2;
  B[99] = 96;
  playRound(B, R);

  if(R[0] > R[1]) return 0;
  else if(R[0] < R[1]) return 1;

  assert(false);
}

void allValues(int N, int W, int *P) {
  if (W == 2*N) {
    // TODO: Implement Subtask 4 solution here.
    // You may leave this block unmodified if you are not attempting this
    // subtask.
  } else {
    // TODO: Implement Subtask 5 solution here.
    // You may leave this block unmodified if you are not attempting this
    // subtask.
  }
}
