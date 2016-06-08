//
// Created by Jonathan Hollocombe on 08/06/2016.
//

#include <vector>
#include <random>
#include <iostream>

struct Data {
    int index() const { return index_; }

private:
    constexpr static size_t len_ = 10;
    const static std::default_random_engine generator;
    const static std::uniform_int_distribution<int> distribution;
    const static std::function<int()> random_index;

    std::unique_ptr<double[]> data_ = std::unique_ptr<double[]>(new double[len_]);
    int index_ = random_index();
};

const std::default_random_engine Data::generator{};
const std::uniform_int_distribution<int> Data::distribution = std::uniform_int_distribution<int>(1,6);
const std::function<int()> Data::random_index = std::bind(distribution, generator);

int main()
{
    std::vector<std::unique_ptr<Data>> vec;

    for (int i = 0; i < 10; ++i) {
        vec.emplace_back(std::unique_ptr<Data>(new Data{}));
    }

    for (const auto& el : vec) {
        std::cout << el->index() << "\n";
    }
    vec.push_back(nullptr);

    auto comparator = [](std::unique_ptr<Data>& lhs, std::unique_ptr<Data>& rhs) {
        if (lhs == nullptr || rhs == nullptr) {
            throw new std::invalid_argument("attempting to compare NULL arguments");
        }
        return lhs->index() < rhs->index();
    };
    std::sort(vec.begin(), vec.end(), comparator);

    return 0;
}