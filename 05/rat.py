def linear_combination(a, b, x, y):
   return add(mul(a, x), mul(b, y))

def mul(a, b):
    return a * b
def add(a, b):
    return a + b

def add_rat(x, y):
   return make_rat(numer(x)*denom(y) + \
                   numer(y)*denom(x), \
                   denom(x)*denom(y))


def mul_rat(x, y):
   return make_rat(numer(x)*numer(y), denom(x)*denom(y))

def make_rat(n, d):
    return (n, d)
def numer(x):
    return x[0]
def denom(x):
    return x[1]

def str_rat(x):
        return '{}/{}'.format(numer(x), denom(x))

print("make_rat(1, 2) = {}".format(make_rat(1, 2)))
print("numer(make_rat(1, 2)) = {}".format(numer(make_rat(1, 2))))
print("denom(make_rat(1, 2)) = {}".format(denom(make_rat(1, 2))))

one_half = make_rat(1, 2)
one_third = make_rat(1, 3)

print("mul_rat(one_half, one_third) = {}".format(str_rat(mul_rat(one_half, one_third))))
print("add_rat(one_half, one_third) = {}".format(str_rat(add_rat(one_half, one_third))))
print("add_rat(one_third, one_third) = {}".format(str_rat(add_rat(one_third, one_third))))

from fractions import gcd
def make_rat(n, d):
    g = gcd(n, d)
    return (n//g, d//g)

print("add_rat(one_third, one_third) = {}".format(str_rat(add_rat(one_third, one_third))))

def linear_combination(a, b, x, y):
   return add(mul(a, x), mul(b, y))

def add(a, b):
    if type(a) is tuple and type(b) is tuple:
        return add_rat(a, b)
    else:
        return a + b;

def mul(a, b):
    if type(a) is tuple and type(b) is tuple:
        return mul_rat(a, b)
    else:
        return a * b;

print("linear_combination(1, 2, 3, 4) = {}".format(linear_combination(1, 2, 3, 4)))
print("linear_combination(one_half, one_half, one_third, one_third) = {}".format(str_rat(linear_combination(one_half, one_half, one_third, one_third))))

# https://www.angelfire.com/tx4/cus/pl/sicp_python_02.html
def make_rat(n, d):
   if (d < 0 and n < 0) or n < 0:
      return (d * -1, n * -1)
   else:
      return (d, n)
