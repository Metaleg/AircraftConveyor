//
// Created by metalleg on 11.04.18.
//

#include "Interface.h"

void load(std::set<Aircraft, std::less<>> &aircraft, char &sel){
    aircraft_type p_type;
    LoadSave &ls = LoadSave::loadsave();

    std::cout << "Enter type of aircrafts: p - passenger aircraft\n"
              << "                         c - combat aircraft\n"
              << "                         h - helicopter\n"
              << "                         q - quadcopter\n";
    std::cout << "Your choice: ";   std::cin >> sel;

    switch (sel){
        case 'p':
            p_type = passenger_aircraft;
            break;
        case 'c':
            p_type = combat_aircraft;
            break;
        case 'h':
            p_type = helicopter;
            break;
        case 'q':
            p_type = quadcopter;
            break;
        default:
            std::cerr << "Error! Invalid type!\n";
            return;
    }
    ls.load(aircraft, p_type);
}

void save(std::set<Aircraft, std::less<>> &aircraft, char &sel){
    PassengerAircraftBuilder &pas = PassengerAircraftBuilder::build();
    CombatAircraftBuilder &comb = CombatAircraftBuilder::build();
    HelicopterBuilder &hel = HelicopterBuilder::build();
    QuadcopterBuilder &quad = QuadcopterBuilder::build();
    Director &dir = Director::direct();
    LoadSave &ls = LoadSave::loadsave();
    std::shared_ptr<Aircraft> pl;
    Aircraft p;
    aircraft_type p_type;

    int qnt = 0;
    load(aircraft, sel);
    std::cout << "Enter quantity of aircrafts: "; std::cin >> qnt;
    switch (sel){
        case 'p':
            for (int i = 0; i < qnt; ++i){
                std::cout << 'N' << i + 1 << std::endl;
                pl = dir.construct(pas);
                p = *pl;
                aircraft.emplace(p);
            }
            ls.save(aircraft, p_type);
            break;

        case 'c':
            for (int i = 0; i < qnt; ++i){
                std::cout << 'N' << i + 1 << std::endl;
                pl = dir.construct(comb);
                p = *pl;
                aircraft.emplace(p);
            }
            ls.save(aircraft, p_type);
            break;
        case 'h':
            for (int i = 0; i < qnt; ++i){
                std::cout << 'N' << i + 1 << std::endl;
                pl = dir.construct(hel);
                p = *pl;
                aircraft.emplace(p);
            }
            ls.save(aircraft, p_type);
            break;
        case 'q':
            for (int i = 0; i < qnt; ++i){
                std::cout << 'N' << i + 1 << std::endl;
                pl = dir.construct(quad);
                p = *pl;
                aircraft.emplace(p);
            }
            ls.save(aircraft, p_type);
            break;
        default:
            std::cerr << "Error! Invalid type!\n";
            break;
    }
    std::cout << "Save is successful!\n";
    aircraft.clear();
}

void search_by_name(std::set<Aircraft, std::less<>> &aircraft, char &sel){
    std::set<Aircraft, std::less<>>::const_iterator iter;

    load(aircraft, sel);
    std::string search_name;
    std::cout << "Enter search name: "; std::cin >> search_name;
    Aircraft search(search_name);
    iter = aircraft.lower_bound(search);
    while (iter != aircraft.upper_bound(search))
        std::cout << *iter++ << std::endl;
    aircraft.clear();
}

void show(std::set<Aircraft, std::less<>> &aircraft, char &sel){
    load(aircraft, sel);
    for(auto &it : aircraft)
        std::cout << it;
    aircraft.clear();
}

void aircraft_conveyor(){
    char sel = 0;
    std::set<Aircraft, std::less<>> aircraft;

    std::cout << "----------Aircraft conveyor----------\n";

    while(sel != 'e'){
        std::cout << "\nChoose: c - create one or few aircraft;\n"
                  << "        s - show all aircrafts by type;\n"
                  << "        p - print by name;\n"
                  << "        e - exit;\n";
        std::cout << "Your choice: ";   std::cin >> sel;

        switch(sel){
            case 'c':
                save(aircraft, sel);
                break;
            case 's':
                show(aircraft, sel);
                break;
            case 'p':
                search_by_name(aircraft, sel);
                break;
            case 'e':
                std::cout << "Exit\n";
                break;
            default:
                std::cerr << "Error! Please, enter correct command!\n";
                break;
        }
    }
}