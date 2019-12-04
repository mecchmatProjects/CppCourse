#include <iostream>
#include <string>
#include "Date.h"

using namespace std;


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

    void InputTime(myTime &time)
    {

        cout << "Enter day: ";
        cin >> time.days;

        cout << "Enter hours: ";
        cin >> time.hours;

        cout << "Enter minutes: ";
        cin >> time.minutes;

        cout << "Enter seconds: ";
        cin >> time.seconds;

        if (!IsValidTime(time))
        {
            cout << "Incorrect input, try again..." << endl;
            InputTime(time);
        }


    }

    void TimeToScreen(myTime time)
    {
        cout << time.days << "d " << time.hours << "h " << time.minutes << "m " << time.seconds << "s" << endl;
    }

    void DateToScreen(Date::myDate &date)
    {
        cout << date.day << "." << date.month << "." << date.year << endl << endl;
    }

    void ConvertToTime();
    void GetSeconds();
    void GetBiggerTime();
    void AddTimes();
    void SubtractTimes();
    void MultiplyTime();
    void DivideTime();
    void GetDays();
    void AddTimeToDate();
    void SubtractTimeFromDate();

private:

    bool IsValidTime(const myTime &localTime)
    {
        if (localTime.days < 0) return false;
        if ( (localTime.hours < 0) || (localTime.hours > 24) ) return false;
        if ( (localTime.minutes < 0) || (localTime.minutes > 60) ) return false;
        if ( (localTime.seconds < .0) || (localTime.seconds > 60.) ) return false;

        return true;
    }

    int GetSecondsLogic(const myTime &localTime)
    {
        int secondsCount = (86400 * localTime.days) + (3600 * localTime.hours) + (60 * localTime.minutes) + localTime.seconds;
        return secondsCount;
    }

    myTime GetBiggerTimeLogic(const myTime &time1, const myTime &time2)
    {
        return (GetSecondsLogic(time1) > GetSecondsLogic(time2)) ? time1 : time2;
    }

    int GetDays(const myTime &localTime)
    {
        return localTime.days;
    }

    myTime GetConvertedSecondsToTime(int totalSeconds)
    {
        myTime resultTime{};

        int seconds = 0, minutes = 0, hours = 0, days = 0;

        days = totalSeconds / 86400;
        totalSeconds -= 86400 * days;

        hours = totalSeconds / 3600;
        totalSeconds -= 3600 * hours;

        minutes = totalSeconds / 60;
        totalSeconds -= 60 * minutes;

        seconds = totalSeconds;

        resultTime = {days, hours, minutes, seconds};

        return resultTime;
    }

    myTime GetAddedTimes(const myTime &time1, const myTime &time2)
    {
        int seconds = GetSecondsLogic(time1) + GetSecondsLogic(time2);
        return GetConvertedSecondsToTime(seconds);
    }

    myTime GetMultipliedTime(const myTime &localTime, int n)
    {
        int seconds = GetSecondsLogic(localTime) * n;
        return GetConvertedSecondsToTime(seconds);
    }

    myTime GetDividedTime(const myTime &localTime, int n)
    {
        int seconds = GetSecondsLogic(localTime) / n;
        return GetConvertedSecondsToTime(seconds);
    }

};


void Time::GetDays()
{
    cout << "\n***Days***\n";

    myTime time;

    cout << "Set a time\n";
    InputTime(time);

    cout << "\nDays count is: " << GetDays(time);

}

void Time::GetBiggerTime() {

    cout << "\n***Bigger time***\n";

    myTime time1;
    myTime time2;

    cout << "Set №1 time\n";
    InputTime(time1);
    cout << "Set №2 time\n";
    InputTime(time2);

    myTime biggerTime = GetBiggerTimeLogic(time1, time2);

    cout << "\nBigger time is: ";
    TimeToScreen(biggerTime);

}

void Time::DivideTime() {
    myTime time;

    cout << "Set a time\n";
    InputTime(time);

    int divider;
    cout << "Enter a divider: ";
    cin >> divider;

    myTime resultTime = GetDividedTime(time, divider);

    cout << "\nResult time is: ";
    TimeToScreen(resultTime);

}

void Time::MultiplyTime() {

    myTime time;

    cout << "Set a time\n";
    InputTime(time);

    int multiplier;
    cout << "Enter a multiplier: ";
    cin >> multiplier;

    myTime resultTime = GetMultipliedTime(time, multiplier);

    cout << "\nResult time is: ";
    TimeToScreen(resultTime);

}

void Time::AddTimes() {

    cout << "\n***Add times***\n";

    myTime time1;
    myTime time2;

    cout << "Set №1 time\n";
    InputTime(time1);
    cout << "Set №2 time\n";
    InputTime(time2);

    int resultTimeSeconds = GetSecondsLogic(time1) + GetSecondsLogic(time2);

    cout  << "\nResult time is: ";
    TimeToScreen(GetConvertedSecondsToTime(resultTimeSeconds));
}

void Time::SubtractTimes() {

    cout << "\n***Add times***\n";

    myTime time1;
    myTime time2;

    cout << "Set №1 time\n";
    InputTime(time1);
    cout << "Set №2 time\n";
    InputTime(time2);

    int smallSeconds = min(GetSecondsLogic(time1), GetSecondsLogic(time2));
    int bigSeconds = max(GetSecondsLogic(time1), GetSecondsLogic(time2));

    int resultTimeSeconds = bigSeconds - smallSeconds;

    cout  << "\nResult time is: ";
    TimeToScreen(GetConvertedSecondsToTime(resultTimeSeconds));
}

void Time::GetSeconds() {

    cout << "\n***Total seconds***\n";

    myTime time;

    cout << "Set a time\n";
    InputTime(time);

    cout << endl <<  GetSecondsLogic(time) << " seconds" << endl;
}

void Time::AddTimeToDate()
{

    cout << "\n***Add time to date***\n";

    Date::myDate date = {23, 4, 2000};

    myTime time;

    cout << "Set a time\n";
    InputTime(time);

    date.day += time.days;

    cout << "\nResult date is: ";
    DateToScreen(date);
}

void Time::SubtractTimeFromDate()
{
    cout << "\n***Subtract time from date***\n";

    Date::myDate date = {23, 4, 2000};

    myTime time;

    cout << "Set a time\n";
    InputTime(time);

    date.day -= time.days;

    cout << "\nResult date is: ";
    DateToScreen(date);
}

void Time::ConvertToTime()
{
    cout << "\n***Convert date to time***\n";


    Date::myDate date = {23, 4, 2000};

    myTime time = {0, 0, 0, 0};
    time.days = date.day;

    cout << "\nResult time is: ";
    TimeToScreen(time);
}