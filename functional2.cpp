//
// Created by Jonathan Hollocombe on 08/06/2016.
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

#include <random>
#include <vector>
#include <iostream>

struct Data {
    int index() const { return index_; }

private:
    const static std::default_random_engine generator;
    const static std::uniform_int_distribution<int> distribution;
    const static std::function<int()> random_index;

    int index_ = random_index();
};

const std::default_random_engine Data::generator{};
const std::uniform_int_distribution<int> Data::distribution = std::uniform_int_distribution<int>(1,6);
const std::function<int()> Data::random_index = std::bind(distribution, generator);

int main()
{
    std::vector<std::shared_ptr<Data>> vec(10);

    std::for_each(vec.begin(), vec.end(), [](auto& el){
        el = std::make_shared<Data>();
    });

    std::sort(vec.begin(), vec.end(), [](auto& lhs, auto& rhs) {
        return lhs->index() < rhs->index();
    });

    auto is_even = [](const auto& el){ return el->index() % 2 == 0; };

    auto any_even = std::any_of(vec.begin(), vec.end(), is_even);

    decltype(vec) evens;
    if (any_even) {
        std::copy_if(vec.begin(), vec.end(), std::back_inserter(evens), is_even);
    }

    std::for_each(evens.begin(), evens.end(), [](const auto& el) {
        std::cout << el->index() << "\n";
    });

    return 0;
}