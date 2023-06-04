# 1.1
def cube(x):
    return x * x * x

# 1.2
def sum_integers(a, b):
   if a > b:
      return 0
   else:
      return a + sum_integers(a + 1, b)

def sum_cubes(a, b):
   if a > b:
      return 0
   else:
      return cube(a) + sum_cubes(a + 1, b)

def pi_sum(a, b):
   if a > b:
      return 0.0
   else:
      return (1.0 / (a * (a + 2.0))) + \
          pi_sum(a + 4.0, b)

print("sum_integers : %d"%(sum_integers(1, 10)))
print("sum_cubes    : %d"%(sum_cubes(1, 10)))
print("pi_sum       : %f"%(8.0 * pi_sum(1, 1000)))

# Using sum function
print("\n# Using sim function")

def sum(term, a, next, b):
   if a > b:
      return 0
   else:
      return term(a) + sum(term, next(a), next, b)

import inspect
print(inspect.getsource(sum))

def inc(n):
    return n + 1

def sum_cubes(a, b):
   return sum(cube, a, inc, b)

print("sum_cubes    : %d"%(sum_cubes(1, 10)))

def identity(x): return x

def sum_integers(a, b):
   return sum(identity, a, inc, b)

print("sum_integers : %d"%(sum_integers(1, 10)))

def pi_sum(a, b):
   def pi_term(x): return 1.0 / (x * (x + 2.0))
   def pi_next(x): return x + 4.0
   return sum(pi_term, a, pi_next, b)

print("pi_sum       : %f"%(8.0 * pi_sum(1, 1000)))

# Integral
print("\n# Integral")

def integral(f, a, b, dx):
   def add_dx(x): return x + dx
   return sum(f, a + (dx / 2.0), add_dx, b) * dx

print(inspect.getsource(integral))

import sys
sys.setrecursionlimit(2000)
print("integral(cube): %f"%(integral(cube, 0.0, 1.0, 0.001)))
