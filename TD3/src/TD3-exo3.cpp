#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ScopedTimer.hpp>
#include <sorts.hpp>
#include <utils.hpp>

int main()
{
    std::vector<int> array = generate_random_vector(1000);
    std::vector<int> array_copy1 = array;
    std::vector<int> array_copy2 = array;

    {
        ScopedTimer timer("Bubble sort timer");
        bubble_sort(array);
    }

    {
        ScopedTimer timer("Merge sort timer : ");
        merge_sort(array);
    }

    {
        ScopedTimer timer("Std::sort timer : ");
        std::sort(array.begin(), array.end());
    }
}
