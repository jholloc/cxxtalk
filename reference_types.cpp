//
// Created by Jonathan Hollocombe on 07/06/2016.
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

#include <string>
#include <iostream>

std::string f(int& x) { return "l-value"; }
std::string f(int&& x) { return "r-value"; }

int g() { return 1; }

void h(int& x) {
    std::cout << f(x) << std::endl;                     // l-value
}

void i(int&& x) {
    std::cout << f(x) << std::endl;                     // l-value
    std::cout << f(std::forward<int>(x)) << std::endl;  // r-value
}

int main()
{
    int x = 1;

    std::cout << f(x) << std::endl;                     // l-value
    std::cout << f(g()) << std::endl;                   // r-value
    std::cout << f(std::move(x)) << std::endl;          // r-value

    h(x);
    i(std::move(x));

    return 0;
}

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}