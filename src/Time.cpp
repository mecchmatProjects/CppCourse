//
// Created by Mariia on 5/27/2019.
//

#include "../headers/Time.h"

void Time::correction() {
    // Adjust Time to normal format. Throws NegativeTimeException in case of negative Time.
    while (seconds<0){
        minutes--;
        seconds+=60;
    }
    while (minutes<0){
        hours--;
        minutes+=60;
    }
    while (hours<0){
        days--;
        hours+=24;
    }
    minutes += seconds/60;
    seconds %= 60;
    hours += minutes/60;
    minutes %=60;
    days += hours/24;
    hours %= 24;
    if (minutes<0 or seconds <0 or hours<0 or days<0){
        throw NegativeTimeException();
    }
}

Time::Time(const IType& days,const IType& hours,const IType& minutes,const IType& seconds) :
        days(days), hours(hours), minutes(minutes), seconds(seconds) {
    //Constructor with IType arguments. Could throw NegativeTimeException.
    correction();
}

StringType Time::show_time() const {
    // StringType representation of Time.

    ChType buf[256];
    int res = sprintf(buf,"%i.%i.%i.%i", get_days(), get_hours(), get_minutes(), get_seconds());
    StringType str = "ERROR!";
    if (res >= 0 && res < sizeof(buf))
        str = buf;
    return str;

}

IType Time::get_days() const {
    return days;
}

IType Time::get_hours() const {
    return hours;
}

IType Time::get_minutes() const {
    return minutes;
}

IType Time::get_seconds() const {
    return seconds;
}

IType Time::convert_to_sec() const {
    //Convert instance to seconds.
    return seconds+minutes*60+hours*3600+days*86400;
}

Time::Time() {
    //Trivial constructor.
    days = 0;
    hours = 0;
    minutes = 0;
    seconds = 0;
}

bool operator<(const Time &lhs, const Time &rhs) {
    if (lhs.days < rhs.days)
        return true;
    if (rhs.days < lhs.days)
        return false;
    if (lhs.hours < rhs.hours)
        return true;
    if (rhs.hours < lhs.hours)
        return false;
    if (lhs.minutes < rhs.minutes)
        return true;
    if (rhs.minutes < lhs.minutes)
        return false;
    return lhs.seconds < rhs.seconds;
}

bool operator>(const Time &lhs, const Time &rhs) {
    return rhs < lhs;
}

bool operator<=(const Time &lhs, const Time &rhs) {
    return !(rhs < lhs);
}

bool operator>=(const Time &lhs, const Time &rhs) {
    return !(lhs < rhs);
}

bool operator==(const Time &lhs, const Time &rhs) {
    return lhs.days == rhs.days &&
           lhs.hours == rhs.hours &&
           lhs.minutes == rhs.minutes &&
           lhs.seconds == rhs.seconds;
}

bool operator!=(const Time &lhs, const Time &rhs) {
    return !(rhs == lhs);
}

Time::Time(const Time &lhs) {
    //Copy constructor.
    days = lhs.days;
    hours = lhs.hours;
    minutes = lhs.minutes;
    seconds = lhs.seconds;
    correction();
}

Time operator+(const Time& lhs,const Time& rhs){
    return Time(lhs.get_days()+rhs.get_days(),
                lhs.get_hours()+rhs.get_hours(),
                lhs.get_minutes()+rhs.get_minutes(),
                lhs.get_seconds()+rhs.get_seconds());
}

Time operator-(const Time& lhs,const Time& rhs){
    return Time(lhs.get_days()-rhs.get_days(),
                lhs.get_hours()-rhs.get_hours(),
                lhs.get_minutes()-rhs.get_minutes(),
                lhs.get_seconds()-rhs.get_seconds());
}

Time operator*(const Time &lhs,const IType &rhs) {
    // Multiplication between Time and IType. Throws NegativeTimeException.
    return Time(0,0,0,lhs.convert_to_sec()*rhs);
}

Time operator*(const IType &rhs,const Time &lhs) {
    // Multiplication between Time and IType. Throws NegativeTimeException.
    return lhs*rhs;
}

Time operator/(const Time &lhs,const IType &rhs) {
    // Division between Time and IType. Throws NegativeTimeException and overflow_error in case of zero division.
    if (rhs!=0) {
        return Time(0, 0, 0, lhs.convert_to_sec() / rhs);
    } else {
        throw std::overflow_error("Zero division error.");
    }
}


IType toIType(const StringType &text) {
    //Cast StringType to IType. Raise WrongToI.
    int number;
    std::istringstream iss (text);

    if (!( iss >> number)){
        throw WrongToI();
    }
    return number;
}

std::istream &operator>>(std::istream &is, Time &d) {
    StringType op1;
    StringType op2;
    StringType op3;
    StringType op4;

    if (std::getline(is,  op1, '.') && std::getline(is,  op2, '.')
        && std::getline(is, op3, '.') &&std::getline(is, op4) ){

        try {
            d = Time(toIType(op1), toIType(op2), toIType(op3), toIType(op4));
        } catch (WrongToI& e){
            throw WrongTimeInput();
        }

    } else{
        throw WrongTimeInput();
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Time &d) {
    os<<d.show_time();
    return os;
}
