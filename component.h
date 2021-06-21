// AC-Circuits/component.h
// header file for component class definition; also defined namespace
// Frederik Brooke Barnes, Last modified 28/4/2021

//Include guard
#ifndef COMPONENT_H
#define COMPONENT_H
//Includes
#include <string>
#include "complex.h"
//Class definition
class component
{
protected:
  std::string symbol;
  
public:
  component(std::string symb) : symbol{symb} {}
  ~component(){}
  virtual void print_info() = 0;
  virtual complex get_impedance(double frequency) = 0;
  virtual void set_frequency(double frequency);
  virtual double get_magnitude(double frequency);
  virtual double get_phase(double frequency);
  void set_symbol(std::string symb);
  std::string get_symbol();
};

#endif
