//
// Created by metalleg on 07.04.18.
//

#ifndef TECHPROGKURSACH_READWRITE_H
#define TECHPROGKURSACH_READWRITE_H

#include "Aircraft.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <algorithm>
#include <set>

class LoadSave {
    boost::property_tree::ptree aircraft_;
    LoadSave() = default;
    ~LoadSave() = default;
public:
    LoadSave(const LoadSave& ls) = delete;
    LoadSave(LoadSave&& ls) = delete;
    LoadSave&operator=(const LoadSave& ls) = delete;
    LoadSave&operator=(LoadSave&& ls) = delete;

    static LoadSave &loadsave();

    bool load(std::set<Aircraft, std::less<>> &aircraft, std::string &filename);
    void save(std::set<Aircraft, std::less<>> &aircraft, std::string &filename);
};

#endif //TECHPROGKURSACH_READWRITE_H
