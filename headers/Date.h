//
// Created by User on 25.05.2019.
//

#ifndef DATETIME_DATE_H
#define DATETIME_DATE_H

#include "../headers/common.h"
#include "../headers/Time.h"

extern IType DaysOfTheMonth[12]; /*<External array for accessing max days of month>*/
extern StringType MonthNames[]; /*<External array for accessing name of month>*/
extern StringType DayNames[]; /*<External array for accessing name of day>*/


struct Month{
    /** Helper structure to store month in Date class.
     *
     */
    IType index;
    IType days;
};

IType getMonthIndexByName(StringType name); /*<Returns month index by its name>*/

enum YearType{
    /** Helper enum for Date.
     *
     */
    Common = 365,
    Leap = 366,
};

class Date {
public:
    Date();/*<Trivial constructor.>*/

    Date(IType year, IType month, IType day); /*<Constructor with IType values>*/

    Date(IType day, const StringType &month, IType year);/*<Constructor with literal month>*/

    Date(const Date& oldDate);/*<Copy constructor>*/

    StringType repr() const; /*<StringType representation of class instance>*/

    IType getYear() const;

    IType getMonth() const;

    IType getDay() const;

    void nextDay(); /*<Modify instance to next calendar day.>*/

    void prevDay(); /*<Modify instance to previous calendar day.>*/

    void addDay(IType days); /*<Add IType amount of days to date.>*/

    void subDays(IType days); /*<Sub IType amount of days to date.>*/

    StringType weekDay() const; /*<Return week day of this date.>*/

    IType toDays() const; /*<Days between 0.1.1 and current date.>*/

    Time toTime() const; /*<Days between 0.1.1 and current date in Time format.>*/

    friend bool operator<(const Date &lhs, const Date &rhs);

    friend bool operator>(const Date &lhs, const Date &rhs);

    friend bool operator<=(const Date &lhs, const Date &rhs);

    friend bool operator>=(const Date &lhs, const Date &rhs);

    friend bool operator==(const Date &lhs, const Date &rhs);

    friend bool operator!=(const Date &lhs, const Date &rhs);

    friend IType daysBetween(const Date &lhs, const Date &rhs); /*<Days between two Dates.>*/



protected:

    IType year;

    YearType yearType;

    Month month;

    IType day;

    void initDate(IType year, IType month, IType day); /*<Helper function for constructor.>*/

    void monthIncrement(); /*<Next month of current date instance.>*/

    void monthDecrement(); /*<Previous month of current date instance.>*/

    void correction(); /*<Adjust instance to normal representation.>*/

    void adjustYearType(); /*<Adjust year type to year value.>*/
};

Date operator+(const Date &lhs, const Date &rhs);

Date operator-(const Date &lhs, const Date &rhs);

Date operator+(const Date &lhs, const Time &rhs);

Date operator-(const Date &lhs, const Time &rhs);

Date operator+(const Time &lhs, const Date &rhs);

Date operator-(const Time &lhs, const Date &rhs);

std::istream& operator>>(std::istream &is, Date &d);

std::ostream& operator<<(std::ostream &os, const Date &d);

#endif //DATETIME_DATE_H
