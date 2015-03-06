// The Warehouse

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

long long inv_count = 0, N;

void merge(int A[], int L, int mid, int R){
  int C[N];
  int i = L, j = mid + 1, len = R - L + 1;
  for(int k = 0; k < len; k++){
    if(i > mid){
      C[k] = A[j];
      j++;
    }
    else if(j > R){
      C[k] = A[i];
      i++;
    }
    else if(A[i] < A[j]){
      C[k] = A[i];
      i++;
    }
    else {
      C[k] = A[j];
      j++;
      inv_count += mid - i + 1;
    }
  }
  for(int i = 0; i < len; i++){
    A[L + i] = C[i];
  }
}

void mergesort(int A[], int L, int R){
  if(L >= R) return;

  int mid = L + (R - L)/2;

  mergesort(A, L, mid);
  mergesort(A, mid + 1, R);
  merge(A, L, mid, R);
}

int search(vector<pair<int, int> > Q, int val){
  int low = 0, high = N, mid;
  while(low <= high){
    mid = low + (high - low)/2;
    if(Q[mid].first < val){
      low = mid + 1;
    }
    else if(Q[mid].first > val){
      high = mid - 1;
    }
    else {
      return Q[mid].second;
    }
  }
  return -1;
}

bool sort_compare(pair<int, int> a, pair<int, int> b){
  return a.first < b.first;
}

int main() {
  int T; cin >> T;
  char vals[3] = { 'r', 'g', 'b' };

  while(T--){
    string S; cin >> S;
    N = S.length();
    int freq[3] = { 0, 0, 0 };
    for(auto c: S){
      if(c == 'r') freq[0]++;
      else if(c == 'g') freq[1]++;
      else freq[2]++;
    }

    long long min_inv_count = LLONG_MAX;
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          if(i == j || j == k || i == k) continue;
          string curr = "";
          for(int a = 0; a < freq[i]; a++) curr += vals[i];
          for(int a = 0; a < freq[j]; a++) curr += vals[j];
          for(int a = 0; a < freq[k]; a++) curr += vals[k];
          inv_count = 0;
          vector<int> Q[3];
          int P[N + 1];
          for(int a = 0; a < N; a++) {
            if(curr[a] == 'r') Q[0].push_back(a);
            else if(curr[a] == 'g') Q[1].push_back(a);
            else Q[2].push_back(a);
          }
          // sort(Q.begin(), Q.end(), sort_compare);
          int temp[3] = { 0, 0, 0 };
          for(int a = 0; a < N; a++){
            int t;
            if(S[a] == 'r') t = Q[0][temp[0]++];
            else if(S[a] == 'g') t = Q[1][temp[1]++];
            else t = Q[2][temp[2]++];

            P[a + 1] = 1 + t;
          }
          mergesort(P, 1, N);
          min_inv_count = min(min_inv_count, inv_count);
        }
      }
    }

    cout << min_inv_count << endl;
  }
}
