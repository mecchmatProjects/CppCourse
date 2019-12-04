//
// Created by Mariia on 5/27/2019.
//

#ifndef DATATIME_PANKOVA_DATA_H
#define DATATIME_PANKOVA_DATA_H

#include "../headers/common.h"
#include "../headers/Time.h"

extern IType max_days_in_month[12]; //External array for accessing max days of month.
extern StringType month_names[]; //External array for accessing name of month.
extern StringType days_of_week[]; //External array for accessing name of day.


struct Month{
    IType index;
    IType days;
}; //structure to store month in Date class

IType getMonthIndexByName(StringType name); //Returns month index by its name.

enum YearType{
    Common = 365,
    Leap = 366,
};

class Date {
public:
    Date();//Trivial constructor.

    Date(IType year, IType month, IType day); //Constructor with IType values.

    Date(IType day, const StringType &month, IType year);//Constructor with string type month.

    Date(const Date& oldDate);//Copy constructor.

    StringType show_data() const; //StringType representation of class instance.

    IType get_year() const; //Getter for year.

    IType get_month() const; //Getter for month.

    IType get_day() const; //Getter for day.

    void next_day(); //Modify instance to next calendar day.

    void prev_day(); //Modify instance to previous calendar day.

    void add_days(IType days); //Add IType amount of days to date.

    void sub_days(IType days); //Sub IType amount of days from date.

    StringType day_of_the_week() const; //Return week day of this date.

    IType from_beginning() const; //Days between 0.1.1 and current date.

    Time from_beginning_time() const; //Days between 0.1.1 and current date in Time format.

    friend bool operator<(const Date &lhs, const Date &rhs);

    friend bool operator>(const Date &lhs, const Date &rhs);

    friend bool operator<=(const Date &lhs, const Date &rhs);

    friend bool operator>=(const Date &lhs, const Date &rhs);

    friend bool operator==(const Date &lhs, const Date &rhs);

    friend bool operator!=(const Date &lhs, const Date &rhs);

    friend IType days_between(const Date &lhs, const Date &rhs); //Days between two Dates.



protected:

    IType year;
    YearType yearType;
    Month month;
    IType day;

    void initDate(IType year, IType month, IType day); //Helper function for constructor.

    void next_month(); //Next month of current date instance.

    void prev_month(); //Previous month of current date instance.

    void correction(); //Adjust instance to normal representation.

    void adjust_year_type(); //Adjust year type to year value.
};

Date operator+(const Date &lhs, const Date &rhs);

Date operator-(const Date &lhs, const Date &rhs);

Date operator+(const Date &lhs, const Time &rhs);

Date operator-(const Date &lhs, const Time &rhs);

Date operator+(const Time &lhs, const Date &rhs);

Date operator-(const Time &lhs, const Date &rhs);

std::istream& operator>>(std::istream &is, Date &d);

std::ostream& operator<<(std::ostream &os, const Date &d);


#endif //DATATIME_PANKOVA_DATA_H
