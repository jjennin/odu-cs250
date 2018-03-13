#include "fractiontype.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const fractionType& rightFr){
    out << rightFr.numerator;
    out << '/';
    out << rightFr.denominator;
    return out;
}

std::istream& operator>>(std::istream& in, fractionType& rightFr){
    char garbage = ' ';
    in >> rightFr.numerator;
    in >> garbage;
    in >> rightFr.denominator;
    return in;
}

bool fractionType::operator==(fractionType rightFr){
    return (this->numerator*rightFr.denominator == this->denominator*rightFr.numerator);
}
bool fractionType::operator!=(fractionType rightFr){
    return (this->numerator*rightFr.denominator != this->denominator*rightFr.numerator);
}
bool fractionType::operator<=(fractionType rightFr){
    return (this->numerator*rightFr.denominator <= this->denominator*rightFr.numerator);
}
bool fractionType::operator>=(fractionType rightFr){
    return (this->numerator*rightFr.denominator >= this->denominator*rightFr.numerator);
}
bool fractionType::operator<(fractionType rightFr){
    return (this->numerator*rightFr.denominator < this->denominator*rightFr.numerator);
}
bool fractionType::operator>(fractionType rightFr){
    return (this->numerator*rightFr.denominator > this->denominator*rightFr.numerator);
}


fractionType fractionType::operator+(fractionType rightFr){
    fractionType temp;
    temp.numerator = (this->numerator * rightFr.denominator) + (rightFr.numerator * this->denominator);
    temp.denominator = this->denominator * rightFr.denominator;
    return temp;
}
fractionType fractionType::operator-(fractionType rightFr){
    fractionType temp;
    temp.numerator = (this->numerator * rightFr.denominator) - (rightFr.numerator * this->denominator);
    temp.denominator = this->denominator * rightFr.denominator;
    return temp;
}
fractionType fractionType::operator/(fractionType rightFr){
    fractionType temp;
    if(rightFr.numerator == 0){
        std::cout << "Denominator can't be 0" << std::endl;
        return temp;
    }
    temp.numerator = this->numerator * rightFr.denominator;
    temp.denominator = this->denominator * rightFr.numerator;
    return temp;
}
fractionType fractionType::operator*(fractionType rightFr){
    fractionType temp;
    temp.numerator = this->numerator * rightFr.numerator;
    temp.denominator = this->denominator * rightFr.denominator;
    return temp;
}
