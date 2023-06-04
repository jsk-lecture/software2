import time

def loop(n):
    name = "loop"
    for i in range(n):
        print("{} {}"
                  .format(name, i))
        name = yield i
        time.sleep(1.0/n)

l1 = loop(10)
l2 = loop(10)
l1.next();
l2.next();
for i in range(9):
    l1.send("name1")
    l2.send("name2")
