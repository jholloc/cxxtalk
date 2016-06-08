//
// Created by Jonathan Hollocombe on 06/06/2016.
//

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = { 0, 1, 2, 3, 4, 5 };

    // C++03
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << "\n";
    }

    // C++11
    for (const auto& x : vec) {
        std::cout << x << "\n";
    }

    return 0;
}