#ifndef TIME_H
#define TIME_H

#include "Date.h"

class Time
{
public:

    struct myTime
    {
        int days;
        int hours;
        int minutes;
        int seconds;
    };


    void InputTime(myTime &time);
    void GetSeconds();
    void TimeToScreen(myTime time);
    void GetBiggerTime();
    void AddTimes();
    void SubtractTimes();
    void MultiplyTime();
    void DivideTime();
    void GetDays();
    void AddTimeToDate();
    void ConvertToTime();
    void SubtractTimeFromDate();


private:

    bool IsValidTime(const myTime &localTime);
    int GetSecondsLogic(const myTime &localTime);
    myTime GetBiggerTimeLogic(const myTime &time1, const myTime &time2);
    int GetDays(const myTime &localTime);
    myTime GetConvertedSecondsToTime(int totalSeconds);
    myTime GetAddedTimes(const myTime &time1, const myTime &time2);
    myTime GetMultipliedTime(const myTime &localTime, int n);
    myTime GetDividedTime(const myTime &localTime, int n);

};

#endif