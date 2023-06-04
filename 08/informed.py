exec(open('search.py').read())
# from search import *

heuristic = {
    'Arad': 366,     'Bucharest': 0,  'Craiova': 160, 
    'Dobreta': 242,  'Eforie': 161,   'Fagras': 176,
    'Giurgiu': 77,   'Hirsova': 161,  'Iasi': 226,
    'Lugoj': 244,    'Mehadia': 241,  'Neamt': 234,
    'Oradea': 380,   'Pitesti': 100,  'Rimnicu_Vilcea': 193,
    'Sibiu': 253,    'Timisoara': 329,'Urziceni': 80,
    'Vaslui': 199,    'Zerind': 374
}

def remove_front(fringe):
    fringe.sort(key = lambda x: heuristic[x.state])
    # print(["{} {}".format(x.state, heuristic[x.state]) for x in fringe])
    ret = fringe[0]
    del(fringe[0]) # remove first element
    return ret

print("== best first search")
tree_search(problem, Node(None, 'Arad'), lambda x: x.state == 'Bucharest')

def remove_front(fringe):
    fringe.sort(key = lambda x: x.path_cost + heuristic[x.state])
    # print(["{} {} + {}".format(x.state, x.path_cost, heuristic[x.state]) for x in fringe])
    ret = fringe[0]
    del(fringe[0]) # remove first element
    return ret

print("== a* search")
tree_search(problem, Node(None, 'Arad'), lambda x: x.state == 'Bucharest')
