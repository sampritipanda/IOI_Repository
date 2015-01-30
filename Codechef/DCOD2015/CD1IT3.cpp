// Complementary Couples

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    unsigned long long N, K; cin >> N >> K;
    vector<unsigned long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    unordered_map<int, bool> map;

    bool flag = false;
    for(int i = 0; i < N; i++){
        unsigned long long temp = K - A[i];
        if(temp >= 0 && map[temp]) {
            flag = true;
            break;
        }
        map[A[i]] = true;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
