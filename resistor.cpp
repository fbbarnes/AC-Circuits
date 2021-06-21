// AC-Circuits/resistor.cpp
// implementation file for resistor class definition
// Frederik Brooke Barnes, Last modified 28/4/2021

#include<iostream>
#include<cmath>
#include "resistor.h"

void resistor::print_info()
{
  std::cout<<symbol<<": "<<resistance<<" Ohm resistor"<<std::endl;
}

void resistor::set_resistance(double R) 
{
  resistance = R;
}

double resistor::get_resistance() 
{
  return resistance;
}


complex resistor::get_impedance() 
{
  return complex(resistance,0);
}

complex resistor::get_impedance(double frequency) 
{
  return complex(resistance,0);
}
