#include <iostream>

class Rational {
public:
  Rational(int n, int d)
  {
    this->numer = n;
    this->denom = d;
  }

  Rational operator+(const Rational &y)
  {
    return Rational(this->numer*y.denom + y.numer*this->denom, this->denom*y.denom);
  }

  Rational operator-(const Rational &y)
  {
    return Rational(this->numer*y.denom - y.numer*this->denom, this->denom*y.denom);
  }

  Rational operator*(const Rational &y)
  {
    return Rational(this->numer*y.numer, this->denom*y.denom);
  }

  Rational operator/(const Rational &y)
  {
    return Rational(this->numer*y.denom, this->denom*y.numer);
  }

  bool operator=(const Rational &y)
  {
    return this->numer*y.denom == y.numer * this->denom;
  }
  friend std::ostream& operator<<(std::ostream& os, const Rational& y);
private:
  int numer;
  int denom;

};

std::ostream &operator<<(std::ostream &os, const Rational &y)
{
  os << y.numer << "/" << y.denom;
  return os;
}

int linear_combination (int a, int b, int x, int y) {
  return (a*x) + (b*y);
}

Rational linear_combination (Rational a, Rational b, Rational x, Rational y) {
  return (a*x) + (b*y);
}

int  main()
{
  Rational one_half = Rational(1, 2);
  Rational one_third = Rational(1, 3);

  std::cerr << linear_combination(1, 2, 3, 4) << std::endl;
  std::cerr << linear_combination(one_half, one_half, one_third, one_third) << std::endl;
}
