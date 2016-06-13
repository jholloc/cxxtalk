//
// Created by Jonathan Hollocombe on 06/06/2016.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <iostream>
#include <vector>

auto auto_function() {
    return 1;
}

auto auto_function_with_return_type() -> double {
    return 1;
}

auto derived_types(int x, double y) -> decltype(x + y) {
    return x + y;
}

int main()
{
    auto vec = std::vector<double>{ 1, 2, 3, 4, 5 };    // variable declaration
    auto mult = [](double x, int p) { return x * p; };  // lambda type (C++11)
    auto square = [](const auto& x) { return x * x; };  // lambda type (C++14)

    for (auto& x : vec) {
        x = square(x);
    }

    for (const auto& x : vec) {
        std::cout << x << "\n";
    }

    std::cout << auto_function() << "\n";
    std::cout << auto_function_with_return_type() << "\n";
    std::cout << derived_types(1, 3.0) << "\n";

    return 0;
}