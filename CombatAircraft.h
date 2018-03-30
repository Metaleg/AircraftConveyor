//
// Created by metalleg on 24.03.18.
//

#ifndef TECHPROGKURSACH_WARPLANEBUILDER_H
#define TECHPROGKURSACH_WARPLANEBUILDER_H

#include "AircraftBuilder.h"
class CombatAircraft:public AircraftBuilder{
    friend class Director;

    CombatAircraft() = default;
    ~CombatAircraft() = default;

    void create() override;
    void build_name() override;
    void build_military_civil() override;
    void build_type() override;
    void build_weight() override;
    void build_engines() override;
    void build_wings() override;
    void build_chassis() override;
    void build_speed() override;
    void build_takeoff_land() override;
    void build_control() override;
    void build_crew() override;
    void build_year() override;
    void build_weapon() override;

public:
    CombatAircraft(const CombatAircraft& pas) = delete;
    CombatAircraft(CombatAircraft&& pas) = delete;
    CombatAircraft&operator=(const CombatAircraft& pas) = delete;
    CombatAircraft&operator=(CombatAircraft&& pas) = delete;

    static CombatAircraft&build();
};

#endif //TECHPROGKURSACH_WARPLANEBUILDER_H
