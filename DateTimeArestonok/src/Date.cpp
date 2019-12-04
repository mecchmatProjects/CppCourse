#include <iostream>
#include <string>

using namespace std;

class Date
{
public:

    struct myDate
    {
        int day;
        int month;
        int year;
    };

    void InputDate(myDate &date)
    {
        cout << "Enter day: ";
        cin >> date.day;

        cout <<"Enter month: ";
        cin >> date.month;

        cout << "Enter year: ";
        cin >> date.year;

        if (!IsValidDate(date))
        {
            cout << "\n***Incorrect input, try again***\n" << endl;
            InputDate(date);
        }
    }

    void DateToScreen(const myDate &date);
    void SmallerDate();
    void NextDay();
    void PreviousDay();
    void WeekDay();
    void AddDays();
    void SubtractDays();
    void AddDates();
    void SubtractDates();
    void DifferenceTwoDates();
    void DifferenceOneDate();

private:

    bool IsValidDate(const myDate &date)
    {

        if (date.year < 0) return false;
        if (date.month > 12 || date.month < 1) return false;
        if (date.day > 31 || date.day < 1) return false;
        if ((date.day == 31 &&
             ( date.month == 2 || date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) ))
            return false;
        if ( date.day == 30 && date.month == 2) return false;

        if (!(((date.year % 4 == 0) && (date.year % 100 != 0)) || (date.year % 400 == 0))){
            if (date.day == 29 && date.month == 2) return false;
        };

        return true;
    }

    bool IsDatesEqual(const myDate &date1, const myDate &date2)
    {
        return ((date1.day == date2.day) && (date1.month == date2.month) && (date1.year == date2.year));
    }

    myDate NextDayLogic(const myDate &date)
    {

        myDate nextDate = date;

        nextDate = { date.day + 1, date.month, date.year};
        if (IsValidDate(nextDate)) return nextDate;

        nextDate = {1, date.month + 1, date.year};
        if (IsValidDate(nextDate)) return nextDate;

        nextDate = {1, 1, date.year + 1};
        return nextDate;
    }

    myDate PreviousDayLogic (const myDate &date)
    {

        myDate prevDate = date;

        prevDate = {date.day - 1, date.month, date.year};
        if (IsValidDate(prevDate)) return prevDate;

        for (int day(31); day > 27; day--){
            prevDate = {day, date.month - 1, date.year};
            if (IsValidDate(prevDate)) return prevDate;
        }

        prevDate = {31,12,date.year - 1};
        return prevDate;

    }

    myDate GetBiggerDate(const myDate &date1, const myDate &date2)
    {

        if (IsDatesEqual(date1, date2))
            return date1;
        else
        {
            if (date1.year > date2.year)
                return date1;


            else if (date1.year == date2.year)
            {
                if (date1.month > date2.month)
                    return date1;


                else if (date1.month == date2.month)
                {
                    if(date1.day > date2.day)
                        return date1;

                }
            }

            return date2;
        }
    }

    myDate GetSmallerDate(const myDate &date1, const myDate &date2)
    {
        myDate smallerDate;
        myDate biggerDate;

        if(!IsDatesEqual(date1, date2))
            biggerDate = GetBiggerDate(date1, date2);
        else
            return date1;

        if(IsDatesEqual(biggerDate, date1))
            smallerDate = date2;
        else
            smallerDate = date1;

        return smallerDate;
    }

    int GetWeekDay(const myDate &date)
    {
        int curDay ;
        int month = date.month;
        int year = date.year;
        int day = date.day;


        month = (month + 9) % 12;
        year -= month / 10;
        curDay = 365 * year + year / 4 - year / 100 + year / 400 + (month * 306 + 5) / 10 + (day - 1);

        return curDay;
    }

    int DifferenceBetweenDates(myDate &date1, myDate &date2)
    {
        int days = 0;

        myDate biggerDate = GetBiggerDate(date1, date2);
        myDate smallerDate = GetSmallerDate(date1, date2);

        while (!IsDatesEqual(biggerDate, smallerDate))
        {
            biggerDate = PreviousDayLogic(biggerDate);
            days += 1;
        }

        return days;
    }

    int DifferenceBetweenDates(myDate &date1)
    {
        int days = 0;

        myDate biggerDate = date1;
        myDate smallerDate = {0, 0, 0};

        while (!IsDatesEqual(smallerDate, biggerDate) && IsValidDate(biggerDate))
        {
            biggerDate = PreviousDayLogic(biggerDate);
//            DateToScreen(biggerDate);
            days += 1;
        }

        return days;
    }

    myDate AddDaysLogic(const myDate &date, int n)
    {
        if (n < 0)
            n = -n;
        else if (n == 0)
            return date;

        myDate resultDate = NextDayLogic(date);

        int dayCount = 1;


        while (dayCount < n)
        {
            resultDate = NextDayLogic(resultDate);
            dayCount +=1;
        }

        return resultDate;
    };

