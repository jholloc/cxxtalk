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

#include <memory>

struct Base {
    virtual ~Base() {}
    virtual void method() = 0;
    virtual int const_method(int x) const = 0;
};

struct Derived : public Base {
    void method() override {}
    int const_method(int x) const override { return x; }
};

int main()
{
    auto x = std::make_unique<Derived>();
    x->method();
    x->const_method(1);

    return 0;
}