//
// Created by Jonathan Hollocombe on 07/06/2016.
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