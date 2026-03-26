#include <vector>
#include <algorithm>
#include <iostream>
#include <ScopedTimer.hpp>
#include <utils.hpp>
#include <sorts.hpp>

int main()
{
    std::vector<int> array = generate_random_vector(50);

    merge_sort(array);

    for(size_t i= 0; i < array.size(); i++){
        std::cout << array[i] << std::endl;
    }
}