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

def dfs(graph, start, target):
    fringe = [start]
    while fringe:
        node = fringe.pop()
        print("traverse {}".format(node))
        if node == target:
            print("found target {}".format(node))
            return node
        for n in reversed(graph[node]): ## added reversed just for text book
            fringe.append(n)
    return None


print("dfs")
print(dfs(graph, 'A', 'D'))
print(dfs(graph, 'A', 'M'))
