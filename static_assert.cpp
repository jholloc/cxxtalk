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

#include <type_traits>
#include <string>
#include <iostream>

template <typename T>
struct Coord {
    static_assert(std::is_arithmetic<T>::value, "template argument T must be arithmetic");
    Coord(T x, T y) : x_(x), y_(y) {}
    std::string to_string() const { return "[" + std::to_string(x_) + ", " + std::to_string(y_) + "]"; }

private:
    T x_, y_;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Coord<T>& coord)
{
    out << coord.to_string();
    return out;
}

int main()
{
    Coord<double> c{ 0.1, 2.0 };
    // Coord<std::string> d{ "a", "b" };

    std::cout << c << std::endl;

    return 0;
}
