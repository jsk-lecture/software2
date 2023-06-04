class Rational:
   def __init__(self, n, d):
      self.numer = n
      self.denom = d

   def add_rat(self, y):
      return Rational(self.numer*y.denom + y.numer*self.denom, self.denom*y.denom)

   def sub_rat(self, y):
      return Rational(self.numer*y.denom - y.numer*self.denom, self.denom*y.denom)

   def mul_rat(self, y):
      return Rational(self.numer*y.numer, self.denom*y.denom)

   def div_rat(self, y):
      return Rational(self.numer*y.denom, self.denom*y.numer)

   def equal_rat(self, y):
      return self.numer*y.denom == y.numer * self.denom

   def print_rat(self):
      print (str(self.numer) + "/" + str(self.denom))

###

one_half = Rational(1, 2)
print("one_half.print_rat()")
one_half.print_rat()
one_third = Rational(1, 3)

print("one_half.add_rat(one_third).print_rat()")
one_half.add_rat(one_third).print_rat()
print("one_half.mul_rat(one_third).print_rat()")
one_half.mul_rat(one_third).print_rat()
print("one_third.add_rat(one_third).print_rat()")
one_third.add_rat(one_third).print_rat()

