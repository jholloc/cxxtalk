//
// Created by Jonathan Hollocombe on 07/06/2016.
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
