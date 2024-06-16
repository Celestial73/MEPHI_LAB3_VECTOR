#pragma once

#include <iostream>

namespace dt
{
    class Complex
    {
    private:
        double real;
        double img;

    public:
        Complex();
        Complex(double real, double img);

        Complex operator+(const Complex &other) const;
        Complex operator*(const Complex &other) const;
        Complex operator*(const double &scalar) const;
        bool operator==(const Complex &other) const;
        bool isEqual(const Complex &other) const;

        // Finds the positive square root of a complex number
        static Complex sqrt(const Complex &value);
        static double abs(const Complex &value);
        static Complex getZero();
        static Complex getOne();

        const double &getReal() const;
        const double &getImg() const;
        void setReal(const double &value);
        void setImg(const double &value);
    };
}
