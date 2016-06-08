//
// Created by Jonathan Hollocombe on 08/06/2016.
//

#include <random>
#include <vector>
#include <iostream>

struct Data {
    int index() const { return index_; }

private:
    constexpr static size_t len_ = 10;
    const static std::default_random_engine generator;
    const static std::uniform_int_distribution<int> distribution;
    const static std::function<int()> random_index;

    std::unique_ptr<double[]> data_ = std::make_unique<double[]>(len_);
    int index_ = random_index();
};

const std::default_random_engine Data::generator{};
const std::uniform_int_distribution<int> Data::distribution = std::uniform_int_distribution<int>(1,6);
const std::function<int()> Data::random_index = std::bind(distribution, generator);

int main()
{
    std::vector<std::unique_ptr<Data>> vec;

    for (int i = 0; i < 10; ++i) {
        vec.emplace_back(std::make_unique<Data>());
    }

    std::for_each(vec.begin(), vec.end(), [](const auto& el) { std::cout << el->index() << "\n"; });
    vec.push_back(nullptr);

    std::sort(vec.begin(), vec.end(), [](auto& lhs, auto& rhs) {
        if (lhs == nullptr || rhs == nullptr) {
            throw new std::invalid_argument("attempting to compare NULL arguments");
        }
        return lhs->index() < rhs->index();
    });

    return 0;
}