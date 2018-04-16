//
// Created by metalleg on 24.03.18.
//

#include "QuadcopterBuilder.h"

QuadcopterBuilder& QuadcopterBuilder::build() {
    static QuadcopterBuilder quad;
    return quad;
}

void QuadcopterBuilder::create() {
    aircraft = std::make_shared<Aircraft>();
    //aircraft->set_p_type_(quadcopter);
}

void QuadcopterBuilder::build_name() {
    std::cout << "Enter quadcopter name: ";
    aircraft->set_name(set_string());
}

void QuadcopterBuilder::build_military_civil() {
    std::cout << "Enter quadcopter type: military or civil: ";
    aircraft->set_militaty_civil(set_string());
}

void QuadcopterBuilder::build_type() {
    std::cout << "Enter quadcopter type: ";
    aircraft->set_type(set_string());
}

void QuadcopterBuilder::build_weight() {
    std::cout << "Enter takeoff weight: ";
    aircraft->set_takeoff_weight(set_int());
}

void QuadcopterBuilder::build_engines() {
    std::cout << "Enter engines type: ";
    aircraft->set_engine_type(set_string());
    std::cout << "Enter number of engines: ";
    aircraft->set_engines(set_int());
}

void QuadcopterBuilder::build_speed() {
    std::cout << "Enter flight speed: ";
    aircraft->set_flight_speed_(set_int());
}

void QuadcopterBuilder::build_takeoff_land() {
    aircraft->set_takeoff_landing_type("Vertical take-off");
}

void QuadcopterBuilder::build_control() {
    aircraft->set_control_method("Remote control");
}

void QuadcopterBuilder::build_year() {
    std::cout << "Enter year of production: ";
    aircraft->set_year_of_product_(set_int());
}

void QuadcopterBuilder::build_weapon() {
    std::cout << "Enter weapon type: ";
    aircraft->set_weapon_type(set_string());
}