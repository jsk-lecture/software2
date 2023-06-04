a = 10

def foo():
    # global a
    a = 100
    print("foo: a = {}".format(a))
    bar()

def bar():
    print("bar: a = {}".format(a))

foo()
print("global: a = {}".format(a))
