// AC-Circuits/component.h
// header file for circuit class definition
// Frederik Brooke Barnes, Last modified 5/5/2021

//Include guard
#ifndef CIRCUIT_H
#define CIRCUIT_H
//Includes
#include<vector>
#include<memory>
#include<map>
#include "complex.h"
#include "component.h"
#include "component_list_item.h"
//Circuit class definition 
class circuit
{
private:
  double frequency;
  complex impedance;
  std::vector<component_list_item> component_list;
  void update_impedance(std::shared_ptr<component> &comp, bool is_series);
public:
  circuit() : impedance{complex(0,0)}, frequency{1} {} 
  circuit(complex Z, double F) : impedance{Z}, frequency{F} {} 
  ~circuit(){}
  void add_component(std::shared_ptr<component> comp, bool is_series = true);
  void print_info();
  void draw();
  void set_frequency(double F);
  double get_frequency();
  complex get_impedance();
  double get_magnitude();
  double get_phase();
};

#endif
