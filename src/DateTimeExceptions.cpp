//
// Created by Mariia on 5/27/2019.
//

#include "../headers/common.h"

/** Exception classes for Date and Time classes.
 *
 */

class DateTimeException: public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "DateTime Exception.\n";
    }
};

class WrongDateInput: public DateTimeException
{
public:
    virtual const char* what() const throw()
    {
        return "Wrong date input.\n";
    }
};

class WrongTimeInput: public DateTimeException
{
public:
    virtual const char* what() const throw()
    {
        return "Wrong time input.\n";
    }
};

class NegativeYearException: public DateTimeException
{
public:
    virtual const char* what() const throw()
    {
        return "Year can't be negative.\n";
    }
};

class WrongDaysCount: public DateTimeException{
public:
    virtual const char *what() const throw() {
        return "Wrong days count in current month.\n";
    }
};


class WrongMonthName: public DateTimeException
{
public:
    virtual const char* what() const throw()
    {
        return "Wrong month name.\n";
    }
};

class NegativeTimeException: public DateTimeException
{
public:
    virtual const char* what() const throw()
    {
        return "Negative time.\n";
    }
};

class WrongToI: public DateTimeException
{
public:
    virtual const char* what() const throw()
    {
        return "Bad string to int cast.\n";
    }
};
