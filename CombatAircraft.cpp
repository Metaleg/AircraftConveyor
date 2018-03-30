//
// Created by metalleg on 24.03.18.
//

#include "CombatAircraft.h"

CombatAircraft& CombatAircraft::build() {
    static CombatAircraft war;
    return war;
}

void CombatAircraft::create() {
    aircraft = std::make_shared<Aircraft>();
    aircraft->set_p_type_(combat_aircraft);
}

void CombatAircraft::build_name() {
    std::cout << "Enter aircraft name: ";
    char ch[SIZE];
    std::cin >> ch;
    aircraft->set_name(ch);
}

void CombatAircraft::build_military_civil() {
    aircraft->set_militaty_civil("Military");
}

void CombatAircraft::build_type() {
    std::cout << "Enter aircraft type: ";
    char ch[SIZE];
    std::cin >> ch;
    aircraft->set_type(ch);
}

void CombatAircraft::build_weight() {
    std::cout << "Enter takeoff weight: ";
    aircraft->set_takeoff_weight_(set_int());
}

void CombatAircraft::build_engines() {
    std::cout << "Enter engines type: ";
    char ch[SIZE];
    std::cin >> ch;
    aircraft->set_engine_type(ch);
    std::cout << "Enter number of engines: ";
    aircraft->set_engines(set_int());
}

void CombatAircraft::build_wings() {
    std::cout << "Enter wings location: ";
    char ch[SIZE];
    std::cin >> ch;
    aircraft->set_wings_location(ch);
    std::cout << "Enter number of wings: ";
    aircraft->set_wings_(set_int());
}

void CombatAircraft::build_chassis() {
    std::cout << "Enter chassis type: ";
    char ch[SIZE];
    std::cin >> ch;
    aircraft->set_chassis_type(ch);
}

void CombatAircraft::build_speed() {
    std::cout << "Enter flight speed: ";
    aircraft->set_flight_speed_(set_int());
}

void CombatAircraft::build_takeoff_land() {
    std::cout << "Enter takeoff landing type: ";
    char ch[SIZE];
    std::cin >> ch;
    aircraft->set_takeoff_landing_type(ch);
}

void CombatAircraft::build_control() {
    std::cout << "Enter control method: ";
    char ch[SIZE];
    std::cin >> ch;
    aircraft->set_control_method(ch);
}

void CombatAircraft::build_crew() {
    std::cout << "Enter number of crew: ";
    aircraft->set_crew_(set_int());
}

void CombatAircraft::build_year() {
    std::cout << "Enter year of production: ";
    aircraft->set_year_of_product_(set_int());
}

void CombatAircraft::build_weapon() {
    std::cout << "Enter weapon type: ";
    char ch[SIZE];
    std::cin >> ch;
    aircraft->set_weapon_type(ch);
}
