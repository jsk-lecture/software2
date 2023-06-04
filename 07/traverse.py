# Using a Python dictionary to act as an adjacency list
graph = {
    '+' : ['2','*'],
    '2' : [],
    '*' : ['3', '4'],
    '3' : [],
    '4' : [],
}

def pre_order(graph, root):
    res = []
    if root:
        res.append(root)
        res = res + pre_order(graph,
                              graph[root][0] if len(graph[root])>=1 else None)
        res = res + pre_order(graph,
                              graph[root][1] if len(graph[root])>=2 else None)
    return res

def in_order(graph, root):
    res = []
    if root:
        res = res + in_order(graph,
                             graph[root][0] if len(graph[root])>=1 else None)
        res.append(root)
        res = res + in_order(graph,
                             graph[root][1] if len(graph[root])>=2 else None)
    return res

def post_order(graph, root):
    res = []
    if root:
        res = res + post_order(graph,
                               graph[root][0] if len(graph[root])>=1 else None)
        res = res + post_order(graph,
                               graph[root][1] if len(graph[root])>=2 else None)
        res.append(root)
    return res

'''
def pre_order(graph, root):
    res = []
    if root:
        res.append(root)
        for node in graph[root]:
            res = res + pre_order(graph, node)
    return res

def in_order(graph, root):
    res = []
    if root:
        res = res + in_order(graph,
                             graph[root][0] if len(graph[root])>=1 else None)
        res.append(root)
        res = res + in_order(graph,
                             graph[root][1] if len(graph[root])>=2 else None)
    return res

def post_order(graph, root):
    res = []
    if root:
        for node in graph[root]:
            res = res + post_order(graph, node)
        res.append(root)
    return res
'''

print(pre_order(graph, '+'))
print(in_order(graph, '+'))
print(post_order(graph, '+'))
