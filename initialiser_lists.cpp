//
// Created by Jonathan Hollocombe on 07/06/2016.
//

#include <vector>

struct MyList {
    MyList(std::vector<int> vec) : vec_{ vec } {}
    MyList(std::initializer_list<int> lst) : vec_{ lst } {}

private:
    std::vector<int> vec_;
};

int main()
{
    std::vector<int> vec = { 1, 2, 3, 4, 5 };

    MyList list_from_vector{ vec };
    MyList list_from_initlist{ 1, 2, 3, 4 };

    return 0;
}