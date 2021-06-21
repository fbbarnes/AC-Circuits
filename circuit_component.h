// AC-Circuits/circuit_component.h
// Header file for circuit component class definition
// Frederik Brooke Barnes, Last modified 9/5/2021

//Include guard
#ifndef CIRCUIT_COMPONENT_H
#define CIRCUIT_COMPONENT_H
//Includes
#include "component.h"
#include "circuit.h"
//Class definition
class circuit_component : public component
{
private:
  circuit circ;
public: 
  circuit_component(circuit C) : circ{C}, component("CIRC") {}
  ~circuit_component(){}
  void print_info();
  complex get_impedance(double frequency);
  void set_frequency(double frequency);
};

#endif