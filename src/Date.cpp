//
// Created by Mariia on 5/27/2019.
//

#include "../headers/Date.h"
IType max_days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
StringType month_names[12] = {"January", "February", "March", "April", "May",
                             "June", "July", "August", "September", "October", "November", "December",};
StringType days_of_week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday",};

IType getMonthIndexByName(StringType name) {
    /** Returns month index by its name.
     *
     * trow WrongMonthName name if name undefined.
     */
    for (IType i=0;i<12;i++){
        if (month_names[i] ==name){
            return i+1;
        }
    }
    throw WrongMonthName();
}

StringType Date::show_data() const {  //string show_time for data.
    ChType buf[256];
    int res = sprintf(buf,"%i.%i.%i", get_year(), get_month(), get_day());
    StringType str = "ERROR!";
    if (res >= 0 && res < sizeof(buf))
        str = buf;
    return str;
}

Date::Date(IType year, IType month, IType day) {
    //constructor with IType values. Throws WrongDaysCount or NegativeYearException.
    initDate(year, month, day);
}

IType Date::get_year() const {
    return year;
}

IType Date::get_month() const {
    return month.index;
}

IType Date::get_day() const {
    return day;
}

Date::Date(IType day, const StringType &month, IType year){
    //constructor with str type month. Throws WrongDaysCount or NegativeYearException.
    initDate(year, getMonthIndexByName(month), day);
}

void Date::initDate(IType year, IType month, IType day) {
    //Helper function for constructor.
    if (year<0){
        throw NegativeYearException();
    }
    this->year = year;

    adjust_year_type();

    this->month.index = month;
    this->month.days = max_days_in_month[month-1];
    if (month==2 && this->yearType == Leap){
        this->month.days++;
    }

    if (day<1 or day>this->month.days){
        throw WrongDaysCount();
    }
    this->day = day;

}

void Date::next_day() {
    //Modify instance to next calendar day.
    day++;
    correction();
}

void Date::prev_day() {
    //Modify instance to previous calendar day. Could throw NegativeYearException.
    day--;
    correction();
}

void Date::add_days(IType days) {
    //Add IType amount of days to date. Could throw NegativeYearException.
    day+=days;
    correction();
}

void Date::sub_days(IType days) {
    //Sub IType amount of days from date. Could throw NegativeYearException.
    add_days(-days);
}

void Date::prev_month() {
    //Previous month of current date instance.
    month.index--;
    if (month.index == 0){
        year--;
        month.index = 12;
        adjust_year_type();
    }
    month.days = max_days_in_month[month.index-1];
    if (month.index==2 && this->yearType == Leap) {
        this->month.days++;
    }
}

void Date::correction() {
    //Adjust instance to normal representation. Could throw NegativeYearException.
    while (day>month.days){
        day-=month.days;
        next_month();
    }
    while (day<=0){
        prev_month();
        day+=month.days;
    }
    if (year<0){
        throw NegativeYearException();
    }
}

void Date::next_month() {
    //Next month of current date instance.
    month.index++;
    if (month.index==13){
        month.index = 0;
        year++;
        adjust_year_type();
    }
    month.days = max_days_in_month[month.index-1];
    if (month.index==2 && this->yearType == Leap){
        this->month.days++;
    }
}

void Date::adjust_year_type() {
    //Adjust year type to year value.
    if ((this->year % 4 == 0 && this->year % 100 !=0) || this->year%400 == 0){
        this->yearType = Leap;
    } else{
        this->yearType = Common;
    }
}

bool operator<(const Date &lhs, const Date &rhs) {
    if (lhs.year < rhs.year)
        return true;
    if (rhs.year < lhs.year)
        return false;
    if (lhs.month.index < rhs.month.index)
        return true;
    if (rhs.month.index < lhs.month.index)
        return false;
    return lhs.day < rhs.day;
}

bool operator>(const Date &lhs, const Date &rhs) {
    return rhs < lhs;
}

bool operator<=(const Date &lhs, const Date &rhs) {
    return !(rhs < lhs);
}

bool operator>=(const Date &lhs, const Date &rhs) {
    return !(lhs < rhs);
}

bool operator==(const Date &lhs, const Date &rhs) {
    return lhs.year == rhs.year &&
           lhs.month.index == rhs.month.index &&
           lhs.day == rhs.day;
}

bool operator!=(const Date &lhs, const Date &rhs) {
    return !(rhs == lhs);
}

IType days_between(const Date &lhs, const Date &rhs){
    //Days between two Dates. Returns negative value if lhs>rhs.
    return lhs.from_beginning()- rhs.from_beginning();
}

StringType Date::day_of_the_week() const {
    //Return week day of this date.
    int a = (14 - month.index) / 12;
    int y = year - a;
    int m = month.index + 12 * a - 2;
    return days_of_week[(day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7];
}

IType Date::from_beginning() const {
    //Days between 0.1.1 and current date.

    IType days = day;
    if (month.index>2){
        days++;
    }
    for (int i=0; i<month.index-1; i++){
        days+=max_days_in_month[i];
    }
    int leap = year/4+year/400-year/100;
    days += leap*Leap+(year-leap)*Common;
    return days;
}

Time Date::from_beginning_time() const {
    //Days between 0.1.1 and current date in Time format.
    return Time(from_beginning(), 0, 0, 0);
}

Date::Date(const Date &oldDate) {
    //Copy constructor.
    initDate(oldDate.get_year(), oldDate.get_month(), oldDate.get_day());
}

Date::Date() {
    //Trivial constructor.
    initDate(1,1,1);
}

Date operator+(const Date &lhs, const Date &rhs){
    Date newDate = lhs;
    newDate.add_days(rhs.from_beginning());
    return newDate;
}

Date operator-(const Date &lhs, const Date &rhs){
    Date newDate = lhs;
    newDate.add_days(-rhs.from_beginning());
    return newDate;
}

Date operator+(const Date &lhs, const Time &rhs) {
    Date newDate = lhs;
    newDate.add_days(rhs.get_days());
    return newDate;
}

Date operator-(const Date &lhs, const Time &rhs) {
    Date newDate = lhs;
    newDate.sub_days(rhs.get_days());
    return newDate;
}

Date operator+(const Time &lhs, const Date &rhs) {
    return rhs+lhs;
}

Date operator-(const Time &lhs, const Date &rhs) {
    return rhs-lhs;
}

std::istream &operator>>(std::istream &is, Date &d) {
    StringType op1;
    StringType op2;
    StringType op3;

    if (std::getline(is,  op1, '.') && std::getline(is,  op2, '.') && std::getline(is,  op3)){
        if (op2.length()>2){
            try {
                d = Date(toIType(op1),op2,toIType(op3));
            } catch (int x){
                throw WrongDateInput();
            }
        } else{
            try {
                d = Date(toIType(op1),toIType(op2),toIType(op3));
            } catch (int x){
                throw WrongDateInput();
            }
        }
    } else{
        throw WrongDateInput();
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Date &d) {
    os<< d.show_data();
    return os;
}
