#include "testlib.h"

#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cmath>

#define forn(i, n) for(int i=0;i<n;++i)
#define fore(i, l, r) for(int i = int(l); i <= int(r); ++i)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define x first
#define y1 ________y1
#define y second
#define ft first
#define sc second
#define pt pair<int, int>

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int x1 = rnd.next(-1000, -1);
    int y1 = rnd.next(-1000, -1);
    int len1 = atoi(argv[1]);
    int len2 = atoi(argv[2]);
    int x2 = x1 + len1;
    int y2 = y1 + len2;
    vector<pair<pair<int, int>, pair<int, int> > > a;
    for(int x = x1; x <= x2; x++)
    {          
     int szcur = rnd.next(0, 10);
     vector<int>cur;
  if (szcur % 2) szcur++;
     for(int i = 0; i < szcur; i++)
      cur.pb(rnd.next(y1, y2));
     sort(all(cur));
     for(int i = 0; i < sz(cur); i += 2)
      a.pb(mp(mp(x, cur[i]), mp(x, cur[i + 1])));
    }
    for(int y = y1; y <= y2; y++)
    {
     int szcur = rnd.next(0, 10);
     vector<int>cur;
  if (szcur % 2) szcur++;
     for(int i = 0; i < szcur; i++)
      cur.pb(rnd.next(x1, x2));
     sort(all(cur));
     for(int i = 0; i < sz(cur); i += 2)
      a.pb(mp(mp(cur[i], y), mp(cur[i + 1], y)));
    }
    shuffle(all(a));
    int n = min(sz(a), 100 * 1000);
    cout << n << endl;
    for(int i = 0; i < n; i++)
    {
     if(rnd.next(0, 1))
      swap(a[i].ft, a[i].sc);
     cout << a[i].ft.ft << ' ' << a[i].ft.sc << ' ' << a[i].sc.ft << ' ' << a[i].sc.sc << endl;
    }
}

