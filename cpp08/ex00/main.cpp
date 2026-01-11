#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);


    try {
        int* found = easyfind(vec, 3);
        std::cout << "Found: " << *found << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        int* found = easyfind(vec, 7);
        std::cout << "Found: " << *found << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
        try {
        int* found = easyfind(vec, 1);
        std::cout << "Found: " << *found << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        int* notFound = easyfind(vec, -10);
        std::cout << "Found: " << *notFound << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}