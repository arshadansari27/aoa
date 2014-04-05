def solve_recursively(edges, colored, colors, i):
    #print i, colored 
    if all(v in colored.keys() for v in xrange(len(edges[i])) if edges[i][v] == 1):
        return colored 
    for j in xrange(len(edges[i])):
        if j in colored.keys() or edges[i][j]== 0:
            continue
        for k in xrange(colors):
            p = [(u in colored.keys() and colored[u] == k ) for u in xrange(len(edges[j])) if edges[j][u] is 1]
            v = any(p)
            if v:
                continue
            ncolored = {}
            for l, m in colored.iteritems():
                ncolored[l] = m
            ncolored[j] = k
            val = solve_recursively(edges, ncolored, colors, j)
            if val is not False:
                return val
    return False

def color_graph(edges, colors):
    for i in xrange(colors):
        value = solve_recursively(edges, {0: i}, colors, 0)
        if value:
            return value 

if __name__ == '__main__':
    edges = [
                [0, 1, 1, 0, 0, 0],
                [1, 0, 1, 1, 0, 0],
                [1, 1, 0, 0, 1, 0],
                [0, 1, 0, 0, 1, 1],
                [0, 0, 1, 1, 0, 1],
                [0, 0, 0, 1, 1, 0],
            ]
    colors = 3
    print color_graph(edges, colors)
