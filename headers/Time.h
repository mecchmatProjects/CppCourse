//
// Created by Mariia on 5/27/2019.
//

#ifndef DATATIME_PANKOVA_TIME_H
#define DATATIME_PANKOVA_TIME_H
#include "../headers/common.h"
#include "../src/DateTimeExceptions.cpp"

class Time {
public:
    Time();//Trivial constructor.

    Time(const IType & days, const IType & hours, const IType & minutes, const IType & seconds);//Constructor with IType arguments.

    Time(const Time& lhs);//Copy constructor.

    StringType show_time() const; //StringType representation of Time.

    friend bool operator<(const Time &lhs, const Time &rhs);

    friend bool operator>(const Time &lhs, const Time &rhs);

    friend bool operator<=(const Time &lhs, const Time &rhs);

    friend bool operator>=(const Time &lhs, const Time &rhs);

    friend bool operator==(const Time &lhs, const Time &rhs);

    friend bool operator!=(const Time &lhs, const Time &rhs);

    IType get_days() const; //Getter for days.

    IType get_hours() const; //Getter for hours.

    IType get_minutes() const;//Getter for minutes.

    IType get_seconds() const;//Getter for seconds.

    IType convert_to_sec() const; //Convert instance to seconds.


protected:
    IType days;
    IType hours;
    IType minutes;
    IType seconds;

    void correction(); //Adjust Time to normal format.

};


Time operator+(const Time& lhs,const Time& rhs);

Time operator-(const Time& lhs,const Time& rhs);

Time operator*(const Time &lhs,const IType &rhs);

Time operator*(const IType &rhs,const Time &lhs);

Time operator/(const Time &lhs,const IType &rhs);

IType toIType(const StringType &text); //Cast StringType to IType.

std::istream& operator>>(std::istream &is, Time &d); //Stream io operators.

std::ostream& operator<<(std::ostream& os, const Time& d);

#endif //DATATIME_PANKOVA_TIME_H
