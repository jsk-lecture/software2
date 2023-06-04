#include <iostream>

class Rational {
public:
  Rational(int n, int d)
  {
    this->numer = n;
    this->denom = d;
  }

  Rational add_rat(Rational y)
  {
    return Rational(this->numer*y.denom + y.numer*this->denom, this->denom*y.denom);
  }

  Rational sub_rat(Rational y)
  {
    return Rational(this->numer*y.denom - y.numer*this->denom, this->denom*y.denom);
  }

  Rational mul_rat(Rational y)
  {
    return Rational(this->numer*y.numer, this->denom*y.denom);
  }

  Rational div_rat(Rational y)
  {
    return Rational(this->numer*y.denom, this->denom*y.numer);
  }

  bool equal_rat(Rational y)
  {
    return this->numer*y.denom == y.numer * this->denom;
  }

  void print_rat()
  {
    std::cout << this->numer << "/" << this->denom << std::endl;
  }
private:
  int numer;
  int denom;
};

int  main()
{
  Rational one_half = Rational(1, 2);
  one_half.print_rat();
  // std::cerr << one_half.numer << "/" << one_half.denom << std::endl;
  Rational one_third = Rational(1, 3);
  one_half.add_rat(one_third).print_rat();
  one_half.mul_rat(one_third).print_rat();
  one_third.add_rat(one_third).print_rat();
}
