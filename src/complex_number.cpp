#include <cmath>
#include <format>
#include "complex_number.h"

float ComplexNumber::norm() const
{
    float x = _re*_re + _im*_im;
    return (x > 0.) ? sqrt(x) : 0.;
}

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
    ComplexNumber _z = ComplexNumber(cos(z.im()), sin(z.im()));
    return _z * exp(z.re());
}
