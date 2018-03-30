//
// Created by metalleg on 30.03.18.
//

#ifndef TECHPROGKURSACH_INTERFACE_H
#define TECHPROGKURSACH_INTERFACE_H
#include "Director.h"
#include "PassengerAircraftBuilder.h"
#include "CombatAircraft.h"
#include "HelicopterBuilder.h"
#include "QuadcopterBuilder.h"

#include "Aircraft.h"
#include <algorithm>
#include <set>
#include <iterator>


void read_file(std::set<Aircraft>& aircraft);
void create(std::set<Aircraft>& aircraft);


#endif //TECHPROGKURSACH_INTERFACE_H
