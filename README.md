# C++ Talk Examples

This project contains the C++ examples used in the C++ 11/14 talk given at CCFE on 14<sup>th</sup> June 2016.

All code samples are released under GPLv3 Licence (see LICENCE.txt).

## Dependencies

There are no library dependencies for this project but you will require a compiler with full C++14
support. The following compilers can be used:

* g++ version &ge; 5.0
* clang++ version &ge; 3.4

You will also need cmake version &ge; 2.8

## Build

To build run cmake and then the appropriate make system, i.e. make on Linux:

    cmake .
    make .

This will build all the example programs. If desired you can also build them manually using:

    g++ -std=c++14 <file>.cpp

Or

    clang++ -std=c++14 <file>.cpp