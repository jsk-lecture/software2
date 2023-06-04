print("use global variable")
balance = 100
def withdraw(amount):
    global balance
    if balance >= amount:
        balance = balance - amount
        return balance
    else:
        return 'Insufficient funds'

print("withdraw(25) = {}".format(withdraw(25)))
print("withdraw(25) = {}".format(withdraw(25)))
print("withdraw(60) = {}".format(withdraw(60)))
print("withdraw(15) = {}".format(withdraw(15)))

'''
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
'''
print("with python2")
def make_withdraw(balance):
    class context: # Python2 needs context, https://stackoverflow.com/questions/3190706/nonlocal-keyword-in-python-2-x
        _balance = balance
    def withdraw(amount):
        # nonlocal balance on Python3 you can use nonlocal
        balance = context._balance
        if amount > balance:
            return 'Insufficient funds'
        balance = balance - amount
        context._balance = balance        # Send back to context for Python2
        return balance
    return withdraw

kei = make_withdraw(100)
bill = make_withdraw(1000)

print (kei(25))
print (bill(25))
print (kei(25))
print (bill(25))
print (kei(60))
print (bill(60))

print("with class")
class Deposit():
    def __init__(self, init_balance):
        self.balance = init_balance

    def withdraw(self, amount):
        if amount > self.balance:
            return 'Insufficient funds'
        self.balance = self.balance - amount
        return self.balance

    
kei = Deposit(100)
bill = Deposit(1000)

print (kei.withdraw(25))
print (bill.withdraw(25))
print (kei.withdraw(25))
print (bill.withdraw(25))
print (kei.withdraw(60))
print (bill.withdraw(60))
