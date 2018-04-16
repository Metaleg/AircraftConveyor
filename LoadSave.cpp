//
// Created by metalleg on 07.04.18.
//

#include "LoadSave.h"

LoadSave &LoadSave::loadsave() {
    static LoadSave ls;
    return ls;
}

std::string LoadSave::return_filename(aircraft_type &p_type) {
    std::string filename;

    switch (p_type){
        case passenger_aircraft:
            filename = "passenger_aircraft.xml";
            break;
        case combat_aircraft:
            filename = "combat_aircraft.xml";
            break;
        case helicopter:
            filename = "helicopter.xml";
            break;
        case quadcopter:
            filename = "quadcopter.xml";
            break;
        default:
            std::cerr << "This type of aircraft is not supported!\n";
            return nullptr;
    }
    return filename;
}

void LoadSave::save(std::set<Aircraft, std::less<>> &aircraft,  aircraft_type &p_type) {
    std::string path;
    for (auto &it : aircraft) {
        aircraft_.put(it.get_name(), "");
        path = it.get_name() + ".mil_civ";
        aircraft_.put(path, it.get_military_civil());
        path = it.get_name() + ".type";
        aircraft_.put(path, it.get_type());
        path = it.get_name() + ".weight";
        aircraft_.put(path, it.get_takeoff_weight());
        path = it.get_name() + ".engines";
        aircraft_.put(path, it.get_engines());
        path = it.get_name() + ".engines_type";
        aircraft_.put(path, it.get_engine_type());
        path = it.get_name() + ".wings";
        aircraft_.put(path, it.get_wings());
        path = it.get_name() + ".wings_location";
        aircraft_.put(path, it.get_wings_location());
        path = it.get_name() + ".chassis";
        aircraft_.put(path, it.get_chassis_type());
        path = it.get_name() + ".speed";
        aircraft_.put(path, it.get_flight_speed());
        path = it.get_name() + ".landing_type";
        aircraft_.put(path, it.get_takeoff_landing_type());
        path = it.get_name() + ".control";
        aircraft_.put(path, it.get_control_method());
        path = it.get_name() + ".crew";
        aircraft_.put(path, it.get_crew());
        path = it.get_name() + ".year";
        aircraft_.put(path, it.get_year_of_product());
        path = it.get_name() + ".weapon";
        aircraft_.put(path, it.get_weapon_type());
    }
    boost::property_tree::write_xml(return_filename(p_type), aircraft_);
}

void LoadSave::load(std::set<Aircraft, std::less<>> &aircraft, aircraft_type &p_type) {
    std::ifstream file(return_filename(p_type));
    if(!file){
        std::cerr << "Can`t open file " << return_filename(p_type) << std::endl;
        return;
    }

    Aircraft air;
    boost::property_tree::read_xml(return_filename(p_type), aircraft_);

    for(boost::property_tree::ptree::value_type &it : aircraft_){
        std::string name = it.first;
        std::string path;
        air.set_name(name);
        path = name + ".mil_civ";
        air.set_militaty_civil(aircraft_.get<std::string>(path));
        path = name + ".type";
        air.set_type(aircraft_.get<std::string>(path));
        path = name + ".weight";
        air.set_takeoff_weight(aircraft_.get<int>(path));
        path = name + ".engines";
        air.set_engines(aircraft_.get<int>(path));
        path = name + ".engines_type";
        air.set_engine_type(aircraft_.get<std::string>(path));
        path = name + ".wings";
        air.set_wings(aircraft_.get<int>(path));
        path = name + ".wings_location";
        air.set_wings_location(aircraft_.get<std::string>(path));
        path = name + ".chassis";
        air.set_chassis_type(aircraft_.get<std::string>(path));
        path = name + ".speed";
        air.set_flight_speed_(aircraft_.get<int>(path));
        path = name + ".landing_type";
        air.set_takeoff_landing_type(aircraft_.get<std::string>(path));
        path = name + ".control";
        air.set_control_method(aircraft_.get<std::string>(path));
        path = name + ".crew";
        air.set_crew_(aircraft_.get<int>(path));
        path = name + ".year";
        air.set_year_of_product_(aircraft_.get<int>(path));
        path = name + ".weapon";
        air.set_weapon_type(aircraft_.get<std::string>(path));

        aircraft.emplace(air);
    }
    std::cout << "\nLoad is successful!\n";
}
