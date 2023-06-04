graph = {
    'A' : ['B','C'],
    'B' : ['D','E'],
    'C' : ['F','G'],
    'D' : ['H','I'],
    'E' : ['J','K'],
    'F' : ['L','M'],
    'G' : ['N','O'],
    'H' : [], 'I' : [], 'J' : [], 'K' : [], 'L' : [], 'M' : [], 'N' : [], 'O' : []
}

def bfs(graph, start, target):
    fringe = [start]
    while fringe:
        node = fringe[0]; fringe = fringe[1:] # pop
        print("traverse {}".format(node))
        if node == target:
            print("found target {}".format(node))
            return node
        for n in graph[node]:
            fringe.append(n)
    return None

print("bfs")
print(bfs(graph, 'A', 'D'))
