// Tavas and Karafs

#include <iostream>

using namespace std;

long long A, B, n, l, t, m;

long long term(int i){
  return A + (i - 1) * B;
}

int main() {
  cin >> A >> B >> n;

  while (n--) {
    cin >> l >> t >> m;
    if (term(l) > t) {
      cout << -1 << endl;
      continue;
    }
    if (term(l + m) > t) {
      long long r = l + 2, i = 2;
      while(!term(r) > t){
        i *= 2;
        r += i;
      }

      long long imin = l, imax = r;
      while(imin < imax){
        long long imid = (imin+imax)>>1;
        if(!(imid < imax)) return 0;
        if(term(imax) > t) {
          imax = imid;
        }
        else {
          imin = imid + 1;
        }
      }
      if(imax != imin) {
        cout << -1 << endl;
      }
      else {
        cout << imin << endl;
      }
    }
    else {
      long long r = l + m, count = t - term(l);
      for (int i = m; count > 0; i++) {
        long long curr = (i - l) * m;
        if (curr <= count ) {
          count -= curr;
          r = i;
        }
      }
      cout << r << endl;
    }
  }
}

