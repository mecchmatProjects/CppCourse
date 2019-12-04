#ifndef DATE_H
#define DATE_H

class Date
{
public:

    struct myDate
    {
        int day;
        int month;
        int year;
    };

    static void InputDate(myDate &date);
    static void DateToScreen(const myDate &date);
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

    bool IsValidDate(const myDate &date);
    static bool IsDatesEqual(const myDate &date1, const myDate &date2);
    myDate NextDayLogic(const myDate &date);
    myDate PreviousDayLogic (const myDate &date);
    myDate GetBiggerDate(const myDate &date1, const myDate &date2);
    static myDate GetSmallerDate(const myDate &date1, const myDate &date2);
    int GetWeekDay(const myDate &date);
    int DifferenceBetweenDates(myDate &date1, myDate &date2);
    myDate AddDaysLogic(const myDate &date, int n);
    myDate SubtractDaysLogic(const myDate &date, int n);
    myDate AddDatesLogic(myDate &date1, myDate &date2);
    myDate SubtarctDatesLogic(myDate &date1, myDate &date2);

};

#endif