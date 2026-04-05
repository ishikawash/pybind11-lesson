#pragma once

#include <string>
#include <cmath>
#include <pybind11/pybind11.h>


#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

class ComplexNumber
{
    float _re = 0.0f;
    float _im = 0.0f;
public:
    ComplexNumber() = default;
    ComplexNumber(float re, float im) : _re(re), _im(im) {}
    float re() const { return _re; }
    float im() const { return _im; }
    ComplexNumber add(const ComplexNumber& other) const;
    ComplexNumber add(float number) const { return add(ComplexNumber(number, 0.)); }
    ComplexNumber multiply(const ComplexNumber& other) const;
    ComplexNumber multiply(float number) const { return multiply(ComplexNumber(number, 0.)); }
    bool equals(const ComplexNumber& other) const { return (_re == other._re) && (_im == other._im); }
    std::string to_string() const;

    ComplexNumber operator+(const ComplexNumber& other) const { return add(other); }
    ComplexNumber operator+(float number) const { return add(number); }
    ComplexNumber operator*(const ComplexNumber& other) const { return multiply(other); }
    ComplexNumber operator*(float number) const { return multiply(number); }
    bool operator==(const ComplexNumber& other) const { return equals(other); }
};

ComplexNumber exponent(const ComplexNumber& z);

namespace py = pybind11;

PYBIND11_MODULE(_tiny_math, m, py::mod_gil_not_used(), py::multiple_interpreters::per_interpreter_gil()) {
    py::class_<ComplexNumber>(m, "ComplexNumber")
        .def(py::init<float, float>(), py::arg("re"), py::arg("im"))
        .def_property_readonly("re", &ComplexNumber::re)
        .def_property_readonly("im", &ComplexNumber::im)
        .def("__add__", py::overload_cast<const ComplexNumber&>(&ComplexNumber::add, py::const_), py::arg("other"))
        .def("__add__", py::overload_cast<float>(&ComplexNumber::add, py::const_), py::arg("number"))
        .def("__mul__", py::overload_cast<const ComplexNumber&>(&ComplexNumber::multiply, py::const_), py::arg("other"))
        .def("__mul__", py::overload_cast<float>(&ComplexNumber::multiply, py::const_), py::arg("number"))
        .def("__eq__", &ComplexNumber::equals, py::arg("other"))
        .def("__repr__", &ComplexNumber::to_string);

    m.def("exponent", &exponent, py::arg("z"));

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
