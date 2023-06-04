# coding: utf-8

class Rational:
   def __init__(self, n, d):
      self.numer = n
      self.denom = d

   def __add__(self, y):
      return Rational(self.numer*y.denom + y.numer*self.denom, self.denom*y.denom)

   def __sub_(self, y):
      return Rational(self.numer*y.denom - y.numer*self.denom, self.denom*y.denom)

   def __mul__(self, y):
      return Rational(self.numer*y.numer, self.denom*y.denom)

   def __truediv__(self, y):
      # Python2用
      # 2/3 が 0 ではなく 0.66 となるような a / b を返します。
      # https://docs.python.org/ja/3/library/operator.html
      return Rational(self.numer*y.denom, self.denom*y.numer)

   def __div__(self, y):
      # Python3用
      # __future__.division が有効でなければ、 a / b は a // b と同じ結果を返します。
      # これは "古典的な (classic)" 除算とも呼ばれます。
      # https://docs.python.org/ja/2.7/library/operator.html
      return Rational(self.numer*y.denom, self.denom*y.numer)

   def __equal__(self, y):
      return self.numer*y.denom == y.numer * self.denom

   def __repr__(self):
      return (str(self.numer) + "/" + str(self.denom))

###

one_half = Rational(1, 2)
print("one_half = {}".format(one_half))
one_third = Rational(1, 3)
print("one_half + one_third = {}".format(one_half + one_third))
print("one_half * one_third = {}".format(one_half * one_third))
print("one_half + one_third = {}".format(one_third / one_third))

