import time

def loop(n):
    name = "loop"
    for i in range(n):
        print("{} {}".format(name, i))
        yield i
        time.sleep(1.0/n)

l1 = loop(10)
l2 = loop(10)
for i in range(10):
    next(l1)  # l1.next()
    next(l2)  # l2.next()