    myDate SubtractDaysLogic(const myDate &date, int n)
    {
        if (n < 0)
            n = -n;
        else if (n == 0)
            return date;

        myDate resultDate = PreviousDayLogic(date);

        int dayCount = 1;


        while (dayCount < n)
        {
            resultDate = PreviousDayLogic(resultDate);
            dayCount +=1;
        }

        return resultDate;
    };

    myDate AddDatesLogic(myDate &date1, myDate &date2)
    {

        myDate smallerDate = GetSmallerDate(date1, date2);
        myDate biggerDate = GetBiggerDate(date1, date2);

        int days = DifferenceBetweenDates(smallerDate);

        myDate resultDate = AddDaysLogic(biggerDate, days);
        return resultDate;
    }

    myDate SubtarctDatesLogic(myDate &date1, myDate &date2)
    {

        myDate smallerDate = GetSmallerDate(date1, date2);
        myDate biggerDate = GetBiggerDate(date1, date2);

        int days = DifferenceBetweenDates(smallerDate);

        myDate resultDate = SubtractDaysLogic(biggerDate, days);
        return resultDate;
    }

};

void Date::DateToScreen(const Date::myDate &date)
{
    cout << date.day << "." << date.month << "." << date.year << endl << endl;
}

void Date::SmallerDate()
{

    cout << "\n***Earlier Date***\n";

    myDate date1;
    myDate date2;

    cout << "Set №1 date\n";
    InputDate(date1);
    cout << "\nSet №2 date\n";
    InputDate(date2);

    myDate earlierDate = GetSmallerDate(date1, date2);

    cout << "\nEarlier date is: ";
    DateToScreen(earlierDate);
}

void Date::DifferenceTwoDates()
{

    cout << "\n***Difference between two dates***\n";

    myDate date1;
    myDate date2;

    cout << "Set №1 date\n";
    InputDate(date1);
    cout << "Set №2 date\n";
    InputDate(date2);

    cout << "\nDifference is " << DifferenceBetweenDates(date1, date2) << " days" << endl;
}

void Date::DifferenceOneDate()
{

    cout << "\n***Difference with 0-year***\n";

    myDate date1;

    cout << "Set a date\n";
    InputDate(date1);

    cout << "\nDifference is " << DifferenceBetweenDates(date1) << " days" << endl;
}

void Date::AddDates()
{

    cout << "\n***Add two dates***\n";

    myDate date1;
    myDate date2;

    cout << "Set №1 date\n";
    InputDate(date1);
    cout << "Set №2 date\n";
    InputDate(date2);

    myDate AddedDate = AddDatesLogic(date1, date2);

    cout << "\nResult date is: ";
    DateToScreen(AddedDate);
}

void Date::SubtractDates()
{

    cout << "\n***Subtract dates***\n";

    myDate date1;
    myDate date2;

    cout << "Set №1 date\n";
    InputDate(date1);
    cout << "Set №2 date\n";
    InputDate(date2);

    myDate resultDate = SubtarctDatesLogic(date1, date2);

    cout << "\nResult date is: ";
    DateToScreen(resultDate);
}

void Date::AddDays()
{

    cout << "\n***Add days***\n";

    myDate date;

    cout << "Set a date\n";
    InputDate(date);

    int days = 0;
    cout << "Enter amount of days to add: ";
    cin >> days;
    myDate AddedDate = AddDaysLogic(date, days);

    cout << "\nResult date is: ";
    DateToScreen(AddedDate);
}

void Date::SubtractDays()
{

    cout << "\n***Subtract days***\n";

    myDate date;

    cout << "Set a date\n";
    InputDate(date);

    int days = 0;
    cout << "Enter amount of days to subtract: ";
    cin >> days;
    myDate AddedDate = SubtractDaysLogic(date, days);

    cout << "\nResult date is: ";
    DateToScreen(AddedDate);
}

void Date::WeekDay()
{

    cout << "\n***Week Day***\n";

    string days[7] =
            {
                    "Wednesday",
                    "Thursday",
                    "Friday",
                    "Saturday",
                    "Sunday",
                    "Monday",
                    "Tuesday"
            };

    myDate date;

    cout << "Set a date\n";
    InputDate(date);

    int curDay = GetWeekDay(date);
    cout << "\nDay is " << days[curDay % 7] << endl;
}

void Date::PreviousDay()
{

    cout << "\n***Previous Date***\n";


    myDate date;

    cout << "Set a date\n";
    InputDate(date);

    myDate previousDate = PreviousDayLogic (date);

    cout << "\nPrevious date is: ";
    DateToScreen(previousDate);
}

void Date::NextDay()
{

    cout << "\n***Next Date***\n";

    myDate date;

    cout << "Set a date\n";
    InputDate(date);

    myDate nextDate = NextDayLogic(date);

    cout << "\nNext date is: ";
    DateToScreen(nextDate);
}

