problem = {
    'Arad': ['Zerind', 'Timisoara', 'Sibiu'],
    'Bucharest': ['Urziceni', 'Giurgiu', 'Pitesti', 'Fagras'],
    'Craiova': ['Dobreta', 'Pitesti', 'Rimnicu_Vilcea'],
    'Dobreta': ['Mehadia', 'Craiova'],
    'Eforie': ['Hirsova'],
    'Fagras': ['Sibiu', 'Bucharest'],
    'Giurgiu': ['Bucharest'],
    'Hirsova': ['Eforie', 'Urziceni'],
    'Iasi': ['Neamt', 'Vaslui'],
    'Lugoj': ['Mehadia', 'Timisoara'],
    'Mehadia': ['Lugoj', 'Dobreta'],
    'Neamt': ['Iasi'],
    'Oradea': ['Zerind', 'Sibiu'],
    'Pitesti': ['Rimnicu_Vilcea', 'Bucharest', 'Craiova'],
    'Rimnicu_Vilcea': ['Sibiu', 'Pitesti', 'Craiova'],
    'Sibiu': ['Rimnicu_Vilcea', 'Fagras', 'Oradea', 'Arad'],
    'Timisoara': ['Lugoj', 'Arad'],
    'Urziceni': ['Bucharest', 'Hirsova', 'Vaslui'],
    'Vaslui': ['Iasi', 'Urziceni'],
    'Zerind': ['Oradea', 'Arad'],
}

step_cost = {
    'Arad': {'Zerind': 75, 'Timisoara': 188, 'Sibiu': 140},
    'Bucharest': {'Urziceni': 85, 'Giurgiu': 90, 'Pitesti': 101, 'Fagras': 221},
    'Craiova': {'Dobreta': 120, 'Pitesti': 138, 'Rimnicu_Vilcea': 146},
    'Dobreta': {'Mehadia': 75, 'Craiova': 120},
    'Eforie': {'Hirsova': 86},
    'Fagras': {'Sibiu': 99, 'Bucharest': 211},
    'Giurgiu': {'Bucharest': 90},
    'Hirsova': {'Eforie': 86, 'Urziceni': 98},
    'Iasi': {'Neamt': 87, 'Vaslui': 92},
    'Lugoj': {'Mehadia': 70, 'Timisoara': 111},
    'Mehadia': {'Lugoj': 70, 'Dobreta': 75},
    'Neamt': {'Iasi': 87},
    'Oradea': {'Zerind': 71, 'Sibiu': 151},
    'Pitesti': {'Rimnicu_Vilcea': 97, 'Bucharest': 101, 'Craiova': 138},
    'Rimnicu_Vilcea': {'Sibiu': 80, 'Pitesti': 97, 'Craiova': 146},
    'Sibiu': {'Rimnicu_Vilcea': 80, 'Fagras': 99, 'Oradea': 140, 'Arad': 151},
    'Timisoara': {'Lugoj': 111, 'Arad': 118},
    'Urziceni': {'Bucharest': 85, 'Hirsova': 98, 'Vaslui': 142},
    'Vaslui': {'Iasi': 92, 'Urziceni': 142},
    'Zerind': {'Oradea': 71, 'Arad': 75},
}


def problem_to_dot(problem):
    with open("problem.dot", mode='w') as f:
        f.write("digraph problem {\n")
        f.write("  // node\n")
        for node in problem.keys():
            f.write("  {} [shape = box];\n".format(node))

        f.write("  // edge\n")
        for node1 in problem.keys():
            for node2 in problem[node1]:
                f.write("  {} -> {} [label = {}];\n".format(
                    node1, node2, step_cost[node1][node2]))
        f.write("}\n")

problem_to_dot(problem) # use 'xdot problem.dot' to show graph


def bfs(graph, start, target):
    fringe = [start]
    while fringe:
        node = fringe[0]
        fringe = fringe[1:]  # pop
        print("traverse {}".format(node))
        if node == target:
            print("found target {}".format(node))
            return node
        for n in graph[node]:
            fringe.append(n)
    return None


print("= bfs")
bfs(problem, 'Arad', 'Bucharest')  # This is not problem search

def successor(problem, node):
    return problem[node]

class Node:
    def __init__(self, parent, state):
        self.parent = parent
        self.state = state
        if parent:
            self.path_cost = parent.path_cost + step_cost[parent.state][state]
            self.depth = parent.depth + 1
        else:
            self.path_cost = 0
            self.depth = 0


def remove_front(fringe):
    ret = fringe[0]
    del(fringe[0]) # remove first element
    return ret

def tree_search(problem, start, goal_test):
    fringe = [start]
    while fringe:
        node = remove_front(fringe) # pop
        print("traverse {0: <16}  cost {1: >5}, depth {2}".format(
            node.state, node.path_cost, node.depth))
        if goal_test(node) == True:
            print("found target {}".format(node.state))
            n = node
            result = []
            while n:
                result.append(n.state)
                n = n.parent
            result.reverse()
            print(result)
            return node
        for n in successor(problem, node.state):
            fringe.append(Node(node, n))
    return None


print("= tree_search")
tree_search(problem, Node(None, 'Arad'), lambda x: x.state == 'Bucharest')

'''
# for those who do no like lambda...
def my_goal_test(x):
    return x. state == 'Bucharest'
def my_goal_test(x):
    if x. state == 'Bucharest':
        return True
    else:
        return False
print(tree_search(problem, Node(None, 'Arad'), my_goal_test))
'''
