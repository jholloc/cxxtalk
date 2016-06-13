//
// Created by Jonathan Hollocombe on 13/06/2016.
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

#include <vector>
#include <iostream>

struct BigData {
    BigData() : vec(1000000) {}
    BigData(const BigData& other) {
        std::cout << "i've been copied\n";
        vec = other.vec;
    }
    BigData(BigData&& other) {
        std::cout << "i've been moved\n";
        vec = std::move(other.vec);
    }

private:
    std::vector<int> vec;
};

BigData&& g(BigData&& vec)
{
    return std::move(vec);
}

BigData f()
{
    BigData data;
    return g(std::move(data));
}

int main()
{
    auto data = f();
    return 0;
}