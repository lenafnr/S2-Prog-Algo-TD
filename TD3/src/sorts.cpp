#include <sorts.hpp>

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

void merge_sort_merge(std::vector<int> &vec, size_t const left, size_t const middle, size_t const right) {

    size_t size1 = middle - left + 1;
    size_t size2 = right - middle;

    std::vector<int> left_vec(size1);
    std::vector<int> right_vec(size2);

    for (size_t i = 0; i < size1; i++)
        left_vec[i] = vec[left + i];
    for (size_t j = 0; j < size2; j++)
        right_vec[j] = vec[middle + 1 + j];

    size_t i = 0, j = 0, k = left;
    while (i < size1 && j < size2) {
        if (left_vec[i] <= right_vec[j]) {
            vec[k] = left_vec[i];
            i++;
        } else {
            vec[k] = right_vec[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        vec[k] = left_vec[i];
        i++;
        k++;
    }

    while (j < size2) {
        vec[k] = right_vec[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int> &vec, size_t const left, size_t const right)
{

    if (left != right)
    {
        size_t middle = (left + right) / 2;

        merge_sort(vec, left, middle);
        merge_sort(vec, middle+1, right);
        merge_sort_merge(vec, left, middle, right);
    }

};

void merge_sort(std::vector<int> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
}