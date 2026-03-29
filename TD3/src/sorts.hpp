#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

bool is_sorted(std::vector<int> const& vec);

void bubble_sort(std::vector<int> &vec);

void merge_sort_merge(std::vector<int> &vec, size_t const left, size_t const middle, size_t const right);

void merge_sort(std::vector<int> &vec, size_t const left, size_t const right);

void merge_sort(std::vector<int> &vec);

int search (const std::vector<int>& vec, int val);