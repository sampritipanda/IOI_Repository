// Tavas and Karafs

#include <iostream>

using namespace std;

long long A, B, n, t, m, l;

bool possible(long long r){
  long long start = A + (l - 1) * B;
  long long end = A + (r - 1) * B;
  long long sum = ((r - l + 1) * (start + end))/2;
  long long max_pos = t * (min(r - l + 1, m));

  if(m >= (r - l + 1)){
    if(t > end) return true;
    else return false;
  }

  if(max_pos >= sum) return true;
  else return false;
}

int main() {
  cin >> A >> B >> n;

  while(n--){
    cin >> l >> t >> m;
    if(!possible(l)) {
      cout << -1 << endl;
      continue;
    }
    long long r = l + 2, i = 2;
    while(possible(r)){
      i *= 2;
      r += i;
    }

    long long imin = l, imax = r;
    while(imin < imax){
      long long imid = (imin+imax)>>1;
      if(!(imid < imax)) return 0;
      if(possible(imax)) {
        imin = imid + 1;
      }
      else {
        imax = imid;
      }
    }
    if(imax != imin) {
      cout << -1 << endl;
    }
    else {
      cout << imin << endl;
    }
  }
}
