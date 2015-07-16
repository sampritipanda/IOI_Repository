
# read the number of vertices and the number of directed edges

N = int( raw_input() )
assert 1 <= N <= 60

M = int( raw_input() )
assert 0 <= M <= N*(N-1)

# read the list of edges, check that there are no duplicates

outgoing_edges = [ {} for n in range(N) ]

for m in range(M):
    v_from, v_to, length = [ int(x) for x in raw_input().split() ]

    assert        0 <= v_from <= N-1
    assert        0 <= v_to   <= N-1
    assert -(2**31) <= length <= (2**31)-1

    assert v_from != v_to
    assert v_to not in outgoing_edges[v_from]

    outgoing_edges[v_from][v_to] = length

# initialize the list of distances

distance = [ 10**18 for n in range(N) ]
distance[0] = 0

# initialize the priority queue

from heapq import heappush, heappop
priority_queue = []
heappush( priority_queue, (0,0) )

# main loop: while there is an active vertex, process it

PROCESSED_VERTICES = 0

while len(priority_queue) > 0:
    how_far, where = heappop(priority_queue)
    if distance[where] != how_far: continue # discarding an old record

    PROCESSED_VERTICES += 1

    for goal in outgoing_edges[where]:
        if how_far + outgoing_edges[where][goal] < distance[goal]:
            distance[goal] = how_far + outgoing_edges[where][goal]
            heappush( priority_queue, ( distance[goal], goal ) )

print PROCESSED_VERTICES
