// AC-Circuits/resistor.h
// Header file for resistor class definition; also defined namespace
// Frederik Brooke Barnes, Last modified 28/4/2021

//Include guard
#ifndef RESISTOR_H
#define RESISTOR_H
//Includes
#include "component.h"
//Class definition
class resistor : public component
{
private:
  double resistance;
public:
  resistor() : resistance{}, component("R") {} 
  resistor(double R) : resistance{R}, component("R") {}
  ~resistor(){}
  void print_info();
  void set_resistance(double R);
  double get_resistance();
  complex get_impedance(double frequency);
  complex get_impedance();  
};

#endif