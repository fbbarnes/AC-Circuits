// AC-Circuits/inductor.h
// Header file for inductor class definition
// Frederik Brooke Barnes, Last modified 2/5/2021

//Include guard
#ifndef INDUCTOR_H
#define INDUCTOR_H
//Includes
#include "component.h"
//Class definition
class inductor : public component
{
private:
  double inductance;
public:
  inductor() : inductance{}, component("L") {} 
  inductor(double L) : inductance{L}, component("L") {}
  ~inductor(){}
  void print_info();
  void set_inductance(double L);
  double get_inductance();
  complex get_impedance(double frequency);
};

#endif