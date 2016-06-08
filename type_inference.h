//
// Created by Jonathan Hollocombe on 06/06/2016.
//

#ifndef CXXTALK_TYPE_INFERENCE_H
#define CXXTALK_TYPE_INFERENCE_H

#include <iostream>
#include <vector>

struct TypeInference {
    auto auto_function() {
        return 1;
    }

    auto auto_function_with_return_type() -> double {
        return 1;
    }

    auto auto_variables() {
        auto vec = std::vector<double>{ 1, 2, 3, 4, 5 };
        auto square = [](const auto& x) { return x * x; };
        for (auto& x : vec) {
            x = square(x);
        }
        for (const auto& x : vec) {
            std::cout << x << "\n";
        }
        return vec;
    }

    auto derived_types(int x, double y) -> decltype(x + y) {
        return x + y;
    }
};

#endif //CXXTALK_TYPE_INFERENCE_H
