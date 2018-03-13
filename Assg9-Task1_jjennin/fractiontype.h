#ifndef FRACTIONTYPE_H
#define FRACTIONTYPE_H
#include <iostream>

class fractionType{
    int numerator;
    int denominator;

    friend std::ostream& operator<<(std::ostream& out, const fractionType& rightFr);
    friend std::istream& operator>>(std::istream& in, fractionType& rightFr);

public:
    fractionType(){
        numerator=0; denominator=1;
    }
    fractionType(int num, int den){
        numerator=num; denominator=den;
    }
    bool operator==(fractionType rightFr);
    bool operator!=(fractionType rightFr);
    bool operator<=(fractionType rightFr);
    bool operator>=(fractionType rightFr);
    bool operator<(fractionType rightFr);
    bool operator>(fractionType rightFr);

    fractionType operator+(fractionType rightFr);
    fractionType operator-(fractionType rightFr);
    fractionType operator/(fractionType rightFr);
    fractionType operator*(fractionType rightFr);
};

#endif // FRACTIONTYPE_H
