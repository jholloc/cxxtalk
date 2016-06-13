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

constexpr double gen_pi()
{
    const int N = 400;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            auto x = static_cast<double>(i) / N;
            auto y = static_cast<double>(j) / N;
            auto len = x*x + y*y;
            if (len < 1) ++count;
        }
    }
    return (count * 4.0) / (N * N);
}

constexpr auto PI = gen_pi();

int main()
{
    static_assert(static_cast<int>(PI * 10) / 10.0 == 3.1, "");

    std::cout << PI << std::endl;

    return 0;
}