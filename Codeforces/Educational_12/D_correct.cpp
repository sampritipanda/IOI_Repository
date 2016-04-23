#include <bits/stdc++.h>
using namespace std;
#define PI  acos(-1.0)
#define lb  lower_bound
#define ub  upper_bound
#define pb  push_back
#define mp  make_pair
#define fs  first
#define sc  second
#define ll  long long
#define vi  vector<int>
#define vvi vector<vi >
#define mit map<int>::iterator
#define all(x) x.begin(), x.end()
 
int n;
vi  v;

bool pr(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(all(v));
    int ones = 0;
    int oddd = 0;
    int even = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == 1)
            ++ones;
        if (v[i] & 1)
            ++oddd;
        else
            ++even;
    }
    if (even == n) {
        cout << 1 << endl;
        cout << v[0] << endl;
    }
    else if (oddd == n) {
        if (ones > 0) {
            cout << ones << endl;
            for (int i = 0; i < ones; ++i)
                cout << 1 << " ";
            cout << endl;
        }
        else {
            cout << 1 << endl;
            cout << v[0] << endl;
        }
    }
    else {
        if (ones < 2) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (pr((v[i] + v[j]))) {
                        cout << 2 << endl;
                        cout << v[i] << " " << v[j] << endl;
                        return 0;
                    }
                }
            }
            cout << 1 << endl;
            cout << v[0] << endl;
            return 0;
        }
        else {
            int j = -1;
            for (int i = 0; i < n; ++i) {
                if (v[i] > 1 && pr(v[i] + 1))
                    j = i;
            }
            if (j != -1)
                ++ones;
            cout << ones << endl;
            for (int i = 0; i < n; ++i) {
                if (v[i] == 1 || i == j)
                    cout << v[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
} 
