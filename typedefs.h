// AC-Circuits/typedefs.h
// Header file for custom type definitions
// Frederik Brooke Barnes, Last modified 10/5/2021

//Include guard
#ifndef TYPEDEFS_H
#define TYPEDEFS_H
//Includes
#include<vector>
#include<memory>
#include "component.h"
#include "resistor.h"
#include "capacitor.h"
#include "inductor.h"
#include "circuit_component.h"

//Type definitions useful as shorthand
typedef std::vector<std::shared_ptr<component>> library_vector;
typedef std::shared_ptr<component> component_ptr;
typedef std::shared_ptr<resistor> resistor_ptr;
typedef std::shared_ptr<capacitor> capacitor_ptr;
typedef std::shared_ptr<inductor> inductor_ptr;
typedef std::shared_ptr<circuit_component> circuit_component_ptr;

#endif
