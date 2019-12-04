#include <iostream>
#include "src/Date.h"
#include "src/Time.h"

using namespace std;

void TestDateUI()
{
    cout << "***Date UI***\n";

    int choice = 1;
    bool status = true;

    Date date;

    cout << "1 - Get a next day\n"
            "2 - Get a previous day\n"
            "3 - Get earlier date\n"
            "4 - Get name of the day\n"
            "5 - Add an amount of days to date\n"
            "6 - Subtract an amount of days from date\n"
            "7 - Get difference between two dates\n"
            "8 - Get difference between one date and 0-year\n"
            "9 - Add date to date\n"
            "10 - Subtract date from date\n"
            "0 - Close UI\n"
            "-1 - Show these commands again\n";


    while (status) {

        cout << "\nEnter what you want to do: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                date.NextDay();
                break;
            case 2:
                date.PreviousDay();
                break;
            case 3:
                date.SmallerDate();
                break;
            case 4:
                date.WeekDay();
                break;
            case 5:
                date.AddDays();
                break;
            case 6:
                date.SubtractDays();
                break;
            case 7:
                date.DifferenceTwoDates();
                break;
            case 8:
                date.DifferenceOneDate();
                break;
            case 9:
                date.AddDates();
                break;

            case 10:
                date.SubtractDates();
                break;
            case -1: {
                cout << "1 - Get a next day\n"
                        "2 - Get a previous day\n"
                        "3 - Get earlier date\n"
                        "4 - Get name of the day\n"
                        "5 - Add an amount of days to date\n"
                        "6 - Subtract an amount of days from date\n"
                        "7 - Get difference between two dates\n"
                        "8 - Get difference between one date and 0-year\n"
                        "9 - Add date to date\n"
                        "10 - Subtract date from date\n"
                        "0 - Close UI\n"
                        "-1 - Show these commands again\n";
                break;
            }
            case 0:
                status = false;
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
}

void TestTimeUI()
{

    cout << "***Time UI***\n";


    int choice = 1;
    bool status = true;

    Time time;

    cout << "1 - Get the amount of days in Time\n"
            "2 - Add two Times\n"
            "3 - Subtract Times\n"
            "4 - Multiply time\n"
            "5 - Divide Time \n"
            "6 - Add Time to Date\n"
            "7 - Subtract Time from Date\n"
            "0 - Close UI\n"
            "-1 - Show these commands again\n";


    while (status) {

        cout << "\nEnter what you want to do: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                time.GetDays();
                break;
            case 2:
                time.AddTimes();
                break;
            case 3:
                time.SubtractTimes();
                break;
            case 4:
                time.MultiplyTime();
                break;
            case 5:
                time.DivideTime();
                break;
            case 6:
                time.AddTimeToDate();
                break;
            case 7:
                time.SubtractTimeFromDate();
                break;
            case -1: {
                cout << "1 - Get the amount of days in Time\n"
                        "2 - Add two Times\n"
                        "3 - Subtract Times\n"
                        "4 - Multiply time\n"
                        "5 - Divide Time \n"
                        "6 - Add Time to Date\n"
                        "7 - Subtract Time from Date\n"
                        "0 - Close UI\n"
                        "-1 - Show these commands again\n";
                break;
            }
            case 0:
                status = false;
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
}


int main()
{
    TestDateUI();
    TestTimeUI();
}
