#include <cmath>
#include <functional>
#include <format>
#include "complex_number.h"

namespace
{
    float approximated_function(std::function<float(int)> df, float x, int n)
    {
        float fx = df(0);
        float xn = 1.;
        float kn = 1.;
        for (int k = 1; k < n; k++)
        {
            xn *= x;
            kn *= k;
            fx += df(k) * xn / kn;
        }
        return fx;
    }
}

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

ComplexNumber approximated_exponent(const ComplexNumber& z, int iteration)
{
    // Try to approximate exponential function using Maclaurin series.
    auto dcos = [](int n)
    {
        float y[] = { 1., 0., -1., 0. };
        return y[n % 4];
    };
    auto dsin = [](int n)
    {
        float y[] = { 0., 1., 0., -1 };
        return y[n % 4];
    };
    float cosine = approximated_function(dcos, z.im(), iteration);
    float sine = approximated_function(dsin, z.im(), iteration);
    ComplexNumber _z = ComplexNumber(cosine, sine);
    return _z * exp(z.re());
}
