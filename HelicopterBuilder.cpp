//
// Created by metalleg on 24.03.18.
//

#include "HelicopterBuilder.h"

HelicopterBuilder& HelicopterBuilder::build() {
    static HelicopterBuilder hel;
    return hel;
}

void HelicopterBuilder::create() {
    aircraft = std::make_shared<Aircraft>();
    aircraft->set_p_type_(helicopter);
}

void HelicopterBuilder::build_name() {
    std::cout << "Enter helicopter name: ";
    char ch[SIZE];
    std::cin >> ch;
    aircraft->set_name(ch);
}

void HelicopterBuilder::build_military_civil() {
    std::cout << "Enter helicopter type: military or civil: ";
    char ch[SIZE];
    std::cin >> ch;
    aircraft->set_militaty_civil(ch);
}

void HelicopterBuilder::build_type() {
    std::cout << "Enter helicopter type: ";
    char ch[SIZE];
    std::cin >> ch;
    aircraft->set_type(ch);
}

void HelicopterBuilder::build_weight() {
    std::cout << "Enter takeoff weight: ";
    aircraft->set_takeoff_weight_(set_int());
}

void HelicopterBuilder::build_engines() {
    std::cout << "Enter engines type: ";
    char ch[SIZE];
    std::cin >> ch;
    aircraft->set_engine_type(ch);
    std::cout << "Enter number of engines: ";
    aircraft->set_engines(set_int());
}

void HelicopterBuilder::build_chassis() {
    std::cout << "Enter chassis type: ";
    char ch[SIZE];
    std::cin >> ch;
    aircraft->set_chassis_type(ch);
}

void HelicopterBuilder::build_speed() {
    std::cout << "Enter flight speed: ";
    aircraft->set_flight_speed_(set_int());
}

void HelicopterBuilder::build_takeoff_land() {
    aircraft->set_takeoff_landing_type("Vertical take-off");
}

void HelicopterBuilder::build_control() {
    std::cout << "Enter control method: ";
    char ch[SIZE];
    std::cin >> ch;
    aircraft->set_control_method(ch);
}

void HelicopterBuilder::build_crew() {
    std::cout << "Enter number of crew: ";
    aircraft->set_crew_(set_int());
}

void HelicopterBuilder::build_year() {
    std::cout << "Enter year of production: ";
    aircraft->set_year_of_product_(set_int());
}

void HelicopterBuilder::build_weapon() {
    std::cout << "Enter weapon type: ";
    char ch[SIZE];
    std::cin >> ch;
    aircraft->set_weapon_type(ch);
}