#include "rational.hpp"

/*

class Rational {
    public:
        int num;
        int den;
        int whole;
        char sign;

        // reduces the fraction to lowest terms, which must be coprime
        void red();

        // returns the greatest common divisor of the numerator and denominator
        int gcd();

        // returns the lowest common multiple of the numerator and denominator
        int lcm();

        // returns the absolute value of the rational number
        Rational abs();

        // returns the reciprocal of the rational number
        Rational rec();

        Division: (a/b) / (c/d)  = (a*d)/(b*c)

        // Addition
        Rational operator+(const Rational &rhs);

        // Subtraction
        Rational operator-(const Rational &rhs);

        // Multiplication
        Rational operator*(const Rational &rhs);

        // Division
        Rational operator/(const Rational &rhs);

        // Exponentiation (integers)
        Rational operator^(const int &rhs);

        // Exponentiation (rationals)
        Rational operator^(const Rational &rhs);

        // Exponentiation (floats)
        Rational operator^(const float &rhs);

        // Exponentiation (doubles)
        Rational operator^(const double &rhs);

        // Greater than
        bool operator>(const Rational &rhs);

        // Less than
        bool operator<(const Rational &rhs);

        // Greater than or equal to
        bool operator>=(const Rational &rhs);

        // Less than or equal to
        bool operator<=(const Rational &rhs);

        // Equality for floating point numbers
        bool operator==(const float &rhs);

        // Eq. for integers
        bool operator==(const int &rhs);
};

*/

/*
        Arithmetic:

        Addition: (a/b) + (c/d) = k => k*bd = ad + bc => k = (ad + bc) / bd.

        (ad + bc) / bd.

        Subtraction: (a/b) - (c/d) = k => k*bd = ad - bc => k = (ad - bc) / bd.

        (ad - bc) / bd.

        Multiplication: (a/b) * (c/d) = (a*c)/(b*d).

        (a*c) / (b*d).
*/



bool Rational::operator<(const Rational &rhs) {
    // reduce rhs
    Rational t1 = rhs;
    t1.red();

    // create a copy of this
    Rational t2 = *this;
    t2.red();

    // a/b < c/d if ad < bc

    if (t1.den * t2.num < t1.num * t2.den) {
        return true;
    } else {
        return false;
    };
}


bool Rational::operator>(const Rational &rhs) {
    // reduce rhs
    Rational t1 = rhs;
    t1.red();

    // create a copy of this
    Rational t2 = *this;
    t2.red();

    // a/b < c/d if ad < bc

    if (t1.den * t2.num > t1.num * t2.den) {
        return true;
    } else {
        return false;
    };
}

bool Rational::operator>=(const Rational &rhs) {
    // reduce rhs
    Rational t1 = rhs;
    t1.red();

    // create a copy of this
    Rational t2 = *this;
    t2.red();

    // a/b < c/d if ad < bc

    if (t1.den * t2.num >= t1.num * t2.den) {
        return true;
    } else {
        return false;
    };
}

bool Rational::operator<=(const Rational &rhs) {
    // reduce rhs
    Rational t1 = rhs;
    t1.red();

    // create a copy of this
    Rational t2 = *this;
    t2.red();

    // a/b < c/d if ad < bc

    if (t1.den * t2.num <= t1.num * t2.den) {
        return true;
    } else {
        return false;
    };
}

short int signMul(short int a, short int b) {
    return a * b;
};

Rational Rational::operator*(const Rational &rhs) {
    // (a*c) / (b*d)
    Rational result("0/0");
    result.num = num * rhs.num;
    result.den = den * rhs.den;
    result.red();
    // sign
    result.sign = signMul(sign, rhs.sign);
    return result;
};

Rational Rational::operator+(const Rational &rhs) {
    // (ad + bc) / bd
    Rational result("0/0");
    result.num = num * rhs.den + den * rhs.num;
    result.den = den * rhs.den;
    result.red();
    return result;
};

Rational Rational::operator/(const Rational &rhs) {
    // (a*d) / (b*c)
    Rational result("0/0");
    result.num = num * rhs.den;
    result.den = den * rhs.num;
    result.red();
    // sign
    result.sign = signMul(sign, rhs.sign);
    return result;
};

Rational Rational::operator-(const Rational &rhs) {
    // (ad - bc) / bd
    Rational result("0/0");
    result.num = num * rhs.den - den * rhs.num;
    result.den = den * rhs.den;
    result.red();
    return result;
};

// implement reduce
void Rational::red() {
    int g = gcd();
    num /= g;
    den /= g;
};

// gcd
int Rational::gcd() {
    // Euclid's algorithm
    int a = num;
    int b = den;
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
};

std::string Rational::toString() {
    std::string result = "";
    if (sign == -1) {
        result += "-";
    }
    result += std::to_string(num);
    result += "/";
    result += std::to_string(den);
    return result;
};