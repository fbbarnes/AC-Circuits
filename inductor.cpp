// AC-Circuits/inductor.cpp
// implementation file for inductor class definition
// Frederik Brooke Barnes, Last modified 5/2/2021

#include<iostream>
#include<cmath>
#include "inductor.h"
#include "constants.h"


void inductor::print_info()
{
  std::cout<<symbol<<": "<<inductance<<" Henry inductor"<<std::endl;
}

void inductor::set_inductance(double L) 
{
  inductance = L;
}

double inductor::get_inductance() 
{
  return inductance;
}

complex inductor::get_impedance(double frequency) 
{
  return complex(0, 2 * constant::pi * frequency * inductance);
}
