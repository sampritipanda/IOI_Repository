#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//{{{
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#ifdef DEBUG
    #define _debug(args...) { fprintf(stderr, args); fflush(stderr); }
#else
    #define _debug(args...) {}
#endif
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }
template<class T> T absv(T _x) { return _x>0?_x:-_x; }
//}}}

int n; LL A, B, C[100010];

void read_input() {
    cin>>n>>A>>B;
    rep(i, 1, n) cin>>C[i];
}

double R(LL N) {
    LL s=0; rep(i, 1, n) s+=C[i];
    if(N>s) {
        return R(s)*double(N/s) + R(N%s);
    }
    double ans=0;
    rep(i, 1, n) {
        if(N<C[i]) {
            ans+=double(N)*double(N)/2;
            break;
        }
        ans+=double(C[i])*double(C[i])/2;
        N-=C[i];
    }
    return ans;
}

double solve() {
    double b=R(B), a=R(A);
    return (b-a)/double(B-A);
}

int main() {
    int csn; scanf("%d", &csn);
    rep(cs, 1, csn) {
        read_input();
        double ans=solve();
        printf("Case #%d: %.10lf\n", cs, ans);
    }
    return 0;
}

