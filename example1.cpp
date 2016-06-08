//
// Created by Jonathan Hollocombe on 08/06/2016.
//

#include <vector>
#include <stdlib.h>
#include <iostream>

struct Data {
    Data() : data_(new double[len_]), index_(rand() % 10000) {}
    ~Data() { delete[] data_; }
    int index() const { return index_; }

private:
    const static size_t len_;
    double* data_;
    int index_;
};

const size_t Data::len_ = 10;

struct DataComparator {
    bool operator() (const Data* lhs, const Data* rhs) {
        if (lhs == NULL || rhs == NULL) {
            throw new std::invalid_argument("attempting to compare NULL arguments");
        }
        return lhs->index() < rhs->index();
    }
};

int main()
{
    std::vector<Data*> vec;

    for (int i = 0; i < 10; ++i) {
        vec.push_back(new Data());
    }

    for (std::vector<Data*>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << (*it)->index() << "\n";
    }
    vec.push_back(NULL);

    DataComparator comparator;
    std::sort(vec.begin(), vec.end(), comparator);

    for (std::vector<Data*>::iterator it = vec.begin(); it != vec.end(); ++it) {
        delete *it;
    }

    return 0;
}