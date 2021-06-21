// AC-Circuits/inductor.cpp
// implementation file for menu class definition
// Frederik Brooke Barnes, Last modified 10/5/2021

#include<iostream>
#include<cmath>
#include<limits>
#include "menu.h"
#include "get_input.h"
#include "resistor.h"
#include "capacitor.h"
#include "inductor.h"
#include "circuit.h"
#include "typedefs.h"
#include "circuit_component.h"
#include "edit_symbol.h"


//Implement main menu class members

//Create main menu options list
enum class menu::main_menu_option 
{
  add_component=1, add_circuit=2,  show_library=3, quit=4
};
//Set user input strings to menu options
void menu::register_main_menu_options()
{
  main_menu_options["n"] = main_menu_option::add_component;
  main_menu_options["c"] = main_menu_option::add_circuit;
  main_menu_options["l"] = main_menu_option::show_library;
  main_menu_options["q"] = main_menu_option::quit;
}

//Implement main menu functionality
void menu::main_menu() 
{
  bool is_running {true};
  register_main_menu_options();
  
  std::string user_input;

  //Asks user to sleect menu option and executes appropiate function
  while (is_running) {
    std::cout<<std::endl;
    std::cout<<"What would you like to do?"<<std::endl;
    std::cout<<"Add new component to library: Enter n"<<std::endl;
    std::cout<<"Add new circuit to library: Enter c"<<std::endl;
    std::cout<<"Show library: Enter l"<<std::endl;
    std::cout<<"Quit: Enter q"<<std::endl;
    user_input = get_input(user_input);
    switch (main_menu_options[user_input]) 
    {
      case main_menu_option::add_component:
          std::cout << "add component!"<<std::endl; 
          add_component_menu();
          break;
      case main_menu_option::add_circuit:
          std::cout << "add circuit!"<<std::endl; 
          add_circuit_menu();
          break;
      case main_menu_option::show_library:
          std::cout << "show library!"<<std::endl; 
          show_library();
          break; 
      case main_menu_option::quit:
          std::cout << "quit!";
          is_running = false; 
          break;
      default:
          std::cout << "Please enter valid option!"<<std::endl;
          break;
    }
  }
}

//Create component adding menu options list
enum class menu::add_comp_option 
{
  add_resistor=1, add_capacitor=2, add_inductor=3, cancel=4
};
//Set user input strings to component adding menu options
void menu::register_add_comp_options()
{
  add_comp_options["r"] = add_comp_option::add_resistor;
  add_comp_options["c"] = add_comp_option::add_capacitor;
  add_comp_options["l"] = add_comp_option::add_inductor;
  add_comp_options["x"] = add_comp_option::cancel;
}

//Implement component adding menu for adding component to library
void menu::add_component_menu() 
{
  bool is_adding {true};
  register_add_comp_options();
  //Asks user to select valid menu option and executes appropiate function
  //then adds component to back of component library vector
  while (is_adding) {
    std::string user_input;
    std::cout<<std::endl;
    std::cout<<"What kind of component would you like to add to the library?"<<std::endl;
    std::cout<<"Add resistor: enter r"<<std::endl;
    std::cout<<"Add capacitor: enter c"<<std::endl;
    std::cout<<"Add inductor: enter l"<<std::endl;
    std::cout<<"Cancel: enter x"<<std::endl;
    std::cout<<"user_input: "<<user_input<<std::endl;
    user_input = get_input(user_input);
    switch (add_comp_options[user_input]) 
    {
      case add_comp_option::add_resistor:
          std::cout << "add resistor!"<<std::endl;
          library.push_back(edit_symbol(get_resistor(), library));
          break;
      case add_comp_option::add_capacitor:
          std::cout << "add capacitor!"<<std::endl; 
          library.push_back(edit_symbol(get_capacitor(), library));
          break;
      case add_comp_option::add_inductor:
          std::cout << "add inductor!"<<std::endl;
          library.push_back(edit_symbol(get_inductor(), library));
          break; 
      case add_comp_option::cancel:
          std::cout << "cancel!";
          is_adding = false; 
          break;
      default:
          std::cout << "Please enter valid option!"<<std::endl;
          break;
    }
  }
}

