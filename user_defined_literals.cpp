//
// Created by Jonathan Hollocombe on 07/06/2016.
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
