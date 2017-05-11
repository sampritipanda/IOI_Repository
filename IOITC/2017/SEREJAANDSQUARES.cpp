#include <cstdio>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> points[100001];
vector<int> small, large;
const int BLOCK_SIZE = 500;
int rev_X[250][100001];
int rev_large_id[100001];

int main() {
	int N; scanf("%d", &N);
	
	for(int i = 0; i < N; i++) {
		int x, y; scanf("%d %d", &x, &y);
		points[y].push_back(x);
	}
	for(int y = 0; y <= 100000; y++) {
		if(points[y].size() > 0) sort(points[y].begin(), points[y].end());
	}
	
	for(int y = 0; y <= 100000; y++) {
		if(points[y].size() == 0) continue;
		if(points[y].size() <= BLOCK_SIZE) small.push_back(y);
		else large.push_back(y);
	}
		
	for(int i = 0; i <= 100000; i++) rev_large_id[i] = -1;
	
	for(int i = 0; i < large.size(); i++) {
		rev_large_id[large[i]] = i;
		for(int x: points[large[i]]) {
			rev_X[i][x] = 1;
		}
	}
	
	long long ans = 0;
	
	for(int y: small) {
		for(int j = 0; j < points[y].size(); j++) {
			for(int k = j + 1; k < points[y].size(); k++) {
				int d = points[y][k] - points[y][j];
				if(y + d <= 100000 && points[y + d].size() > 0) {
					if(rev_large_id[y + d] != -1) {
						int id = rev_large_id[y + d];
						if(rev_X[id][points[y][j]] && rev_X[id][points[y][k]]) {
							ans++;
						}
					}
					else {					
						if(binary_search(points[y + d].begin(), points[y + d].end(), points[y][j])
						   && binary_search(points[y + d].begin(), points[y + d].end(), points[y][k])) {
							ans++;
						}
					}
				}
				if(y - d >= 0 && points[y - d].size() > 0 && rev_large_id[y - d] != -1) {
            int id = rev_large_id[y - d];
            if(rev_X[id][points[y][j]] && rev_X[id][points[y][k]]) {
              ans++;
            }
        }
			}
		}
	}
	
	for(int i1 = 0; i1 < large.size(); i1++) {
		for(int i2 = i1 + 1; i2 < large.size(); i2++) {
			int y1 = large[i1], y2 = large[i2];
			int d = y2 - y1;
			int L = 0;
			for(int R = 0; R < points[y1].size(); R++) {
				while(points[y1][R] - points[y1][L] > d) {
					L++;
				}
				if(points[y1][R] - points[y1][L] == d && rev_X[i2][points[y1][L]] && rev_X[i2][points[y1][R]]) ans++;
			}
		}
	}
	
	printf("%lld\n", ans);
}
