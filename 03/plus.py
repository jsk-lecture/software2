def inc(x):
    return x + 1
def dec(x):
    return x - 1

def plus_a(a, b):
    if a == 0:
        return b
    else:
        return inc(plus_a(dec(a), b))

def plus_b(a, b):
    if a == 0:
        return b
    else:
        return plus_b(dec(a), inc(b))


print("call plus_a(4, 5))")
print(plus_a(4, 5))
print("call plus_b(4, 5))")
print(plus_b(4, 5))
