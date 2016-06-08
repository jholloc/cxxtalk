//
// Created by Jonathan Hollocombe on 06/06/2016.
//

#include <iostream>

enum class Color : unsigned short {
    Red, Yellow, Green
};

std::string to_string(const Color& color)
{
    switch (color) {
        case Color::Red: return "Red";
        case Color::Yellow: return "Yellow";
        case Color::Green: return "Green";
    }
}

int main()
{
    Color color = Color::Red;

    std::cout << to_string(color) << std::endl;

    return 0;
}