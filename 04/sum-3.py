def cube(x):
    return x * x * x

def sum(term, a, next, b):
    if a > b:
        return 0
    else:
        return term(a) + sum(term, next(a), next, b)

def pi_sum(a, b):
    return sum(lambda x: 1.0 / (x * (x + 2.0)), a, lambda x: x + 4.0, b)

def integral(f, a, b, dx):
    return sum(f, a + (dx / 2.0), lambda x: x + dx, b) * dx

import sys
sys.setrecursionlimit(2000)
print("integral(cube): %f"%(integral(cube, 0.0, 1.0, 0.001)))
print("pi_sum       : %f"%(8.0 * pi_sum(1, 1000)))
