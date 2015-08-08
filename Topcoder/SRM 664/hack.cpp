#line 7 "BearSortsDiv2.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;


const double LOG2 = log(0.5);
class BearSortsDiv2
{
  map <int, int> ind;
  int ret;
  public:
  double getProbability(vector <int> seq)
  {
      ind.clear();
      ret = 0;

      int n = seq.size();
      for (int i = 0; i < n; i++) ind[seq[i]] = i;
      sort(seq.begin(), seq.end());
      merge(seq);
      return  LOG2 * ret;
  }

  vector <int> merge(vector <int> seq) {
    int n = seq.size();
    if (n <= 1) return seq;
    vector <int> left = merge(vector <int>(seq.begin(), seq.begin() + n/2));
    vector <int> right = merge(vector <int>(seq.begin() + n/2, seq.end()));
    vector <int> ans(n);
    int p = 0, q = 0, k = 0;
    int m = left.size(); n = right.size();

    while (p < m || q < n) {
      if (p == m) ans[k++] = right[q++];
      else if (q == n) ans[k++] = left[p++];
      else {
        if (ind[left[p]] > ind[right[q]]) ans[k++] = right[q++];
        else ans[k++] = left[p++];
        ret++;
      }
    }
    return ans;
  }
        

};

int main() {
  BearSortsDiv2 test;
  cout << test.getProbability({7, 6, 2, 11, 19, 5, 17, 15, 8, 4, 14, 3, 20, 9, 10, 18, 13, 12, 1, 16}) << endl;
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
