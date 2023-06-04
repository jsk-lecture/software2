import sys
import resource

SIZE = 100000

def fib(n):
    if n[0] == 0:
        return [0]*SIZE
    elif n[0] == 1:
        return [1]*SIZE
    else:
        return [fib([n[0] - 1]*SIZE)[0] + fib([n[0] - 2]*SIZE)[0]]*SIZE


n = int(sys.argv[1])
print("call fib({})".format(n))
r = fib([n]*SIZE)
print(" --> {}".format(r[0]))

print("memory usage = {}".format(resource.getrusage(resource.RUSAGE_SELF).ru_maxrss))
