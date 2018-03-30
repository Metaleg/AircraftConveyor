#include "Interface.h"

int main(){

    try {
        char sel = 0;
        std::set<Aircraft, std::less<Aircraft>> aircraft;
        std::set<Aircraft, std::less<Aircraft>>::const_iterator iter;
        Aircraft p;

        while(sel != 'e'){
            std::cout << "Choose: c - create one or few aircraft;\n"
                      << "        s - show all plains by type;\n"
                      << "        p - print by name;\n"
                      << "        e - exit;\n";
            std::cout << "Your choice: ";   std::cin >> sel;

            switch(sel){
                case 'c':
                    create(aircraft);
                    iter = aircraft.begin();
                    while (iter != aircraft.end()){
                       p = *iter++;
                       p.write();
                    }
                    std::cout << "Write is done!\n";
                    aircraft.clear();
                    break;
                case 's': {
                    read_file(aircraft);
                    iter = aircraft.begin();
                    int count = 0;
                    while (iter != aircraft.end()){
                        std::cout << 'N' << ++count;
                        std::cout << (*iter++) << std::endl;
                    }
                    std::cout << "Show is done!\n";
                    aircraft.clear();
                    break;
                }
                case 'p':{
                    read_file(aircraft);
                    char name[SIZE];
                    std::cout << "Enter name of aircraft: "; std::cin >> name;
                    for(iter = aircraft.begin(); iter != aircraft.end(); iter++){
                        if(!strcmp((*iter).get_name(), name))
                            std::cout << *iter << std::endl;
                        else
                            std::cout << "Aircrafts with same name are missing\n";
                    }
                    aircraft.clear();
                    break;
                }
                case 'e':
                    std::cout << "Exit\n";
                    break;
                default:
                    std::cout << "Error! Please, enter correct command!\n";
                    break;
            }
        }

    }
    catch(Exception){
        std::cin.clear();
        std::cout << "Error input data!" << std::endl;
    }
    return 0;
}
