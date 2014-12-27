// Number of Routings

#include <stdio.h>
#include <vector>

using namespace std;

int dfs(vector<vector<int> >& graph, int v, int target, int depth){
	if(depth == 0){
		return (v == target);
	}
	int sum_paths = 0;
	for(vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); ++it){
		sum_paths += dfs(graph, *it, target, depth - 1);
	}
	return (sum_paths % 42373);
}

int main() {
	int N; scanf("%d", &N);
	vector<vector<int> > graph(N);

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int val; scanf("%d", &val);
			while(val--){
				graph[i].push_back(j);
			}
		}
	}

	int S, T, K; scanf("%d %d %d", &S, &T, &K);
	S--; T--;

	int num_paths = dfs(graph, S, T, K);
	printf("%d\n", num_paths);
}
