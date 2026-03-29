#include <vector>
#include <algorithm>
#include <iostream>
#include <ScopedTimer.hpp>
#include <utils.hpp>
#include <sorts.hpp>

int main()
{

    std::vector<int> array = {1, 2, 2, 3, 4, 8, 12};
    int val {};
    std::cin >> val;

    if (!is_sorted(array))
    {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
    else
    {
        std::cout << search(array, val) << std::endl;
    }
}