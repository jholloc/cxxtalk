//
// Created by Jonathan Hollocombe on 07/06/2016.
//

#include <string>
#include <iostream>

std::string f(int& x) { return "l-value"; }
std::string f(int&& x) { return "r-value"; }

int g() { return 1; }

int main()
{
    int x = 1;

    std::cout << f(x) << std::endl;
    std::cout << f(g()) << std::endl;
    std::cout << f(std::move(x)) << std::endl;

    return 0;
}