exec(open('informed.py').read())
class Problem:
    def __init__(self, start, goal):
        self.start = start
        self.goal = goal
        return None

    def remove_front(self, fringe):
        fringe.sort(key = lambda x: x.path_cost + self.heuristic(x.state))
        ret = fringe[0]
        del(fringe[0]) # remove first element
        return ret

    def goal_test(self, state):
        return state == self.goal

    def string(self, state):
        return state

class Romania(Problem):
    def successor(self, state):
        return problem[state]

    def step_cost(self, parent_state, state):
        return step_cost[parent_state][state]

    def heuristic(self, state):
        return heuristic[state]

class Node:
    def __init__(self, problem, parent, state):
        self.parent = parent
        self.state = state
        if parent:
            self.path_cost = parent.path_cost + problem.step_cost(parent.state, state)
            self.depth = parent.depth + 1
        else:
            self.path_cost = 0
            self.depth = 0

def tree_search(problem):
    fringe = [Node(problem, None, problem.start)]
    while fringe:
        node = problem.remove_front(fringe) # pop
        print("traverse {0: <16}  g {1: >5} + h {2: >5}, depth {3}".format(
            node.state, node.path_cost, problem.heuristic(node.state), node.depth))
        if problem.goal_test(node.state) == True:
            print("found target {}".format(node.state))
            n = node
            result = []
            while n:
                result.append(n.state)
                n = n.parent
            result.reverse()
            for r in result:
                print(problem.string(r))
            return node
        for n in problem.successor(node.state):
            fringe.append(Node(problem, node, n))
    return None

romania = Romania('Arad', 'Bucharest')
tree_search(romania)

import copy
class Puzzle(Problem):
    def find_index(self, state, number):
        for i in range(0, 3):
            for j in range(0, 3):
                if state[i][j] == number:
                    x = j
                    y = i
        return (x, y)

    def successor(self, state):
        # find 0 (blank)
        (x, y) = self.find_index(state, 0)
        # get sucessor state
        ret = []
        if x > 0:
            r = copy.deepcopy(state)
            r[y][x-1], r[y][x] = 0, r[y][x-1]
            ret.append(r)
        if x < 2:
            r = copy.deepcopy(state)
            r[y][x], r[y][x+1] = r[y][x+1], 0
            ret.append(r)
        if y > 0:
            r = copy.deepcopy(state)
            r[y-1][x], r[y][x] = 0, r[y-1][x]
            ret.append(r)
        if y < 2:
            r = copy.deepcopy(state)
            r[y][x], r[y+1][x] = r[y+1][x], 0
            ret.append(r)

        return ret

    def step_cost(self, parent_state, state):
        return 1

    def heuristic(self, state):
        return 1

    def string(self, state):
        return '{}\n{}\n{}\n'.format(state[0], state[1], state[2])

#puzzle = Puzzle([[4,1,5],[2,0,8],[3,6,7]], [[0,1,2],[3,4,5],[6,7,8]]) # depth 12
#puzzle = Puzzle([[0,1,5],[4,2,8],[3,6,7]], [[0,1,2],[3,4,5],[6,7,8]]) # depth 10
puzzle = Puzzle([[1,2,5],[4,0,8],[3,6,7]], [[0,1,2],[3,4,5],[6,7,8]]) # depth 8
tree_search(puzzle)
# [1,2,5]
# [4,0,8]
