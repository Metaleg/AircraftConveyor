//
// Created by metalleg on 24.03.18.
//

#include "PassengerAircraftBuilder.h"

PassengerAircraftBuilder& PassengerAircraftBuilder::build() {
    static PassengerAircraftBuilder pas;
    return pas;
}

void PassengerAircraftBuilder::create() {
    aircraft = std::make_shared<Aircraft>();
}

void PassengerAircraftBuilder::build_name() {
    std::cout << "Enter aircraft name: ";
    aircraft->set_name(set_string());
}

void PassengerAircraftBuilder::build_military_civil() {
    std::cout << "Enter aircraft type: military or civil: ";
    aircraft->set_militaty_civil(set_string());
}

void PassengerAircraftBuilder::build_type() {
    std::cout << "Enter aircraft type: ";
    aircraft->set_type(set_string());
}

void PassengerAircraftBuilder::build_weight() {
    std::cout << "Enter takeoff weight: ";
    aircraft->set_takeoff_weight(set_int());
}

void PassengerAircraftBuilder::build_engines() {
    std::cout << "Enter engines type: ";
    aircraft->set_engine_type(set_string());
    std::cout << "Enter number of engines: ";
    aircraft->set_engines(set_int());
}

void PassengerAircraftBuilder::build_wings() {
    std::cout << "Enter wings location: ";
    aircraft->set_wings_location(set_string());
    std::cout << "Enter number of wings: ";
    aircraft->set_wings(set_int());
}

void PassengerAircraftBuilder::build_chassis() {
    std::cout << "Enter chassis type: ";
    aircraft->set_chassis_type(set_string());
}

void PassengerAircraftBuilder::build_speed() {
    std::cout << "Enter flight speed: ";
    aircraft->set_flight_speed_(set_int());
}

void PassengerAircraftBuilder::build_takeoff_land() {
    std::cout << "Enter takeoff landing type: ";
    aircraft->set_takeoff_landing_type(set_string());
}

void PassengerAircraftBuilder::build_control() {
    std::cout << "Enter control method: ";
    aircraft->set_control_method(set_string());
}

void PassengerAircraftBuilder::build_crew() {
    std::cout << "Enter number of crew: ";
    aircraft->set_crew_(set_int());
}

void PassengerAircraftBuilder::build_year() {
    std::cout << "Enter year of production: ";
    aircraft->set_year_of_product_(set_int());
}

