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

'''
** recursive version of dfs **

def dfs(graph, node, target):
    print("traverse {}".format(node))
    if node == target:
        print("found target {}".format(node))
        return node
    for n in graph[node]: ## added reversed just for text book
        ret = dfs(graph, n, target)
        if ret != None:
            return ret
    return None
'''

def dlfs(graph, node, target, depth_limit, limit = 0):
    cutoff_occured = False
    print("traverse {}, level {}".format(node, limit))
    limit = limit + 1
    if node == target:
        print("found target {}".format(node))
        return node
    elif limit > depth_limit:
        return 'cutoff'
    for n in graph[node]: ## added reversed just for text book
        ret = dlfs(graph, n, target, depth_limit, limit)
        if ret == 'cutoff':
            cutoff_occured = True
        elif ret != None:
            return ret
    if cutoff_occured:
        return 'cutoff'
    else:
        return None

print("limited-dfs")
print(dlfs(graph, 'A', 'M', 0))
print(dlfs(graph, 'A', 'M', 1))
print(dlfs(graph, 'A', 'M', 2))
print(dlfs(graph, 'A', 'M', 3))
