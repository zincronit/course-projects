//
// Created by zincronit on 11/16/26.
//

#include "PackageManager.hpp"

class Package* PackageManager::create_package(char type)
{
    switch (type)
    {
        case 'S': return new StandardPackage();
        case 'R': return new RefrigeratedPackage();
        default: return nullptr;
    }
}

void PackageManager::load_packages(const std::string& filepath, const std::string& filename)
{
    std::ifstream input;
    Utils::open_input_file(input, filepath);
    char type;
    while (true)
    {
        input.get(type);
        if (input.eof()) break;
        input.ignore();
        Package* package = create_package(type);
        package->read(input);
        package_queue.push_back(package);
        package_index[package->get_code()] = package;
    }
    input.close();
    Utils::open_input_file(input, filename);
    std::string code;
    while (true)
    {
        std::getline(input, code, ',');
        if (input.eof()) break;
        class Product product;
        product.read(input);
        auto it = package_index.find(code);
        if (it != package_index.end())
            it->second->add_product(product);
    }
    input.close();
}

void PackageManager::process_dispatch(const std::string&)
{
    std::cout << "hello" << std::endl;
}
