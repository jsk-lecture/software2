import sys
import resource

def fib(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)


n = int(sys.argv[1])
print("call fib({})".format(n))
r = fib(n)
print(" --> {}".format(r))

print("memory usage = {}".format(resource.getrusage(resource.RUSAGE_SELF).ru_maxrss))
