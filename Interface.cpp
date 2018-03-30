//
// Created by metalleg on 30.03.18.
//

#include "Interface.h"

void read_file(std::set<Aircraft>& aircraft){
    aircraft_type p_type = none;
    char sel = 0;
    Aircraft p;

    std::cout << "Enter type of aircrafts to show: p - passenger aircraft\n"
              << "                                 c - combat aircraft\n"
              << "                                 h - helicopter\n"
              << "                                 q - quadcopter\n";
    std::cout << "Your choose: "; std::cin >> sel;

    switch (sel){
        case 'p':
            p_type = passenger_aircraft;
            for (int i = 0; i < Aircraft::passenger_plane_count(); ++i){
                p.read(i, p_type);
                aircraft.emplace(p);
            }
            break;
        case 'c':
            p_type = combat_aircraft;
            for (int i = 0; i < Aircraft::warplane_count(); ++i){
                p.read(i, p_type);
                aircraft.emplace(p);
            }
            break;
        case 'h':
            p_type = helicopter;
            for (int i = 0; i < Aircraft::helicopter_count(); ++i){
                p.read(i, p_type);
                aircraft.insert(p);
            }
            break;
        case 'q':
            p_type = quadcopter;
            for (int i = 0; i < Aircraft::quadcopter_count(); ++i){
                p.read(i, p_type);
                aircraft.insert(p);
            }
            break;
        default:
            std::cout << "Error! Invalid type!\n";
            break;
    }
}

void create(std::set<Aircraft>& aircraft){
    Director &dir = Director::direct();
    PassengerAircraftBuilder &pas = PassengerAircraftBuilder::build();
    CombatAircraft &comb = CombatAircraft::build();
    HelicopterBuilder &hel = HelicopterBuilder::build();
    QuadcopterBuilder &quad = QuadcopterBuilder::build();
    std::shared_ptr<Aircraft> pl;
    Aircraft p;

    char sel = 0;
    int qnt = 0;

    std::cout << "Enter type of aircrafts: p - passenger aircraft\n"
              << "                         c - combat aircraft\n"
              << "                         h - helicopter\n"
              << "                         q - quadcopter\n";
    std::cout << "Your choice: ";   std::cin >> sel;
    std::cout << "Enter quantity of aircrafts: "; std::cin >> qnt;

    switch (sel){
        case 'p':
            for (int i = 0; i < qnt; ++i){
                std::cout << 'N' << i + 1 << std::endl;
                pl = dir.construct(pas);
                p = *pl;
                aircraft.emplace(p);
            }
            break;

        case 'c':
            for (int i = 0; i < qnt; ++i){
                std::cout << 'N' << i + 1 << std::endl;
                pl = dir.construct(comb);
                p = *pl;
                aircraft.emplace(p);
            }
            break;
        case 'h':
            for (int i = 0; i < qnt; ++i){
                std::cout << 'N' << i + 1 << std::endl;
                pl = dir.construct(hel);
                p = *pl;
                aircraft.emplace(p);
            }
            break;
        case 'q':
            for (int i = 0; i < qnt; ++i){
                std::cout << 'N' << i + 1 << std::endl;
                pl = dir.construct(quad);
                p = *pl;
                aircraft.insert(p);
            }
            break;
        default:
            std::cout << "Error! Invalid type!\n";
            break;
    }
}