#include <cassert>
#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {

    // read the number of vertices and the number of directed edges

    int N; cin >> N;
    assert(cin);
    assert(1 <= N && N <= 60);

    int M; cin >> M;
    assert(cin);
    assert(0 <= M && M <= N*(N-1));

    // read the list of edges, check that there are no duplicates

    vector< unordered_map<int,int> > outgoing_edges(N);

    for (int m=0; m<M; ++m) {
        int v_from, v_to, length;
        cin >> v_from >> v_to >> length;
        assert(cin);
        assert(0 <= v_from && v_from <= N-1);
        assert(0 <= v_to   && v_to   <= N-1);
        assert(v_from != v_to);
        assert(outgoing_edges[v_from].count(v_to) == 0);

        outgoing_edges[v_from][v_to] = length;
    }

    // initialize the list of distances

    vector<long long> distance( N, pow(10,18) );
    distance[0] = 0;

    // initialize the priority queue

    priority_queue< pair<long long,int>, vector< pair<long long,int> >, greater< pair<long long,int> > > PQ;
    PQ.push( {0,0} );

    long long PROCESSED_VERTICES = 0;

    // main loop: while there is an active vertex, process it

    while (!PQ.empty()) {
        long long how_far = PQ.top().first;
        int where = PQ.top().second;
        PQ.pop();
        if (distance[where] != how_far) continue; // discarding an old record

        ++PROCESSED_VERTICES;

        for (auto edge : outgoing_edges[where]) {
            if (how_far + edge.second < distance[edge.first]) {
                distance[edge.first] = how_far + edge.second;
                PQ.push( { distance[edge.first], edge.first } );
            }
        }
    }

    cout << PROCESSED_VERTICES << endl;
}
