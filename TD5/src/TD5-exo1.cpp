#include <iostream>

size_t folding_string_hash(std::string const& s, size_t max) {

    size_t hash(0);
    for(size_t i {0}; i < s.size(); i++) {
        //hash += s[i];

        hash = (hash + s[i]) % max;
    }

    //for(char const& c : s) {
    //hash += c;
    //}

    //hash %= max;
    return hash;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max) {

    size_t hash(0);
    for(size_t i {0}; i < s.size(); i++) {

        hash = (hash + s[i] * (i + 1)) % max;
    }

    return hash;
}

int main() {
    std::string str (" ");
    std::cout << "Entre une string : ";
    std::cin >> str;
    //int test_c{0};
    std::cout <<folding_string_hash(str, 120) << std::endl;
    std::cout <<folding_string_ordered_hash(str, 120);

    //char test_c;

    //return 0;
}