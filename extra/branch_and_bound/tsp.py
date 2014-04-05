from Queue import PriorityQueue 
import sys

def display_graph(g):
    for i in xrange(len(g)):
        print "|", " ".join("%2d" % j for j in g[i]) 

def calculated_distance(graph, path):
    distance = 0
    distance_string = []
    for i in xrange(len(path) - 1):
        j = i + 1
        distance += graph[path[i]][path[j]]
        distance_string.append("%d -> %d [%d]" % (i, j, graph[path[i]][path[j]])) 
    #print ", ".join(distance_string)
    return distance

def get_alternatives(graph, node, visited, path):
    unvisited = []
    
    if len(visited) == len(graph) and graph[node][0] > 0:
        path.append(0)
        return [(calculated_distance(graph, path), (0, path, visited),)]

    for j in xrange(len(graph[node])):
        if j == 0 or j in visited:
            continue
        unvisited.append(j)
    alternatives = []
    for u in unvisited:
        npath = path + [u]
        nvisited = set(visited)
        nvisited.add(u)
        distance = calculated_distance(graph, npath)
        alternatives.append((distance, (u, npath , nvisited,),))
    return alternatives

def solve(graph, start):
    pass

if __name__ == '__main__':
    graph = [
        [0, 3, 2, 5],
        [2, 0, 4, 2],
        [3, 1, 0, 6],
        [4, 5, 1, 0]
    ]
    display_graph(graph)
    pq = PriorityQueue()
    visited = set([])
    pq.put((0, (0, [0], set([0]),),))
    min_distance_wise = sys.maxint, []

    while not pq.empty():
        distance, (node, npath, nvisited) = pq.get()

        if len(graph) == len(nvisited) and len(npath) == len(graph) + 1:
            if min_distance_wise[0] > distance:
                min_distance_wise = distance, npath 
                print "D: %2d, [%2d, P: %s, V: %s]" % (distance, node, npath, nvisited)
        alternatives = get_alternatives(graph, node, nvisited, npath)
        for a in alternatives:
            pq.put(a) 

    print min_distance_wise
