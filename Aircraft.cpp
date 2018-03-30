//
// Created by metalleg on 24.03.18.
//

#include "Aircraft.h"

Aircraft::Aircraft() noexcept {
    p_type_ = none;
    strcpy(name_, "");
    strcpy(military_civil_, "");
    strcpy(type_, "");
    takeoff_weight_ = 0;
    engines_ = 0;
    strcpy(engine_type_, "");
    wings_ = 0;
    strcpy(wings_location_, "none");
    strcpy(chassis_type_, "none");
    flight_speed_ = 0;
    strcpy(takeoff_landing_type_, "");
    strcpy(control_method_, "");
    crew_ = 0;
    year_of_product_ = 0;
    strcpy(weapon_type_, "none");
}

Aircraft::Aircraft(char *name) noexcept {
    p_type_ = none;
    strcpy(name_, name);
    strcpy(military_civil_, "");
    strcpy(type_, "");
    takeoff_weight_ = 0;
    engines_ = 0;
    strcpy(engine_type_, "");
    wings_ = 0;
    strcpy(wings_location_, "none");
    strcpy(chassis_type_, "none");
    flight_speed_ = 0;
    strcpy(takeoff_landing_type_, "");
    strcpy(control_method_, "");
    crew_ = 0;
    year_of_product_ = 0;
    strcpy(weapon_type_, "none");
}

Aircraft::Aircraft(const Aircraft& plane) noexcept {
    p_type_ = plane.p_type_;
    strcpy(name_, plane.name_);
    strcpy(military_civil_, plane.military_civil_);
    strcpy(type_, plane.type_);
    takeoff_weight_ = 0;
    engines_ = 0;
    strcpy(engine_type_, plane.engine_type_);
    wings_ = 0;
    strcpy(wings_location_, plane.wings_location_);
    strcpy(chassis_type_, plane.chassis_type_);
    flight_speed_ = 0;
    strcpy(takeoff_landing_type_, plane.takeoff_landing_type_);
    strcpy(control_method_, plane.control_method_);
    crew_ = 0;
    year_of_product_ = 0;
    strcpy(weapon_type_, plane.weapon_type_);
}

Aircraft::Aircraft(Aircraft&& plane) noexcept {
    *this = std::move(plane);
}

Aircraft &Aircraft::operator=(Aircraft&& plane) noexcept {
    p_type_ = plane.p_type_;
    strcpy(name_, plane.name_);
    strcpy(military_civil_, plane.military_civil_);
    strcpy(type_, plane.type_);
    takeoff_weight_ = 0;
    engines_ = 0;
    strcpy(engine_type_, plane.engine_type_);
    wings_ = 0;
    strcpy(wings_location_, plane.wings_location_);
    strcpy(chassis_type_, plane.chassis_type_);
    flight_speed_ = 0;
    strcpy(takeoff_landing_type_, plane.takeoff_landing_type_);
    strcpy(control_method_, plane.control_method_);
    crew_ = 0;
    year_of_product_ = 0;
    strcpy(weapon_type_, plane.weapon_type_);

    plane.p_type_ = none;
    strcpy(plane.name_, "");
    strcpy(plane.military_civil_, "");
    strcpy(plane.type_, "");
    plane.takeoff_weight_ = 0;
    plane.engines_ = 0;
    strcpy(plane.engine_type_, "");
    plane.wings_ = 0;
    strcpy(plane.wings_location_, "none");
    strcpy(plane.chassis_type_, "none");
    plane.flight_speed_ = 0;
    strcpy(plane.takeoff_landing_type_, "");
    strcpy(plane.control_method_, "");
    plane.crew_ = 0;
    plane. year_of_product_ = 0;
    strcpy(plane.weapon_type_, "none");

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Aircraft &plane) {
    os << std::endl << plane.name_ << ", " << plane.military_civil_ <<", " << "type " << plane.type_ <<std::endl
       << "takeoff weight: " << plane.takeoff_weight_ << " kilograms" << std::endl
       << plane.engines_ << " engines, " << "type " << plane.engine_type_ << std::endl
       << plane.wings_ << " wings, " << "locating in " << plane.wings_location_ << std::endl
       << "type of chassis: " << plane.chassis_type_ << std::endl
       << "flight speed: " << plane.flight_speed_ << " km/h" << std::endl
       << "type of takeoff landing: " << plane.takeoff_landing_type_ << std::endl
       << "method of control: " << plane.control_method_ << std::endl
       << "crew of " << plane.crew_ << " people" << std::endl
       << plane.year_of_product_ << " year of production" << std::endl
       << "type of weapon: " << plane.weapon_type_ << std::endl;
    return os;
}

bool Aircraft::operator==(const Aircraft &rhs) const {
    return p_type_ == rhs.p_type_ &&
           name_ == rhs.name_ ;
}

