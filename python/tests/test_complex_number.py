import math
from tiny_math import ComplexNumber, exponent

def test_add():
    z1 = ComplexNumber(1., 0.)
    z2 = ComplexNumber(0., 1.)
    z3 = z1 + z2
    assert z3 == ComplexNumber(z1.re + z2.re, z1.im + z2.im)    

def test_multiply():
    z1 = ComplexNumber(0., 1.)
    z2 = z1*z1
    assert z2 == ComplexNumber(-1., 0.)

def test_exponent():
    z1 = ComplexNumber(0., math.pi)
    z2 = exponent(z1) + 1.
    assert math.isclose(0., z2.norm, abs_tol=1e-6)
    