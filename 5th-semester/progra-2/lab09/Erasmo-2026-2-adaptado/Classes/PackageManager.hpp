//
// Created by zincronit on 11/16/26.
//

#ifndef ERASMO_2026_2_ADAPTADO_PACKAGEMANAGER_HPP
#define ERASMO_2026_2_ADAPTADO_PACKAGEMANAGER_HPP

#include "StandardPackage.hpp"
#include "RefrigeratedPackage.hpp"
class PackageManager
{
public:
    PackageManager() = default;
    ~PackageManager() = default;
    class Package* create_package(char );
    void load_packages(const std::string&, const std::string&);
    void process_dispatch(const std::string& );
private:
    std::list<Package*> package_queue;
    std::map<std::string, Package*> package_index;
};


#endif //ERASMO_2026_2_ADAPTADO_PACKAGEMANAGER_HPP