//Asks user for resistance, creates resistor, and returns pointer to resistor 
resistor_ptr menu::get_resistor()
{
  double resistance{0};
  //Asks for resistance until positive
  while(true) {
    std::cout<<"Enter resisistance (Ohms): "<<std::endl;
    try {
      resistance = get_input(resistance);
      if (resistance > 0) {
        resistor_ptr new_resistor{std::make_shared<resistor>(resistance)};
        std::cout<<resistance<<" Ohm resistor created"<<std::endl;
        return new_resistor;
      } 
      else {
          throw (resistance);
      }
    }
    //If not positive, tell user their input
    catch (const double &input) {
      std::cout<<"Incorrect input. Must be a positive number."<<std::endl;
      std::cout<<"Input: "<<input<<std::endl;
    }
    //Catches any other error caused by getting input
    catch(...) {
      std::cout<<"Input error. Please try again."<<std::endl;
    }
  } 
}

//Asks user for capacitance, creates capacitor, and returns pointer to capacitor 
capacitor_ptr menu::get_capacitor()
{
  double capacitance{0};
  //Asks for capacitance until positive
  while(true) {
    std::cout<<"Enter capacitance (Farads): "<<std::endl;
    try {
      capacitance = get_input(capacitance);
      if (capacitance > 0) {
        capacitor_ptr new_capacitor{std::make_shared<capacitor>(capacitance)};
        std::cout<<capacitance<<" Farad capacitor added"<<std::endl;
        return new_capacitor;
      } 
      else {
          throw (capacitance);
      }
    }
    //If not positive, tell user their input
    catch (const double &input) {
      std::cout<<"Incorrect input. Must be a positive number."<<std::endl;
      std::cout<<"Input: "<<input<<std::endl;
    }
    //Catches any other error caused by getting input
    catch(...) {
      std::cout<<"Input error. Please try again."<<std::endl;
    }
  }
}

//Asks user for inductance, creates inductor, and returns pointer to inductor 
inductor_ptr menu::get_inductor()
{
  double inductance{0};
  //Asks for inductance until positive
  while(true) {
    std::cout<<"Enter inductance (Henrys): "<<std::endl;
    try {
      inductance = get_input(inductance);
      if (inductance > 0) {
        inductor_ptr new_inductor{std::make_shared<inductor>(inductance)};
        std::cout<<inductance<<" Henry capacitor added"<<std::endl;
        return new_inductor;
      } 
      else {
          throw (inductance);
      }
    }
    //If not positive, tell user their input
    catch (const double &input) {
      std::cout<<"Incorrect input. Must be a positive number."<<std::endl;
      std::cout<<"Input: "<<input<<std::endl;
    }
    //Catches any other error caused by getting input
    catch(...) {
      std::cout<<"Input error. Please try again."<<std::endl;
    }
  }
}

//Checks if integer 'x' is greater than 'low' and less than 'high'
bool menu::in_range(int low, int high, int x)
{
return (low <= x && x <= high);
}

//Shows the user the library,
//asks user to select the number of a component as
//ordered in the library, and returns corresponding pointer.
component_ptr menu::get_from_lib() 
{
  std::cout<<"Please select component or circuit from library"<<std::endl;
  show_library();
  std::cout<<"Enter component number: "<<std::endl;
  int component_number{-1};
  //Asks for component until valid number given
  while(true) {
    try {
      component_number = get_input(component_number);
      //Check if component exists
      if (in_range(1, library.size(), component_number)) {
        component_ptr comp = library[component_number-1];
        std::cout<<"Component "<<component_number<<" selected."<<std::endl;
        return comp;
      } 
      else {
        throw (component_number);
      }
    }
    //Tell user if component choice doesn't exist
    catch (const double &input) {
      std::cout<<"Incorrect input. Component number must be listed in library."<<std::endl;
      std::cout<<"Input: "<<input<<std::endl;
    }
    //Catches any other error caused by getting input
    catch(...) {
      std::cout<<"Input error. Please try again."<<std::endl;
    }
  }
}


//Creates a new circuit and allows user to edit it 
//before adding the circuit pointer to component library
void menu::add_circuit_menu() 
{
  circuit new_circuit;
  edit_circuit_menu(new_circuit);
  auto new_circuit_ptr = std::make_shared<circuit_component>(new_circuit);
  //new_circuit.set_symbol(new_circuit.get_symbol() + std::to_string(circuit_count));
  library.push_back(edit_symbol(new_circuit_ptr, library));
  std::cout<<"Circuit added to library"<<std::endl;
}

//List options for adding component in series or parallel
enum class menu::get_is_series_option 
{
  series=1, parallel=2
};

//Set user input strings for adding component in series or parallel
void menu::register_get_is_series_options()
{
  get_is_series_options["s"] = get_is_series_option::series;
  get_is_series_options["p"] = get_is_series_option::parallel;
}

