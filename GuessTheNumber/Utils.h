#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
using namespace std;

namespace Utils
{

    void print_vector(std::vector<int> array);

    template <typename T>
    void print(T message);

}