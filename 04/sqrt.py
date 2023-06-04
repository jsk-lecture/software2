# 1.5
import sys
sys.setrecursionlimit(2000)

# 1.5.1
print("# Newton method")

def sqrt_iter(guess, x):
    if good_enougth(guess, x):
        return guess
    else:
        return sqrt_iter(improve(guess, x), x)

def improve(guess, x):
    return average(guess, (x / guess))

def average(x, y):
    return (x + y) / 2.0

def square(x): return x * x
def abs(x): return -x if x < 0 else x

def good_enougth(guess, x):
    return abs(square(guess) - x) < 0.001

def my_sqrt(x):
    return sqrt_iter(1.0, x)

print("sqrt : %f"%(my_sqrt(10)))

# 1.5.2
print("# Using fixed point")

tolerance = 0.00001
def close_enough(v1, v2):
    return abs(v1 - v2) < tolerance

def try_proc(f, guess):
    next = f(guess)
    if close_enough(guess, next):
        return next
    else:
        return try_proc(f, next)

def fixed_point(f, first_guess):
    return try_proc(f, first_guess)

def my_sqrt(x):
    return fixed_point(lambda y: x / y, 1.0)

# print("sqrt : %f"%(my_sqrt(10))) # will not converge

def my_sqrt(x):
    return fixed_point(lambda y: average(y, x / y), 1.0)

print("sqrt : %f"%(my_sqrt(10)))

# 1.5.3
print("# Using average damp")

def average_damp(f):
    return lambda x: average(x, f(x))

import inspect
print(inspect.getsource(average_damp(square)))

print("{}(10) : {}".format(average_damp(square), average_damp(square)(10)))

def my_sqrt(x):
    return fixed_point(average_damp(lambda y: x / y), 1.0)
print("sqrt : %f"%(my_sqrt(10)))

def my_cube_root(x):
    return fixed_point(average_damp(lambda y: x / square(y)), 1.0)

print("sqrt : %f"%(my_sqrt(10)))

# Newton transform
print("# Using newton transform")
dx = 0.00001
def deriv(g):
   return lambda x: float(g(x + dx) - g(x)) / dx

def cube(x): return x * x * x

print(inspect.getsource(deriv(cube)))
print("deriv(cube)(5) : %f"%(deriv(cube)(5)))

def newton_transform(g):
    return lambda x: x - g(x) / deriv(g)(x)

def newtons_method(g, guess):
    return fixed_point(newton_transform(g), guess)

def my_sqrt(x):
    return newtons_method(lambda y: square(y) - x, 1.0)

print("sqrt : %f"%(my_sqrt(10)))

# 1.5.4
print("# Using fixed point of transform")

def fixed_point_of_transform(g, transform, guess):
    return fixed_point(transform(g), guess)

def my_sqrt(x):
    return fixed_point_of_transform(lambda (y): x / y, average_damp, 1.0)

print("sqrt : %f"%(my_sqrt(10)))

def my_sqrt(x):
    return fixed_point_of_transform(lambda (y): square(y)-x, newton_transform, 1.0)

print("sqrt : %f"%(my_sqrt(10)))
