#pragma once

#include <string>

namespace tiny_math
{

    class ComplexNumber
    {
        float _re = 0.0f;
        float _im = 0.0f;

    public:
        ComplexNumber() = default;
        ComplexNumber(float re, float im) : _re(re), _im(im) {}
        float re() const { return _re; }
        float im() const { return _im; }
        float norm() const;
        ComplexNumber add(const ComplexNumber &other) const;
        ComplexNumber add(float number) const { return add(ComplexNumber(number, 0.)); }
        ComplexNumber multiply(const ComplexNumber &other) const;
        ComplexNumber multiply(float number) const { return multiply(ComplexNumber(number, 0.)); }
        bool equals(const ComplexNumber &other) const { return (_re == other._re) && (_im == other._im); }
        std::string to_string() const;

        ComplexNumber operator+(const ComplexNumber &other) const { return add(other); }
        ComplexNumber operator+(float number) const { return add(number); }
        ComplexNumber operator*(const ComplexNumber &other) const { return multiply(other); }
        ComplexNumber operator*(float number) const { return multiply(number); }
        bool operator==(const ComplexNumber &other) const { return equals(other); }
    };

    ComplexNumber exp(const ComplexNumber &z);
    ComplexNumber approximated_exp(const ComplexNumber &z, int iteration = 5);

}
