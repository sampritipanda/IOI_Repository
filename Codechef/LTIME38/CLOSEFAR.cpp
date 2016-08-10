// http://codeforces.com/blog/entry/43230  -  Thanks Animesh

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 35005;
const int MAXM = 35005;
const int LN = 16;

int N, M, K, cur, A[MAXN], LVL[MAXN], DP[LN][MAXN];
int BL[MAXN << 1], ID[MAXN << 1], VAL[MAXN], ANS[MAXM];
int l[MAXN], r[MAXN];
bool VIS[MAXN];
vector < int > adjList[MAXN];
set<int> vals;
multiset<int> diffs;

struct query{
  char type;
	int id, l, r, lc;
	bool operator < (const query& rhs){
		return (BL[l] == BL[rhs.l]) ? (r < rhs.r) : (BL[l] < BL[rhs.l]);
	}
}Q[MAXM];

// Set up Stuff
void dfs(int u, int par){
	l[u] = ++cur;
	ID[cur] = u;
	for (int i = 1; i < LN; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
	for (int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		if (v == par) continue;
		LVL[v] = LVL[u] + 1;
		DP[0][v] = u;
		dfs(v, u);
	}
	r[u] = ++cur; ID[cur] = u;
}

// Function returns lca of (u) and (v)
inline int lca(int u, int v){
	if (LVL[u] > LVL[v]) swap(u, v);
	for (int i = LN - 1; i >= 0; i--)
		if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
	if (u == v) return u;
	for (int i = LN - 1; i >= 0; i--){
		if (DP[i][u] != DP[i][v]){
			u = DP[i][u];
			v = DP[i][v];
		}
	}
	return DP[0][u];
}

inline void check(int x){
	// If (x) occurs twice, then don't consider it's value
	if ( (VIS[x]) ) {
    // delete
    auto it = vals.find(A[x]);
    int small = -1, large = -1;
    if(A[x] != *vals.begin()) {
      it--;
      small = *it;
      diffs.erase(diffs.find(A[x] - *it));
      it++;
    }
    if(A[x] != *vals.rbegin()) {
      it++;
      diffs.erase(diffs.find(*it - A[x]));
      large = *it;
      it--;
    }
    if(small != -1 && large != -1) {
      diffs.insert(large - small);
    }
    vals.erase(it);
  }
	else if ( (!VIS[x]) ) {
    // add
    vals.insert(A[x]);
    auto it = vals.find(A[x]);
    int small = -1, large = -1;
    if(A[x] != *vals.begin()) {
      it--;
      diffs.insert(A[x] - *it);
      small = *it;
      it++;
    }
    if(A[x] != *vals.rbegin()) {
      it++;
      diffs.insert(*it - A[x]);
      large = *it;
      it--;
    }
    if(small != -1 && large != -1) {
      diffs.erase(diffs.find(large - small));
    }
  }
	VIS[x] ^= 1;
}

void compute(){
	// Perform standard Mo's Algorithm
	int curL = Q[0].l, curR = Q[0].l - 1;

	for (int i = 0; i < M; i++){

		while (curL < Q[i].l) check(ID[curL++]);
		while (curL > Q[i].l) check(ID[--curL]);
		while (curR < Q[i].r) check(ID[++curR]);
		while (curR > Q[i].r) check(ID[curR--]);

		int u = ID[curL], v = ID[curR];

		// Case 2
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc);

    if(Q[i].type == 'C') {
      ANS[Q[i].id] = *diffs.begin();
    }
    else {
      ANS[Q[i].id] = *vals.rbegin() - *vals.begin();
    }

		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc);
	}

	for (int i = 0; i < M; i++) printf("%d\n", ANS[i]);
}

int main(){
  char t;
	int u, v, x;
  int N; scanf("%d", &N);

  // Cleanup
  cur = 0;
  memset(VIS, 0, sizeof(VIS));
  memset(VAL, 0, sizeof(VAL));
  for (int i = 1; i <= N; i++) adjList[i].clear();
  vals.clear();
  diffs.clear();

  // Inputting Values
  for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

  // Inputting Tree
  for (int i = 1; i < N; i++){
    scanf("%d %d", &u, &v);
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  // Preprocess
  DP[0][1] = 1;
  dfs(1, -1);
  int size = 620;

  for (int i = 1; i <= cur; i++) BL[i] = (i - 1) / size + 1;

  scanf("%d", &M);
  for (int i = 0; i < M; i++){
    scanf(" %c %d %d ", &t, &u, &v);
    Q[i].type = t;
    Q[i].lc = lca(u, v);
    if (l[u] > l[v]) swap(u, v);
    if (Q[i].lc == u) Q[i].l = l[u], Q[i].r = l[v];
    else Q[i].l = r[u], Q[i].r = l[v];
    Q[i].id = i;
  }

  sort(Q, Q + M);
  compute();
}

