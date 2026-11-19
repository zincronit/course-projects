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

PackageManager::~PackageManager()
{
    for (std::pair<const std::string, Package *>& pair: package_index)
        delete pair.second;
    package_index.clear();
    package_queue.clear();
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
        // package_index.insert({package->get_code(),package});
        // package_index.emplace(package->get_code(), package);
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
        std::map<std::string, Package *>::iterator it;
        it = package_index.find(code);
        if (it != package_index.end())
            it->second->add_product(product);
    }
    input.close();
}

void PackageManager::process_dispatch(const std::string& filepath , const std::string& filename)
{
    std::ofstream output, fout;
    Utils::open_output_file(output, filepath);
    Utils::open_output_file(fout, filename);
    output << std::fixed << std::setprecision(2) << std::setw(10) << "DISPATCHED PACKAGES\n";
    fout << std::fixed << std::setprecision(2) << std::setw(10) << "PENDING PACKAGES\n";
    while (not package_queue.empty())
    {
        class Package* package = package_queue.back();
        package_queue.pop_back();
        package->can_dispatch() ?  package->print_details(output) : package->print_details(fout);
    }
    std::cout << package_index.size() << " packages were loaded" << std::endl;
    std::cout << package_queue.size() << " packages were loaded" << std::endl;
    output.close();
    fout.close();
}
