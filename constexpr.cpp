//
// Created by Jonathan Hollocombe on 06/06/2016.
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