//Asks user if they want to add component in series or parallel.
//Returns true for series, false for parallel.
bool menu::get_is_series()
{
  register_get_is_series_options();
  std::string user_input;
  //Asks for series/parallel until valid number given
  while(true) {
    std::cout<<"Add in series or parallel? "<<std::endl;
    std::cout<<"Series: enter s"<<std::endl;
    std::cout<<"Parallel: enter p"<<std::endl;
    user_input = get_input(user_input);
    std::cout<<"user_input: "<<user_input;
    switch (get_is_series_options[user_input]) 
    {
      case get_is_series_option::series:
          return true;
          break;
      case get_is_series_option::parallel:
          return false;
          break;
      //If input string invalid, remind user
      default:
          std::cout << "Please enter s or p"<<std::endl;
          break;
    }
  }
}

//Asks user for frequency until positive
//number is given, then returns input
double menu::get_frequency() 
{
  double frequency{0};
  while(true) {
    std::cout<<"Enter frequency: "<<std::endl;
    frequency = get_input(frequency);
    if(frequency>0) {
      return frequency;
    }
    else {
      std::cout<<"Frequency must be positive"<<std::endl;
    }
  }
}

//List options for circuit editing menu
enum class menu::edit_circuit_option 
{
  add_resistor=1, add_capacitor=2, add_inductor=3, add_from_lib=4,
  set_frequency=5, show_info=6, draw=7, cancel=8
};
//Set input strings for circuit editing menu options
void menu::register_edit_circuit_options()
{
  edit_circuit_options["r"] = edit_circuit_option::add_resistor;
  edit_circuit_options["c"] = edit_circuit_option::add_capacitor;
  edit_circuit_options["l"] = edit_circuit_option::add_inductor;
  edit_circuit_options["lib"] = edit_circuit_option::add_from_lib;
  edit_circuit_options["f"] = edit_circuit_option::set_frequency;
  edit_circuit_options["info"] = edit_circuit_option::show_info;
  edit_circuit_options["draw"] = edit_circuit_option::draw;
  edit_circuit_options["x"] = edit_circuit_option::cancel;
}

//Gives user options how to edit circuit by adding component,
//setting frequency, showing info, drawing circuit digram, or cancelling. 
//Executes corresponding menu function or exits if user cancels.
void menu::edit_circuit_menu(circuit& circ)
{
  bool is_running {true};
  register_edit_circuit_options();
  //Ask user until they cancel the menu what they want to do
  while (is_running) {
    std::string user_input;
    std::cout<<std::endl;
    std::cout<<"What would you like to do to the circuit?"<<std::endl;
    std::cout<<"Add resistor: enter r"<<std::endl;
    std::cout<<"Add capacitor: enter c"<<std::endl;
    std::cout<<"Add inductor: enter l"<<std::endl;
    std::cout<<"Add component from library: enter lib"<<std::endl;
    std::cout<<"Set frequency: enter f"<<std::endl;
    std::cout<<"Show info: enter info"<<std::endl;
    std::cout<<"Show diagram: enter draw"<<std::endl;
    std::cout<<"Cancel: enter x"<<std::endl;
    user_input = get_input(user_input);
    switch (edit_circuit_options[user_input]) 
    {
      case edit_circuit_option::add_resistor:
          std::cout << "add resistor!"<<std::endl;
          circ.add_component(get_resistor(), get_is_series());
          break;
      case edit_circuit_option::add_capacitor:
          std::cout << "add capacitor!"<<std::endl; 
          circ.add_component(get_capacitor(), get_is_series());
          break;
      case edit_circuit_option::add_inductor:
          std::cout << "add inductor!"<<std::endl;
          circ.add_component(get_inductor(), get_is_series());
          break;
      case edit_circuit_option::add_from_lib:
          std::cout << "add from library!"<<std::endl;
          circ.add_component(get_from_lib(), get_is_series());
          break; 
      case edit_circuit_option::set_frequency:
          std::cout << "Set frequency!"<<std::endl;
          circ.set_frequency(get_frequency());
          break;
      case edit_circuit_option::show_info:
          std::cout << "Show info!"<<std::endl;
          circ.print_info();
          break;
      case edit_circuit_option::draw:
          std::cout << "Draw!"<<std::endl;
          circ.draw();
          break;    
      case edit_circuit_option::cancel:
          std::cout << "cancel!";
          is_running = false; 
          break;
      default:
          std::cout << "Please enter valid option!"<<std::endl;
          break;
    }
  }
}

//Prints information for all components in library
void menu::show_library() 
{
  std::cout<<"All components in library: "<<std::endl;
  int item_number{0};
  for(auto const &item : library) {
    item_number++;
    std::cout<<"Component "<<item_number<<":  ";
    item->print_info();
    std::cout<<std::endl;
  }
}






