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

#include <functional>
#include <numeric>
#include <vector>
#include <iostream>

struct MyData {
    double* begin() { return &data_[0]; }
    double* end() { return &data_[Length]; }

private:
    constexpr static size_t Length = 3;
    double data_[Length] = { 0.1, 0.2, 0.3 };
};

namespace std {
    template <> double* begin(MyData& data) { return data.begin(); }
    template <> double* end(MyData& data) { return data.end(); }
}

int main()
{
    auto sum = [](auto& v) { return std::accumulate(std::begin(v), std::end(v), 0.0, std::plus<double>()); };

    std::vector<double> vec = { 0.1, 0.2, 0.3 };
    double array[] = { 0.1, 0.2, 0.3 };
    MyData data;

    std::cout << sum(vec) << std::endl;
    std::cout << sum(array) << std::endl;
    std::cout << sum(data) << std::endl;

    return 0;
}