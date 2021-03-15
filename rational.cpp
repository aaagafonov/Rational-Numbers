#include "rational.h"
#include <math.h>

TRational::TRational() {
    a = 0;
    b = 1;
}

TRational::TRational(int a, unsigned b) {
    this->a = a;
    if (b != 0)
        this->b = b;
    else
    {
        this->b = 1;
        cout << "Error (b == 0). Set to b = 1.\n";
    }
    this->reduce();
}

TRational::TRational(const int& a) {
    this->a = a;
    b = 1;
}

void TRational::reduce() {
    int g = gcd(a, b);
    a /= g;
    b /= g;
}

int TRational::gcd(int x, int y) {
    x = abs(x), y = abs(y);
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

TRational TRational::operator+ (TRational c) {
    TRational t;
    t.a = a * c.b + b * c.a;
    t.b = b * c.b;
    t.reduce();
    return t;
}

TRational TRational::operator* (TRational c) {
    TRational t;
    t.a = a * c.a;
    t.b = b * c.b;
    t.reduce();
    return t;
}

TRational TRational::operator/ (TRational c) {
    TRational t;
    t.a = a * c.b;
    t.b = b * c.a;
    if (t.b < 0) {
        t.b = -t.b;
        t.a = -t.a;
    }
    t.reduce();
    return t;
}

TRational TRational::operator- () {
    TRational t;
    t.a = -a;
    t.b = b;
    return t;
}

TRational TRational::operator- (TRational c) {
    return *this + (-c);
}


bool TRational::operator== (TRational c) {
    return (a == c.a) && (b == c.b);
}

bool TRational::operator!= (TRational c) {
    return !(*this == c);
}

bool TRational::operator> (TRational c) {
    return (a * c.b) > (b * c.a);
}

bool TRational::operator< (TRational c) {
    return c > *this;
}

bool TRational::operator>= (TRational c) {
    return (*this > c || *this == c);
}

bool TRational::operator<= (TRational c) {
    return (*this < c || *this == c);
}

TRational sqrt(TRational c) {
    if ((sqrt(c.a) == int(sqrt(c.a))) && (sqrt(c.b) == int(sqrt(c.b))) && !(c < 0)) {
        TRational t;
        t.a = sqrt(c.a);
        t.b = sqrt(c.b);
        return t;
    }
    else {
        cout << "Square root is not rational.\n";
        return -1;
    }
}

ostream& operator<<(ostream& os, TRational c) {
    os << "(" << c.a << "/" << c.b << ")";
    return os;
}

istream& operator>>(istream& is, TRational& c) {
    is >> c.a;
    do {
        is >> c.b;
        if (c.b <= 0)
            cout << "Error (b <= 0). Enter b > 0.\n";
    } while (c.b <= 0);
    c.reduce();
    return is;
}

