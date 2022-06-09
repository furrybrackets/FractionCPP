#ifndef RATIONAL_H
#define RATIONAL_H
#include <string>

class Rational {
    public:
        int num;
        int den;
        short int sign;

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

        /* 
        Arithmetic:

        Addition: (a/b) + (c/d) = k => k*bd = ad + bc => k = (ad + bc) / bd.

        (ad + bc) / bd.

        Subtraction: (a/b) - (c/d) = k => k*bd = ad - bc => k = (ad - bc) / bd.

        (ad - bc) / bd.

        Multiplication: (a/b) * (c/d) = (a*c)/(b*d).

        (a*c) / (b*d).

        Division: (a/b) / (c/d)  = (a*d)/(b*c)
        */

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

        std::string toString();

        Rational(std::string s) {
            // parse s into num and den

            // first split the string at the '/'
            std::string num_str = s.substr(0, s.find('/'));
            std::string den_str = s.substr(s.find('/') + 1);

            // find the sign
            if (s[0] == '-') {
                sign = -1;
            } else {
                sign = 1;
            };

            // convert the strings to ints
            num = std::stoi(num_str);
            den = std::stoi(den_str);
        };
};

short int signMul(short int a, short int b);
#endif