#include <format>
#include "tiny_math.h"

ComplexNumber ComplexNumber::add(const ComplexNumber& other) const
{
    return ComplexNumber(
        _re + other._re,
        _im + other._im
    );
}

ComplexNumber ComplexNumber::multiply(const ComplexNumber& other) const
{
    return ComplexNumber(
        _re*other._re - _im*other._im,
        _re*other._im + _im*other._re
    );
}

std::string ComplexNumber::to_string() const
{
    return std::format("({}, {})", _re, _im);
}

ComplexNumber exponent(const ComplexNumber& z)
{
    float a = exp(z.re());
    ComplexNumber _z = ComplexNumber(cos(z.im()), sin(z.im()));
    return _z * a;
}
