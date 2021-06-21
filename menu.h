// AC-Circuits/menu.h
// header file for menu class definition
// Frederik Brooke Barnes, Last modified 10/5/2021

//Include guard
#ifndef MENU_H
#define MENU_H
//Includes
#include<vector>
#include<memory>
#include<map>
#include "typedefs.h"
#include "circuit.h"
//Class definition 
class menu
{
private:
  library_vector &library;

  void register_main_menu_options();
  enum class main_menu_option;
  std::map<std::string, main_menu_option> main_menu_options;
  void register_add_comp_options();
  enum class add_comp_option;
  std::map<std::string, add_comp_option> add_comp_options;
  void register_edit_circuit_options();
  enum class edit_circuit_option;
  std::map<std::string, edit_circuit_option> edit_circuit_options;
  void register_get_is_series_options();
  enum class get_is_series_option;
  std::map<std::string, get_is_series_option> get_is_series_options;

public:
  menu(library_vector &l) : library{l} {} 
  ~menu(){}
  void main_menu();
  void add_component_menu();
  void add_circuit_menu();
  void edit_circuit_menu(circuit& circ);
  void show_library();
  resistor_ptr get_resistor();
  capacitor_ptr get_capacitor();
  inductor_ptr get_inductor();
  bool get_is_series();
  double get_frequency();
  component_ptr get_from_lib();
  bool in_range(int low, int high, int x);
};

#endif
