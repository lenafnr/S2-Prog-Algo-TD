#include <vector>
#include <algorithm>
#include <iostream>

void bubble_sort(std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        for (size_t j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main()
{
    std::vector<int> array{6, 2, 8, 1, 5, 3, 9};

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
