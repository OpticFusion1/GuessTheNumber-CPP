#include "Utils.h"

namespace Utils
{

    template <typename T>
    void print(T message)
    {
        std::cout << message << std::endl;
        std::cout.clear();
    }

    void print_vector(std::vector<int> array)
    {
        for (auto i : array)
        {
            std::cout << i << "\t";
        }
        print("\n");
    }

}