bool Aircraft::operator!=(const Aircraft &rhs) const {
    return !(rhs == *this);
}

bool Aircraft::operator<(const Aircraft &rhs) const {
    return this->name_ < rhs.name_;
}

bool Aircraft::operator>(const Aircraft &rhs) const {
    return this->name_ > rhs.name_;
}

int Aircraft::passenger_plane_count() {
    std::ifstream file;
    file.open("passenger_aircraft.DAT", std::ios::binary);
    if(!file){
        std::cout << "Error! Can`t open file!\n";
        exit(1);
    }
    file.seekg(0, std::ios::end);
    return (int)file.tellg() / sizeof(Aircraft);
}

int Aircraft::warplane_count() {
    std::ifstream file;
    file.open("combat_aircraft.DAT", std::ios::binary);
    if(!file){
        std::cout << "Error! Can`t open file!\n";
        exit(1);
    }
    file.seekg(0, std::ios::end);
    return (int)file.tellg() / sizeof(Aircraft);
}

int Aircraft::helicopter_count() {
    std::ifstream file;
    file.open("helicopter.DAT", std::ios::binary);
    if(!file){
        std::cout << "Error! Can`t open file!\n";
        exit(1);
    }
    file.seekg(0, std::ios::end);
    return (int)file.tellg() / sizeof(Aircraft);
}

int Aircraft::quadcopter_count() {
    std::ifstream file;
    file.open("quadcopter.DAT", std::ios::binary);
    if(!file){
        std::cout << "Error! Can`t open file!\n";
        exit(1);
    }
    file.seekg(0, std::ios::end);
    return (int)file.tellg() / sizeof(Aircraft);
}

void Aircraft::write() {
    std::ofstream file;
    switch (p_type_) {
        case passenger_aircraft:
            file.open("passenger_aircraft.DAT", std::ios::binary | std::ios::app);
            break;
        case combat_aircraft:
            file.open("combat_aircraft.DAT", std::ios::binary | std::ios::app);
            break;
        case helicopter:
            file.open("helicopter.DAT", std::ios::binary | std::ios::app);
            break;
        case quadcopter:
            file.open("quadcopter.DAT", std::ios::binary | std::ios::app);
            break;
        default: std::cout << "This type of aircraft is not supported!\n";
    }
    file.write((char*)this, sizeof(*this));
    file.close();
}

void Aircraft::read(int& count, aircraft_type& p_type) {
    std::ifstream file;

    switch (p_type) {
        case passenger_aircraft:
            file.open("passenger_aircraft.DAT", std::ios::binary);
            break;
        case combat_aircraft:
            file.open("combat_aircraft.DAT", std::ios::binary);
            break;
        case helicopter:
            file.open("helicopter.DAT", std::ios::binary);
            break;
        case quadcopter:
            file.open("quadcopter.DAT", std::ios::binary);
            break;
        default: std::cout << "This type of aircraft is not supported!\n";
    }
    if(!file){
        std::cout << "Error! can`t open file!\n";
        exit(1);
    }

    file.seekg(count * sizeof(Aircraft));
    file.read((char*)this, sizeof(*this));
    file.close();
}

void Aircraft::set_p_type_(aircraft_type p_type) {
    Aircraft::p_type_ = p_type;
}

void Aircraft::set_name(char *name) {
    strcpy(name_, name);
}

void Aircraft::set_militaty_civil(char *military_civil) {
    strcpy(military_civil_, military_civil);
}

void Aircraft::set_type(char *type) {
    strcpy(type_, type);
}

void Aircraft::set_takeoff_weight_(int takeoff_weight) {
    Aircraft::takeoff_weight_ = takeoff_weight;
}

void Aircraft::set_engines(int engines) {
    Aircraft::engines_ = engines;
}

void Aircraft::set_engine_type(char *engine_type) {
    strcpy(engine_type_, engine_type);
}

void Aircraft::set_wings_(int wings) {
    Aircraft::wings_ = wings;
}

void Aircraft::set_wings_location(char *wings_location) {
    strcpy(wings_location_, wings_location);
}

void Aircraft::set_chassis_type(char *chassis_type) {
    strcpy(chassis_type_, chassis_type);
}

void Aircraft::set_flight_speed_(int flight_speed) {
    Aircraft::flight_speed_ = flight_speed;
}

void Aircraft::set_takeoff_landing_type(char *takeoff_landing_type) {
    strcpy(takeoff_landing_type_, takeoff_landing_type);
}

void Aircraft::set_control_method(char *control_method) {
    strcpy(control_method_, control_method);
}

void Aircraft::set_crew_(int crew) {
    Aircraft::crew_ = crew;
}

void Aircraft::set_year_of_product_(int year_of_product) {
    Aircraft::year_of_product_ = year_of_product;
}

void Aircraft::set_weapon_type(char *weapon_type) {

}

const char *Aircraft::get_name() const {
    return name_;
}
