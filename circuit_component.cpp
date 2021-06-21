// AC-Circuits/circuit_componetn.cpp
// implementation file for circuit component class definition
// Frederik Brooke Barnes, Last modified 28/4/2021

#include<iostream>
#include<cmath>
#include "circuit_component.h"

void circuit_component::print_info()
{
  std::cout<<symbol<<": ";
  circ.print_info();
}


complex circuit_component::get_impedance(double frequency) 
{
  return circ.get_impedance();
}

void circuit_component::set_frequency(double frequency)
{
  circ.set_frequency(frequency);
};