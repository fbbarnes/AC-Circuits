// AC-Circuits/complex.cpp
// implementation file for complex class definition
// Frederik Brooke Barnes, Last modified 28/4/2021

#include "complex.h"
#include<iostream>

// Function to overload << operator for complex numbers
std::ostream & operator<<(std::ostream &os, const complex &z)
{
  if (z.imaginary() < 0) {os<<z.real()<<"-i"<<-z.imaginary();}
  else {os<<z.real()<<"+i"<<z.imaginary();}
  return os;
}

// Function to overload >> operator for complex numbers
std::istream & operator>>(std::istream  &is, complex &z ) 
{ 
  std::string input;
  is >> input;
  std::size_t pos_delimiter{input.find("+", 1)};
  std::size_t neg_delimiter{input.find("-", 1)};
  if (pos_delimiter < input.size()) {
    z.re = std::stod(input.substr(0, pos_delimiter));
    z.im = std::stod(input.substr(pos_delimiter+2, std::string::npos));
  }
  else if (neg_delimiter < input.size()) {
    z.re = std::stod(input.substr(0, neg_delimiter));
    std::string neg = input.substr(neg_delimiter+2, std::string::npos);
    z.im = - std::stod(neg);
  }
  return is;            
}

complex complex::operator+(const complex &z) const 
{
  complex new_complex(re+(z.real()), im+(z.imaginary()));
  return new_complex;
}

complex complex::operator-(const complex &z) const 
{
  complex new_complex(re-z.real(), im-z.imaginary());
  return new_complex;
}

complex complex::operator*(const complex &z) const
{ 
  double new_re = re*z.real() - im * z.imaginary();
  double new_im = re*z.imaginary() + im * z.real();
  return complex(new_re, new_im);
}

// Overload / operator for division, z1/z2
complex complex::operator/(const complex &z) const
{ 
  double new_re = (*this * (z.conjugate())).real() / (std::pow(z.modulus(), 2));
  double new_im = (*this * z.conjugate()).imaginary() / (std::pow(z.modulus(), 2));
  return complex(new_re, new_im);
}
