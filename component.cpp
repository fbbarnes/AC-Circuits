// AC-Circuits/component.cpp
// Implementation file for component class definition
// Frederik Brooke Barnes, Last modified 21/4/2021

#include<iostream>
#include<cmath>
#include "component.h"


//Returns magnitude of impedance
double component::get_magnitude(double frequency) 
{
  complex Z = this->get_impedance(frequency);
  return Z.modulus();
}
//Returns phase of impedance
double component::get_phase(double frequency)
{
  complex Z = this->get_impedance(frequency);
  return Z.argument();
}

void component::set_frequency(double frequency) {}

void component::set_symbol(std::string symb)
{
  symbol = symb;
}

std::string component::get_symbol()
{
  return symbol;
}