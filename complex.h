// AC-Circuits/complex.h
// header file for complex class definition; also defined namespace
// Frederik Brooke Barnes, Last modified 28/4/2021

//Include guard
#ifndef COMPLEX_H
#define COMPLEX_H
//Includes
#include<cmath>
#include<iostream>
//Class definiton
class complex
{
// Make function to overload operator<< a friend
friend std::ostream & operator<<(std::ostream &os, const complex &z);
friend std::istream & operator>>(std::istream &is, complex &z);

private:
  double re,im;
public:
  // Constructors & destructor
  complex(){re=im=0;}
  complex(double real_part, double im_part){re=real_part; im=im_part;}
  ~complex(){}

  // Return real component
  double real() const {return re;}
  
  // Return imaginary component
  double imaginary() const {return im;}

  // Return modulus
  double modulus() const {return std::sqrt(re*re + im*im);}

  // Return argument
  double argument() const {return std::atan2(im, re);}

  // Return complex conjugate
  complex conjugate() const {return complex(re, -im);}

  // Overload + operator for addition
  complex operator+(const complex &z) const;

  // Overload - operator for subtraction
  complex operator-(const complex &z) const;

  // Overload * operator for multiplication, z1*z2
  complex operator*(const complex &z) const;

  // Overload / operator for division, z1/z2
  complex operator/(const complex &z) const;
};


#endif