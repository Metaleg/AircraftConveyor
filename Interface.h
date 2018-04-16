//
// Created by metalleg on 11.04.18.
//

#ifndef TECHPROGKURSACH_INTERFACE_H
#define TECHPROGKURSACH_INTERFACE_H

#include "Director.h"
#include "PassengerAircraftBuilder.h"
#include "CombatAircraftBuilder.h"
#include "HelicopterBuilder.h"
#include "QuadcopterBuilder.h"
#include "Aircraft.h"
#include "LoadSave.h"
#include <algorithm>
#include <set>
#include <iterator>


void load(std::set<Aircraft, std::less<>> &aircraft, char &sel);
void save(std::set<Aircraft, std::less<>> &aircraft, char &sel);
void search_by_name(std::set<Aircraft, std::less<>> &aircraft, char &sel);
void show(std::set<Aircraft, std::less<>> &aircraft, char &sel);
void aircraft_conveyor();


#endif //TECHPROGKURSACH_INTERFACE_H
