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

#include <iostream>
#include <string>

struct Distance {
    constexpr Distance(double metres) : metres_(metres) { }
    constexpr Distance operator/ (const Distance& rhs) { return Distance{ metres_ / rhs.metres_ }; }
    std::string to_string() const { return std::to_string(metres_) + "m"; }
private:
    double metres_;
};

std::ostream& operator<<(std::ostream& out, const Distance& obj)
{
    out << obj.to_string();
    return out;
}

constexpr Distance operator"" _m(unsigned long long metres)
{
    return Distance{ static_cast<double>(metres) };
}

constexpr Distance operator"" _m(long double metres)
{
    return Distance{ static_cast<double>(metres) };
}

constexpr Distance operator"" _km(unsigned long long metres)
{
    return Distance{ 1E3 * static_cast<double>(metres) };
}

constexpr Distance operator"" _km(long double metres)
{
    return Distance{ 1E3 * static_cast<double>(metres) };
}

int main()
{
    auto x = 100_m;
    auto y = 10_km;

    std::cout << x / y << std::endl;

    return 0;
}
