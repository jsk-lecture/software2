print("with closure")
# exec(open('bank.py').read())
def make_withdraw():
    balance = 100
    def withdraw(amount):
        nonlocal balance
        if balance >= amount:
            balance = balance - amount
            return balance
        else:
            return 'Insufficient funds'
    return withdraw

withdraw = make_withdraw()

print("withdraw(25) = {}".format(withdraw(25)))
print("withdraw(25) = {}".format(withdraw(25)))
print("withdraw(60) = {}".format(withdraw(60)))
print("withdraw(15) = {}".format(withdraw(15)))

a = -10
b = -100
c = -1000

def f(a):
    b = 100
    def g(c):
        # global b
        # nonlocal b
        # b = 10000
        return a + b + c
    return g

h = f(10)
print("h = f(10), h(100)=(10) = {}, a = {}, b = {}, c = {}".format(h(100), a, b, c))

