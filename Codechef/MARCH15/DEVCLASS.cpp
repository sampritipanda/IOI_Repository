// Devu and his Class

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
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

int main() {
  int T; cin >> T;

  while(T--){
    int type; cin >> type;
    string s; cin >> s;
    N = s.length();

    int B = 0, G = 0;
    for(auto c: s){
      if(c == 'B') B++;
      else G++;
    }

    if(abs(B - G) > 1){
      cout << -1 << endl;
    }
    else {
      vector<string> sequences;
      if(B == G){
        string s, t;
        for(int i = 0; i < N; i++){
          if(i % 2 == 0) s += 'B';
          else s += 'G';
        }
        for(int i = 0; i < N; i++){
          if(i % 2 == 1) t += 'B';
          else t += 'G';
        }
        sequences.push_back(s);
        sequences.push_back(t);
      }
      else {
        string s;
        char greater = (B > G ? 'B' : 'G');
        for(int i = 0; i < N - 1; i++){
          if(i % 2 == 0) s += greater;
          else s += (greater == 'B' ? 'G' : 'B');
        }
        s += greater;
        sequences.push_back(s);
      }

      if(type == 0){
        long long swaps = LLONG_MAX;
        for(auto curr: sequences){
          long long curr_swaps = 0;
          for(int i = 0; i < N; i++){
            if(s[i] != curr[i]) curr_swaps++;
          }
          swaps = min(swaps, curr_swaps/2);
        }

        cout << swaps << endl;
      }
      else {
        long long min_inv_count = LLONG_MAX;
        for(auto curr: sequences){
          inv_count = 0;
          vector<int> Q[2];
          int P[N + 1];
          for(int a = 0; a < N; a++) {
            if(curr[a] == 'B') Q[0].push_back(a);
            else Q[1].push_back(a);
          }
          // sort(Q.begin(), Q.end(), sort_compare);
          int temp[2] = { 0, 0 };
          for(int a = 0; a < N; a++){
            int t;
            if(s[a] == 'B') t = Q[0][temp[0]++];
            else t = Q[1][temp[1]++];

            P[a + 1] = 1 + t;
          }
          mergesort(P, 1, N);
          min_inv_count = min(min_inv_count, inv_count);
        }

        cout << min_inv_count << endl;
      }
    }
  }
}
