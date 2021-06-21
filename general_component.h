// AC-Circuits/general_component.h
// Header file for general component class definition
// Frederik Brooke Barnes, Last modified 28/4/2021

//Include guard
#ifndef GENERAL_COMPONENT_H
#define GENERAL_COMPONENT_H
//Includes
#include "component.h"
//Class definition
class general_component : public component
{
protected:
  complex impedance;
  std::string symbol;
public:
  general_component() : component("G") {}
  general_component(complex Z): impedance{Z}, component("G") {}
  ~general_component(){}
  void set_impedance(complex Z);
  complex get_impedance(double frequency);
  complex get_impedance();
  using component::get_magnitude;
  double get_magnitude();
  using component::get_phase;
  double get_phase();
  void print_info();
  std::string get_symbol();
}; 
#endif