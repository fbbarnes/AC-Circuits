// AC-Circuits/main.cpp
// Frederik Brooke Barnes, Last modified 2/5/2021

#include<iostream>
#include<cmath>
#include<vector>
#include<memory>
#include "complex.h"
#include "component.h"
#include "general_component.h"
#include "resistor.h"
#include "capacitor.h"
#include "inductor.h"
#include "circuit.h"
#include "circuit_component.h"
#include "typedefs.h"
#include "menu.h"
#include <typeinfo>
#include <typeindex>
#include<algorithm>
#include "count_type.h"



int main()
{
  //Create example components
  resistor r1(1);
  capacitor c1(1);
  inductor l1(1);

  //Create library of components with array of base class pointers
  library_vector component_library;
  component_library.push_back(std::make_shared<resistor>(1));
  component_library.push_back(std::make_shared<capacitor>(1));
  component_library.push_back(std::make_shared<inductor>(1));
  
  //Create user interface for controlling component library
  menu main_menu(component_library);
  //Run the menu
  main_menu.main_menu();
  return 0;
}


