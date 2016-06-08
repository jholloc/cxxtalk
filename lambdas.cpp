//
// Created by Jonathan Hollocombe on 06/06/2016.
//

#include <functional>

struct Lambdas {
    Lambdas() {
        plain_func_ = [](int x) { return 2.0 * x; };
        bound_func_ = [this](int x) { return plain_func_(x); };
    }

private:
    std::function<double(int)> plain_func_;
    std::function<double(int)> bound_func_;
};

int main()
{
    int x = 0;

    auto ref_capture = [&x](int y) { x = y; };
    auto val_capture = [x](int y) { return x * y; };
    auto ref_all = [&](int y) { x = 2; };
    auto val_all = [=](int y) { return x * y; };

    auto type_inferred = [](auto n) { return n + 1; };

    static_assert(std::is_same<decltype(type_inferred(1.0)), double>::value, "");
    static_assert(std::is_same<decltype(type_inferred(1)), int>::value, "");

    return 0;
}
