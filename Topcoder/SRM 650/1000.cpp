// The Kings Roads

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void dfs(int curr, vector<vector<int> >& graph, vector<int>& indegree, vector<bool>& visited){
	if(visited[curr]) return;
	
	visited[curr] = true;
	for(auto v: graph[curr]){
		indegree[v]++;
		dfs(v, graph, indegree, visited);
	}
}

bool correctGraph(vector<vector<int> >& graph, int N, int h){
	vector<int> indegree(N + 1, 0);
	vector<bool> visited(N + 1, false);
	dfs(1, graph, indegree, visited);
	
	int root_nodes = 0, mid_nodes = 0, leaf_nodes = 0, other = 0;
	
	for(int i = 1; i <= N; i++){
		if(indegree[i] == 2) root_nodes++;
		else if(indegree[i] == 3) mid_nodes++;
		else if(indegree[i] == 1) leaf_nodes++;
		else other++;
	}
	
	return (root_nodes == 1 && mid_nodes == (N - 1 - (1 << (h - 1))) && leaf_nodes == (1 << (h - 1)) && other == 0);
}

class TheKingsRoadsDiv2 {
	public:
	string getAnswer(int h, vector <int> a, vector <int> b) {
		int N = (1 << h) - 1;
		int M = a.size();
		vector<vector<int> > graph(N + 1);
		for(int i = 0; i < M; i++){
			graph[a[i]].push_back(b[i]);
			graph[b[i]].push_back(a[i]);
		}
		
		vector<vector<int> > graph_temp;
		for(int i = 0; i < M; i++){
			graph_temp = graph;
			graph_temp[a[i]].erase(find(graph_temp[a[i]].begin(), graph_temp[a[i]].end(), b[i]));
			graph_temp[b[i]].erase(find(graph_temp[b[i]].begin(), graph_temp[b[i]].end(), a[i]));
			if(correctGraph(graph_temp, N, h)) return "Correct";
		}
		
		return "Incorrect";
	}
};
