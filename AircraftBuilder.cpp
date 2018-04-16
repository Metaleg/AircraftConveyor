//
// Created by metalleg on 24.03.18.
//

#include "AircraftBuilder.h"

std::shared_ptr<Aircraft>AircraftBuilder::get() noexcept {
    return aircraft;
}

int AircraftBuilder::set_int() {
    int arg;
    std::cin >> arg;
    std::cin.ignore(10, '\n');
    if(!(std::cin.good()))
        throw Validator();
    else
        return arg;
}

std::string AircraftBuilder::set_string() {
    std::string arg;
    std::cin >> arg;
    std::cin.ignore(20, '\n');
    if(!(std::cin.good()))
        throw Validator();
    else
        return arg;
}