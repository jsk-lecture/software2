def cons(x, y):
    return (x, y)

def car(z): return z[0]
def cdr(z): return z[1]

def make_rat(n, d): return cons(n, d)
def numer(x): return car(x)
def denom(x): return cdr(x)

print("make_rat(1, 2) = {}".format(make_rat(1, 2)))
print("numer(make_rat(1, 2)) = {}".format(numer(make_rat(1, 2))))
print("denom(make_rat(1, 2)) = {}".format(denom(make_rat(1, 2))))

def cons(x, y):
    def dispatch(m):
        if m == 0:
            return x
        elif m == 1:
            return y
    return dispatch

import inspect
print(inspect.getsource(cons(1, 2)))

print("cons(1, 2) = {}".format(cons(1, 2)))

def car(z): return z(0)
def cdr(z): return z(1)

print("car(cons(1, 2)) = {}".format(car(cons(1, 2))))
print("cdr(cons(1, 2)) = {}".format(cdr(cons(1, 2))))

print("make_rat(1, 2) = {}".format(make_rat(1, 2)))
print("numer(make_rat(1, 2)) = {}".format(numer(make_rat(1, 2))))
print("denom(make_rat(1, 2)) = {}".format(denom(make_rat(1, 2))))

