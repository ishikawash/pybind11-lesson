#include <pybind11/pybind11.h>
#include "complex_number.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(_tiny_math, m, py::mod_gil_not_used(), py::multiple_interpreters::per_interpreter_gil()) {
    py::class_<ComplexNumber>(m, "ComplexNumber")
        .def(py::init<float, float>(), py::arg("re"), py::arg("im"))
        .def_property_readonly("re", &ComplexNumber::re)
        .def_property_readonly("im", &ComplexNumber::im)
        .def_property_readonly("norm", &ComplexNumber::norm)
        .def("__add__", py::overload_cast<const ComplexNumber&>(&ComplexNumber::add, py::const_), py::arg("other"))
        .def("__add__", py::overload_cast<float>(&ComplexNumber::add, py::const_), py::arg("number"))
        .def("__mul__", py::overload_cast<const ComplexNumber&>(&ComplexNumber::multiply, py::const_), py::arg("other"))
        .def("__mul__", py::overload_cast<float>(&ComplexNumber::multiply, py::const_), py::arg("number"))
        .def("__eq__", &ComplexNumber::equals, py::arg("other"))
        .def("__repr__", &ComplexNumber::to_string);

    m.def("exponent", &exponent, py::arg("z"));
    m.def("approximated_exponent", &approximated_exponent, py::arg("z"), py::arg("iteration") = 5);

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
