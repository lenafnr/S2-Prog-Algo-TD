#include <vector>
#include <algorithm>
#include <iostream>
#include <ScopedTimer.hpp>
#include <utils.hpp>
#include <sorts.hpp>

int main()
{
    std::vector<int> array = generate_random_vector(50);

    std::cout << "Voici le tableau avant tri : ";
    for (int n : array)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    bubble_sort(array);

    std::cout << "Voici le tableau après tri : ";
    for (int n : array)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
