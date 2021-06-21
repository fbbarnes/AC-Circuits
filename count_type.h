// AC-Circuits/get_input.h
// header file for count_component template definition
// Frederik Brooke Barnes, Last modified 12/5/2021

//Include guard
#ifndef COUNT_TYPE_H
#define COUNT_TYPE_H
//Includes
#include <vector>
#include <typeinfo>
#include <typeindex>
#include <algorithm>
#include "typedefs.h"

//Counts number of elements in a vector
//which matches the type of the input item
template <class T, class T2>
int count_type (T item, std::vector<std::shared_ptr<T2>> vector) 
{
  //get type_index of type of interest
  std::type_index const item_type = typeid(item);
  //count elements where typeid matches
  int item_count = std::count_if(begin(vector), end(vector), [&](auto element)
  { 
    return item_type == typeid(*element); 
  });
  std::cout<<"count:"<<item_count;
  return item_count;
}

#endif
