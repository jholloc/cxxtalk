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

#include <vector>

struct MyList {
    MyList(std::vector<int> vec) : vec_{ vec } {}
    MyList(std::initializer_list<int> lst) : vec_{ lst } {}

private:
    std::vector<int> vec_;
};

int main()
{
    std::vector<int> vec = { 1, 2, 3, 4, 5 };

    MyList list_from_vector{ vec };
    MyList list_from_initlist{ 1, 2, 3, 4 };

    return 0;
}