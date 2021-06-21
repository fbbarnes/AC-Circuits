// AC-Circuits/capactior.h
// Header file for capacitor class definition
// Frederik Brooke Barnes, Last modified 2/5/2021

//Include guard
#ifndef CAPACITOR_H
#define CAPACITOR_H
//Includes
#include "component.h"
//Class definition
class capacitor : public component
{
protected:
  double capacitance;
public:
  capacitor() : capacitance{}, component("C") {} 
  capacitor(double C) : capacitance{C}, component{"C"} {}
  ~capacitor(){}
  void print_info();
  void set_capacitance(double C);
  double get_capacitance();
  complex get_impedance(double frequency);
};

#endif