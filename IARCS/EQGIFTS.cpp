// Equal Gifts

#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool sort_compare(pair<int, int> a, pair<int, int> b){
    return abs(a.second - a.first) > abs(b.second - b.first);
}

int main() {
	int N; scanf("%d", &N);
	vector<pair<int, int> > books(N);

	for(int i = 0; i < N; i++){
		int a, b; scanf("%d %d", &a, &b);
		books.push_back(make_pair(a, b));
	}
	sort(books.begin(), books.end(), sort_compare);

	int lavanya = 0, nikhil = 0;
	for(vector<pair<int, int> >::iterator it = books.begin(); it != books.end(); it++){
        if(lavanya < nikhil){
            lavanya += max(it->first, it->second);
            nikhil += min(it->first, it->second);
        }
        else {
            lavanya += min(it->first, it->second);
            nikhil += max(it->first, it->second);
        }
	}

	printf("%d\n", abs(lavanya - nikhil));
}
