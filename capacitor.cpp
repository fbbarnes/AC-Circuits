// AC-Circuits/resistor.cpp
// implementation file for resistor class definition
// Frederik Brooke Barnes, Last modified 28/4/2021

#include<iostream>
#include<cmath>
#include "capacitor.h"
#include "constants.h"

void capacitor::print_info()
{
  std::cout<<symbol<<": "<<capacitance<<" Farad capactior"<<std::endl;
}

void capacitor::set_capacitance(double C) 
{
  capacitance = C;
}

double capacitor::get_capacitance() 
{
  return capacitance;
}

complex capacitor::get_impedance(double frequency) 
{
  return complex(0, -1 / (2 * constant::pi * frequency * capacitance));
}
