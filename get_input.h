// AC-Circuits/get_input.h
// header file for get_input template definition
// Frederik Brooke Barnes, Last modified 10/5/2021

//Include guard
#ifndef GET_INPUT_H
#define GET_INPUT_H
//Includes
#include<iostream>
#include<limits>

//Takes object and replaces it with user input
template <class T>
T get_input (T input) {
  //Get input
  std::cin>>input;
  //Sanitise input stream
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return input;
}

#endif
