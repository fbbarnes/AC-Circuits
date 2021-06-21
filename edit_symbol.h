// AC-Circuits/get_input.h
// header file for add_to_library template definition
// Frederik Brooke Barnes, Last modified 12/5/2021

//Include guard
#ifndef EDIT_SYMBOL_H
#define EDIT_SYMBOL_H
//Includes
#include <vector>
#include <typeinfo>
#include <typeindex>
#include <algorithm>
#include "typedefs.h"
#include "count_type.h"
#include "component.h"

//Takes a component of any type and edits its symbol
//depending on the number of that component already
//in the the library.
template <class T, class T2>
T edit_symbol(T comp, std::vector<std::shared_ptr<T2>> library)
{
  //count number of component in library
  int count = count_type(*comp, library);
  std::cout<<"count "<<count<<std::endl;
  //get and edit symbol according to no. of component in library + 1
  std::cout<<comp->get_symbol()<<std::endl;
  std::string new_symbol = comp->get_symbol() + std::to_string(count + 1);
  std::cout<<" new_symbol:"<<new_symbol<<std::endl;
  //set new symbol
  comp->set_symbol(new_symbol);
  comp->print_info();
  return comp;
}

#endif
