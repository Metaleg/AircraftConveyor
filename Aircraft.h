//
// Created by metalleg on 24.03.18.
//

#ifndef TECHPROGKURSACH_PLANE_H
#define TECHPROGKURSACH_PLANE_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <memory>
#include <cstdio>

const int SIZE = 50;
enum aircraft_type{none, passenger_aircraft, combat_aircraft, helicopter, quadcopter};
class Exception{};

class Aircraft{
    aircraft_type p_type_;
    char name_[SIZE];
    char military_civil_[SIZE];
    char type_[SIZE];
    int takeoff_weight_;
    int engines_;
    char engine_type_[SIZE];
    int wings_;
    char wings_location_[SIZE];
    char chassis_type_[SIZE];
    int flight_speed_;
    char takeoff_landing_type_[SIZE];
    char control_method_[SIZE];
    int crew_;
    int year_of_product_;
    char weapon_type_[SIZE];


public:
    Aircraft() noexcept;
    explicit Aircraft(char name[]) noexcept;
    Aircraft(const Aircraft& plane) noexcept;
    Aircraft(Aircraft&& plane) noexcept;
    Aircraft& operator=(const Aircraft& plane) = default;
    Aircraft& operator=(Aircraft&& plane) noexcept;
    ~Aircraft() = default;

    void write();
    void read(int&, aircraft_type&);

    void set_p_type_(aircraft_type p_type);
    void set_name(char* name);
    void set_militaty_civil(char* military_civil);
    void set_type(char* type);
    void set_takeoff_weight_(int takeoff_weight);
    void set_engines(int engines);
    void set_engine_type(char* engine_type);
    void set_wings_(int wings);
    void set_wings_location(char* wings_location);
    void set_chassis_type(char* chassis_type);
    void set_flight_speed_(int flight_speed);
    void set_takeoff_landing_type(char* takeoff_landing_type);
    void set_control_method(char* control_method);
    void set_crew_(int crew);
    void set_year_of_product_(int year_of_product);
    void set_weapon_type(char* weapon_type);

    const char *get_name() const;

    //size of files
    static int passenger_plane_count();
    static int warplane_count();
    static int helicopter_count();
    static int quadcopter_count();

    friend std::ostream &operator<<(std::ostream &os, const Aircraft &plane);
    bool operator<(const Aircraft &rhs) const;
    bool operator>(const Aircraft &rhs) const;
    bool operator==(const Aircraft &rhs) const;
    bool operator!=(const Aircraft &rhs) const;
};

#endif //TECHPROGKURSACH_PLANE_H