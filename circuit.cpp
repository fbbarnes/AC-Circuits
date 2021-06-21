// AC-Circuits/circuit.cpp
// Implementation file for circuit class definition
// Frederik Brooke Barnes, Last modified 2/5/2021

#include<iostream>
#include<cmath>
#include "circuit.h"
#include "component.h"
#include "circuit_component.h"

//Updates the circuit's impedance depending on the component added
//and whether the component is added is series or parallel
void circuit::update_impedance(std::shared_ptr<component> &comp, bool is_series)
{
  //get component impedance with circuit's frequency
  complex comp_impedance = comp->get_impedance(frequency);
  //if added in series, add impedances
  if (is_series) {
    impedance = impedance + comp_impedance;
  } else {
    //if in parallel and is 1st component, set circuit to component impedance
    if (component_list.empty()) {
      impedance = comp_impedance;
      //if in parallel and not 1st component, add impedances in parallel
    } else {
        impedance = complex(1,0) / ((complex(1,0) / impedance) + (complex(1,0) / comp_impedance));
      }
    }
}

//Adds component to circuit in parallel or series:
//sets component frequency, updates circuit impedance, and adds component
//to list of components in circuit
void circuit::add_component(std::shared_ptr<component> comp, bool is_series) 
{
    comp->set_frequency(frequency);
    update_impedance(comp, is_series);
    component_list.push_back(component_list_item(comp, is_series));
}

//Updates frequency and recalculates impedance
void circuit::set_frequency(double F) 
{
  //Set frequency
  std::cout<<"Setting frequency to "<<F<<" Hz"<<std::endl;
  frequency = F;
  //Reset impedance
  impedance = complex(0,0);
  //Reconstruct circuit
  std::vector<component_list_item> temp_list;
  temp_list.swap(component_list);
  for(auto item : temp_list) {
    add_component(item.comp, item.is_series);
    //add_component also updates impedance
  }
}

//Returns circuit impedance
complex circuit::get_impedance()
{
  return impedance;
}
//Returns magnitude of circuit impedance
double circuit::get_magnitude() 
{
  complex Z = this->get_impedance();
  return Z.modulus();
}
//Returns phase of circuit impedance
double circuit::get_phase()
{
  complex Z = this->get_impedance();
  return Z.argument();
}
//Returns circuit frequency in Hz
double circuit::get_frequency()
{
  return frequency;
}

//Displays info about circuit impedance and components
void circuit::print_info()
{
  std::cout<<"Circuit Impedance: "<<impedance<<" Ohm"<<std::endl;
  std::cout<<"        Frequency: "<<frequency<<" Hz"<<std::endl;
  std::cout<<"        Magnitude: "<<get_magnitude()<<" Ohms"<<std::endl;
  std::cout<<"        Phase: "<<get_phase()<<" rad"<<std::endl;
  std::cout<<"        Circuit components: "<<std::endl;
  for(const auto item : component_list) {
    std::cout<<"              ";
    item.comp->print_info();
  }
}

//Displays a text-based circuit diagram
void circuit::draw() 
{
  //Vector of strings for output drawn line by line
  std::vector<std::string> output_lines;
  //Find largest no. of chars used in component symbols
  int max_symbol_len{0};
  for (const auto item : component_list) {
    int symbol_len = item.comp->get_symbol().length();
    max_symbol_len = (max_symbol_len < symbol_len) ? symbol_len : max_symbol_len;
  }
  //Draw circuit terminal wire
  //Length of terminal wires depends on size of biggest circuit symbol
  std::string terminal_wire((max_symbol_len + 1), '-');
  output_lines.push_back(terminal_wire);
  //Dimensions of circuit diagram measured in no. of components
  //width is no. components in series
  //height is no. components in series
  int width{0};
  int height{0};
  //Add wires and symbols of each component in circuit
  for(const auto item : component_list) {
    //Get symbol string and length
    std::string symbol {item.comp->get_symbol()};
    long unsigned int symbol_length {symbol.length()};
    bool symbol_length_is_even {!(symbol_length % 2)};
    //Draw component added in series
    if(item.is_series == 1) {
      //Wires drawn as "-"
      output_lines[0].append("--");
      output_lines[0].append(symbol);
      output_lines[0].append("-");
      //Increase circuit width
      width ++;
      //Increse height if 1st component added
      height = (height == 0) ? 1 : height;
      //Draw component added in parallel
    } else {
        //If not 1st component in circuit
        if (width > 0) {
          //Add one line (row) for spacer and another for new symbol
          output_lines.push_back("");
          output_lines.push_back("");
          //Indexes corresponding to lines being edited
          int new_line = (2 * height);
          int spacer_line = new_line - 1;
          int first_line = 0;
          //Add vertical (parallel) wires "|" and spaces depending on width of first line
          output_lines[spacer_line].append("  |");
          int num_spaces = output_lines[first_line].length() - 3;
          std::string spaces(num_spaces, ' ');
          output_lines[spacer_line].append(spaces);
          output_lines[spacer_line].append("|");
          //Draw line with symbol 
          output_lines[new_line].append("  ");
          //Set wires (dashes) to correct length
          int num_dashes = (num_spaces - symbol_length + 2);
          int num_left_dashes = num_dashes / 2;
          std::string left_dashes(num_left_dashes, '-');
          //Add wires to left of symbol
          output_lines[new_line].append(left_dashes);
          //Add symbol
          output_lines[new_line].append(symbol);
          //Add wires to right of symbol
          int num_right_dashes = num_dashes - num_left_dashes;
          std::string right_dashes(num_right_dashes, '-');
          output_lines[new_line].append(right_dashes);
          //Add vertical parallel wires to previously drawn lines
          int new_line_length = output_lines[new_line].length();
          for(auto& line : output_lines) {
            //Don't edit new line
            if(line == output_lines.front()) continue;
            //Edit previous lines so their width matches new line and add vertical wire
            if (line.length() < new_line_length) {
              int length_diff = new_line_length - line.length();
              std::string spaces(length_diff - 1, ' ');
              line.append(spaces);
              line.append("|");
            }
            for(auto line : output_lines) {
              //std::cout<<line<<std::endl;
            }
          }
          //If parallel component is 1st, draw as in series
        } else {
          output_lines[0].append("--");
          output_lines[0].append(symbol);
          output_lines[0].append("-");
        }
        //Update dimensions of circuit
        height ++;
        width = (width == 0) ? 1 : width;
      }
  }
  //Add output terminal wire
  output_lines[0].append(terminal_wire);
  //Print circuit line by line
  std::cout<<std::endl<<"Circuit diagram:"<<std::endl;
  for(auto line : output_lines) {
    std::cout<<line<<std::endl;
  }
  std::cout<<std::endl;   
}


