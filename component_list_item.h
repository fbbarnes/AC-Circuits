// AC-Circuits/component_list_item.h
// header file for component list struct definition
// Frederik Brooke Barnes, Last modified 5/5/2021

//Include guard
#ifndef COMPONENT_LIST_H
#define COMPONENT_LIST_H
//Includes
#include "component.h"
//Struct definition 
struct component_list_item
{
  std::shared_ptr<component> comp;
  bool is_series;

  component_list_item(std::shared_ptr<component> c, bool pos): comp{c}, is_series{pos} {}
};

#endif
