#include "Complex.h"
#include <math.h>

dt::Complex::Complex() : real(), img(0){};
dt::Complex::Complex(double real, double img) : real(real), img(img){};

const double &dt::Complex::getReal() const
{
    return this->real;
};

const double &dt::Complex::getImg() const
{
    return this->img;
};

void dt::Complex::setReal(const double &value)
{
    this->real = value;
};
void dt::Complex::setImg(const double &value)
{
    this->img = value;
};
dt::Complex dt::Complex::getZero()
{
    return Complex(0, 0);
};
dt::Complex dt::Complex::getOne()
{
    return Complex(1, 0);
};

dt::Complex dt::Complex::operator+(const dt::Complex &other) const
{
    return dt::Complex(this->real + other.real, this->img + other.img);
}

dt::Complex dt::Complex::operator*(const dt::Complex &other) const
{
    return dt::Complex((this->real * other.real - this->img * other.img), this->real * other.img + this->img * other.real);
}

dt::Complex dt::Complex::operator*(const double &realScalar) const
{
    return dt::Complex(this->real * realScalar, this->img * realScalar);
}

bool dt::Complex::operator==(const dt::Complex &other) const
{
    return this->isEqual(other);
}

bool dt::Complex::isEqual(const dt::Complex &other) const
{
    if (this->img != other.img || this->real != other.real)
    {
        return false;
    }
    return true;
}

dt::Complex dt::Complex::sqrt(const dt::Complex &value)
{
    dt::Complex res;
    res.setReal(std::sqrt((dt::Complex::abs(value) + value.real) / 2));
    res.setImg(std::sqrt((dt::Complex::abs(value) - value.real) / 2));
    return res;
}

double dt::Complex::abs(const dt::Complex &value)
{
    double res;
    res = std::sqrt(value.getImg() * value.getImg() + value.getReal() * value.getReal());
    return res;
}