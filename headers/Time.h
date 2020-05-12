#ifndef DATETIME_TIME_H
#define DATETIME_TIME_H


#include "../headers/common.h"
#include "../src/DateTimeExceptions.cpp"

class Time {
  public:
    Time();/*<Trivial constructor.>*/

    Time(const IType & days, const IType & hours, const IType & minutes, const IType & seconds);
    /*<Constructor with IType arguments.>*/

    Time(const Time& lhs);/*<Copy constructor.>*/

    StringType repr() const; /*<StringType representation of Time.>*/

    friend bool operator<(const Time &lhs, const Time &rhs); /*<Compare operators.>*/

    friend bool operator>(const Time &lhs, const Time &rhs);

    friend bool operator<=(const Time &lhs, const Time &rhs);

    friend bool operator>=(const Time &lhs, const Time &rhs);

    friend bool operator==(const Time &lhs, const Time &rhs); /*<Equality operators.>*/

    friend bool operator!=(const Time &lhs, const Time &rhs);

    IType getDays() const; /*<Getters>*/

    IType getHours() const;

    IType getMinutes() const;

    IType getSeconds() const;

    IType toSeconds() const; /*<Convert instance to seconds.>*/


  protected:
    IType hours;

    IType minutes;

    IType days;

    IType seconds;

    void correction(); /*<Adjust Time to normal format.>*/

};
Time operator+(const Time& lhs,const Time& rhs); /*<Operators between Time>*/

Time operator-(const Time& lhs,const Time& rhs);

Time operator*(const Time &lhs,const IType &rhs); /*<Multiplication between Time and IType>*/

Time operator/(const Time &lhs,const IType &rhs); /*<Division between Time and IType.>*/

Time operator*(const IType &rhs,const Time &lhs); /*<Multiplication between Time and IType>*/

IType toI(const StringType& text); /*<Cast StringType to IType.>*/

std::istream& operator>>(std::istream &is, Time &d); /*<Stream io operators>*/

std::ostream& operator<<(std::ostream& os, const Time& d);

#endif //DATETIME_TIME_H
