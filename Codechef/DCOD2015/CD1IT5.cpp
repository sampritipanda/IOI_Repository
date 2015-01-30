// Connecting Islands

#include <iostream>

using namespace std;

int find_group(int group[], int x) {
	if (x == group[x]) return x;
	return group[x] = find_group(group, group[x]);
}

void merge_group(int group[], int a, int b) {
	a = find_group(group, a);
	b = find_group(group, b);
	if (a != b) group[a] = b;
}

int main() {
    int N, Q; cin >> N >> Q;
    int group[N + 1];
    for(int i = 1; i <= N; i++) group[i] = i;

    while(Q--){
        int t, x, y; cin >> t >> x >> y;
        if(t == 0){
            merge_group(group, x, y);
        }
        else {
            if(find_group(group, x) == find_group(group, y)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
