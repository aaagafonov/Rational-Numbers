#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class TRational {
    int a, b;
    void reduce();
    int gcd(int, int);
public:
    TRational();
    TRational(int, unsigned);
    TRational(const int&);

    TRational operator+ (TRational);
    TRational operator* (TRational);
    TRational operator/ (TRational);
    TRational operator- ();
    TRational operator- (TRational);
    bool operator== (TRational);
    bool operator!= (TRational);
    bool operator> (TRational);
    bool operator< (TRational);
    bool operator>= (TRational);
    bool operator<= (TRational);
    friend TRational sqrt(TRational);
    friend ostream& operator<<(ostream&, TRational);
    friend istream& operator>>(istream&, TRational&);
};

#endif // RATIONAL_H
