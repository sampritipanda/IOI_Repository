// Dividing the Students

#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

#define pii std::pair<int, int>
#define vi std::vector<int>

bool myfunction (const pii i, const pii j) {
  return (i.second<j.second);
}

int modPow(long long b, long long e){
  long long mod = 1000000007;
  long long res = 1;
  b %= mod;
  while(e){
    if(e % 2 == 1){
      res = (res * b) % mod;
    }
    e >>= 1;
    b = (b*b) % mod;
  }
  return res;
}

inline int min(int a, int b){
  if(a < b) return a;
  else return b;
}

int main(){
  int T; scanf("%d", &T);
  int N;

  vi A;
  std::vector<pii> studs;
  std::vector<pii> studs_pairs;
  std::vector<pii> memo;

  while(T--){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
      int x;
      scanf("%d", &x);
      A.push_back(x);
    }

    for(int i = 0; i < N; i++){
      for(int j = i + 1; j < N; j++){
        int val_1 = modPow(A[i], A[j]);
        int val_2 = modPow(A[j], A[i]);
        int val = min(val_1, val_2);

        studs.push_back(std::make_pair(studs.size(), val));
        studs_pairs.push_back(std::make_pair(A[i], A[j]));
      }
    }

    std::sort(studs.begin(), studs.end(), myfunction);

    bool flag = true;
    while(flag){
      pii& x = studs.back();
      pii& y = studs_pairs[x.first];

      vi list1, list2;

      for(std::vector<pii>::iterator it = memo.begin(); it != memo.end(); it++){
        if(y.first == it->first) list1.push_back(it->second);
        else if(y.first == it->second) list1.push_back(it->first);

        if(y.second == it->first) list2.push_back(it->second);
        else if(y.second == it->second) list2.push_back(it->first);
      }

      for(vi::iterator it = list1.begin(); it != list1.end(); it++){
        for(vi::iterator jt = list2.begin(); jt != list2.end(); jt++){
          if(*it == *jt){
            flag = false;
            break;
          }
        }
      }

      if(flag){
        studs.pop_back();
        memo.push_back(y);
      }
    }

    A.clear();
    memo.clear();
    printf("%d\n", studs.back().second);
  }
}
