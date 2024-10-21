#include "complex_num.h"

complex_num::complex_num(double r, double i){
    real = r;
    imag = i;
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    z.real = real + w.real;
    z.imag = imag + w.imag;
    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    z.real = real - w.real;
    z.imag = imag - w.imag;
    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    z.real = real * w.real - imag * w.imag;
    z.imag = real * w.imag + imag * w.real;
    return z;
}

complex_num complex_num::operator /(complex_num w){
    complex_num z;
    double denom = w.real * w.real + w.imag * w.imag;
    z.real = (real * w.real + imag * w.imag) / denom;
    z.imag = (real * w.imag + imag * w.real) / denom;
    return z;
}

void complex_num::print(std::ostream &os){
    // Determine the sign of the i component before printing
    std::string op;
    if (imag < 0)
    {
        op = " - ";
        imag *= -1;
    } else {
        op = " + ";
    }    

    // Now print..
    if (imag != 0)
    {
        os << real << op << "i" << imag;
    } else {
        os << real;
    } 
}