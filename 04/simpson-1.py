def inc(n):
    return n + 1

def cube(a):
    return a*a*a

def sum(term,a,next,b):
    if a > b:
        return 0
    else:
        return term(a) + sum(term, next(a), next, b)

def simpson(f,a,b,n):
    h = float(b-a) / n
    def inc(x): return x+1
    def y(k): return f(a+k*h)
    def kvalue(k):
        if k==0 or k==n:
            return 1*y(k)
        elif k%2==0:
            return 2*y(k)
        elif k%2==1:
            return 4*y(k)
    return (h/3.0)*sum(kvalue,0,inc,n)

print(cube(10))
print("simp")
print (simpson(cube, 0, 1, 7))
print (simpson(cube, 0, 1, 10))

