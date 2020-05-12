//
// Created by User on 25.05.2019.
//

#include "../headers/Date.h"

IType DaysOfTheMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
StringType MonthNames[12] = {"January", "February", "March", "April", "May",
                           "June", "July", "August", "September", "October", "November", "December",};
StringType DayNames[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday",};


IType getMonthIndexByName(StringType name) {
    /** Returns month index by its name.
     *
     * trow WrongMonthName name if name undefined.
     */
    for (IType i=0;i<12;i++){
        if (MonthNames[i] ==name){
            return i+1;
        }
    }
    throw WrongMonthName();
}

StringType Date::repr() const {
    /** StringType representation of class member.
     *
     */
    ChType buf[256];
    int res = sprintf(buf,"%i.%i.%i", getYear(), getMonth(), getDay());
    StringType str = "ERROR!";
    if (res >= 0 && res < sizeof(buf))
        str = buf;
    return str;
}

Date::Date(IType year, IType month, IType day) {
    /** Constructor with IType values.
     *
     * Throws WrongDaysCount or NegativeYearException.
     *
     */
    initDate(year, month, day);
}

IType Date::getYear() const {
    return year;
}

IType Date::getMonth() const {
    return month.index;
}

IType Date::getDay() const {
    return day;
}

Date::Date(IType day, const StringType &month, IType year){
    /** Constructor with literal month.
     *
     * Throws WrongDaysCount or NegativeYearException.
     *
     */
    initDate(year, getMonthIndexByName(month), day);
}

void Date::initDate(IType year, IType month, IType day) {
    /** Helper function for constructor.
     *
     */

    if (year<0){
        throw NegativeYearException();
    }
    this->year = year;

    adjustYearType();

    this->month.index = month;
    this->month.days = DaysOfTheMonth[month-1];
    if (month==2 && this->yearType == Leap){
        this->month.days++;
    }

    if (day<1 or day>this->month.days){
        throw WrongDaysCount();
    }
    this->day = day;

}

void Date::nextDay() {
    /** Modify instance to next calendar day.
     *
     */
    day++;
    correction();

}

void Date::prevDay() {
    /** Modify instance to previous calendar day.
     *
     * Could throw NegativeYearException
     */
    day--;
    correction();
}

void Date::addDay(IType days) {
    /** Add IType amount of days to date.
     *
     * Could throw NegativeYearException
     *
     */
    day+=days;
    correction();
}

void Date::subDays(IType days) {
    /** Add IType amount of days to date.
     *
     * Could throw NegativeYearException
     *
     */
    addDay(-days);
}

void Date::monthDecrement() {
    /** Previous month of current date instance.
     *
     */
    month.index--;
    if (month.index == 0){
        year--;
        month.index = 12;
        adjustYearType();
    }
    month.days = DaysOfTheMonth[month.index-1];
    if (month.index==2 && this->yearType == Leap) {
        this->month.days++;
    }
}

void Date::correction() {
    /** Adjust instance to normal representation.
     *
     * Could throw NegativeYearException.
     *
     */
    while (day>month.days){
        day-=month.days;
        monthIncrement();
    }
    while (day<=0){
        monthDecrement();
        day+=month.days;
    }
    if (year<0){
        throw NegativeYearException();
    }
}

void Date::monthIncrement() {
    /** Next month of current date instance.
     *
     */
    month.index++;
    if (month.index==13){
        month.index = 0;
        year++;
        adjustYearType();
    }
    month.days = DaysOfTheMonth[month.index-1];
    if (month.index==2 && this->yearType == Leap){
        this->month.days++;
    }
}

void Date::adjustYearType() {
    /** Adjust year type to year value.
     *
     */
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

IType daysBetween(const Date &lhs, const Date &rhs){
    /** Days between two Dates.
     *
     * Returns negative value if lhs>rhs.
     *
     */
    return lhs.toDays()-rhs.toDays();
}

StringType Date::weekDay() const {
    /** Return week day of this date.
     *
     */
    int a = (14 - month.index) / 12;
    int y = year - a;
    int m = month.index + 12 * a - 2;
    return DayNames[(day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7];
}

IType Date::toDays() const {
    /** Days between 0.1.1 and current date.
     *
     */
    IType days = day;
    if (month.index>2){
        days++;
    }
    for (int i=0; i<month.index-1; i++){
       days+=DaysOfTheMonth[i];
    }
    int leap = year/4+year/400-year/100;
    days += leap*Leap+(year-leap)*Common;
    return days;
}

Time Date::toTime() const {
    /** Days between 0.1.1 and current date in Time format.
     *
     */
    return Time(toDays(), 0, 0, 0);
}

Date::Date(const Date &oldDate) {
    /** Copy constructor.
     *
     */
    initDate(oldDate.getYear(), oldDate.getMonth(), oldDate.getDay());
}

Date::Date() {
    /** Trivial constructor.
     *
     */
    initDate(1,1,1);
}

Date operator+(const Date &lhs, const Date &rhs){
    Date newDate = lhs;
    newDate.addDay(rhs.toDays());
    return newDate;
}

Date operator-(const Date &lhs, const Date &rhs){
    Date newDate = lhs;
    newDate.addDay(-rhs.toDays());
    return newDate;
}

Date operator+(const Date &lhs, const Time &rhs) {
    Date newDate = lhs;
    newDate.addDay(rhs.getDays());
    return newDate;
}

Date operator-(const Date &lhs, const Time &rhs) {
    Date newDate = lhs;
    newDate.subDays(rhs.getDays());
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
                d = Date(toI(op1),op2,toI(op3));
            } catch (int x){
                throw WrongDateInput();
            }
        } else{
            try {
                d = Date(toI(op1),toI(op2),toI(op3));
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
    os<<d.repr();
    return os;
}
