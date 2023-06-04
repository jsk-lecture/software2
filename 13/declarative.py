'''
def sqrt (x):
  return x where
     y > 0 and (square y) == x
'''
def abs(x):
    if (x < 0):
        return -x
    else:
        return x

def sqrt_iter(guess, x):
    if good_enough(guess, x):
        return guess
    else:
        return sqrt_iter(improve(guess, x), x)

def good_enough(guess, x):
    return ((abs ((guess * guess) - x)) < 0.01)

def improve(guess, x):
    return average(guess, (x / guess))

def average(x, y):
    return ((x + y) / 2.0)

def sqrt(x):
    return sqrt_iter(1.0, x)

print("sqrt(10) = {}".format(sqrt(4.0)))

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

print("factorial(5) = {}".format(factorial(5)))

def factorial(n):
    counter = 1
    product = 1
    while counter <= n:
        product = product * counter
        counter += 1
    return product


print("factorial(5) = {}".format(factorial(5)))
