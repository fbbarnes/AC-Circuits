// AC-Circuits/resistor.cpp
// implementation file for resistor class definition
// Frederik Brooke Barnes, Last modified 28/4/2021

#include<iostream>
#include<cmath>
#include "general_component.h"

void general_component::print_info()
{
  std::cout<<impedance<<" Ohm component"<<std::endl;
}

void general_component::set_impedance(complex Z) 
{
  impedance = Z;
}

complex general_component::get_impedance(double frequency) 
{
  return impedance;
}

complex general_component::get_impedance() 
{
  return impedance;
}

double general_component::get_magnitude() 
{
  complex Z = this->get_impedance();
  return Z.modulus();
}

double general_component::get_phase()
{
  complex Z = this->get_impedance();
  return Z.argument();
}

std::string general_component::get_symbol()
{
  return symbol;
}