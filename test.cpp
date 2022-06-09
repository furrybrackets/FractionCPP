#include "rational.hpp"
#include <iostream>


int main() {
    Rational a("2/4");
    Rational b("2/3");

    a.red();

    std::cout << a.toString();
    return 0;
}