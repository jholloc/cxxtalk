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

enum class Color : unsigned short {
    Red, Yellow, Green
};

std::string to_string(const Color& color)
{
    switch (color) {
        case Color::Red: return "Red";
        case Color::Yellow: return "Yellow";
        case Color::Green: return "Green";
    }
}

int main()
{
    Color color = Color::Red;

    std::cout << to_string(color) << std::endl;

    return 0;
}