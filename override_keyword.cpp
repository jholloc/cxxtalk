//
// Created by Jonathan Hollocombe on 06/06/2016.
//

#include <memory>

struct Base {
    virtual ~Base() {}
    virtual void method() = 0;
    virtual int const_method(int x) const = 0;
};

struct Derived : public Base {
    void method() override {}
    int const_method(int x) const override { return x; }
};

int main()
{
    auto x = std::make_unique<Derived>();
    x->method();
    x->const_method(1);

    return 0;
}