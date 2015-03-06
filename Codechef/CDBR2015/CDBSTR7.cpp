// Rising population

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int T; cin >> T;

    while(T--){
        string a, b; cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a == b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
