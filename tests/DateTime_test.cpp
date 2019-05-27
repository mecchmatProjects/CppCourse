#include <iostream>
#include "../headers/Date.h"
#include "../headers/Time.h"
#include "../src/DualStream.cpp"

using namespace std;

void test(Date dateA, Date dateB, const Time& timeA, const Time& timeB, const StringType& filename);

void readFrom(const StringType& inFilename, const StringType& outFilename, bool fromFile);

void readFrom(const StringType& inFilename, const StringType& outFilename, bool fromFile){
    /**Reading test case from file or console.
     *
     * In first two lines should be two Date representations in format yyyy.mm.dd or dd.{month literal}.yyyy
     * In next two lines should be rwo Time representations in format d.h.m.s
     *
     * if fromFile == 0 reads from {inFilename}
     * else reads from console.
     */
    fstream inFile;
    if (fromFile){
        inFile.open(inFilename.c_str());
        if (!inFile) {
            cout << "Unable to open file: "<<inFilename;
            exit(1);
        }
    }
    Date dateA;
    Date dateB;
    Time timeA;
    Time timeB;
    try {
        if (fromFile){
            inFile >> dateA;
            inFile >> dateB;

            inFile >> timeA;
            inFile >> timeB;

        } else{
            cin >> dateA;
            cin >> dateB;

            cin >> timeA;
            cin >> timeB;
        }
    } catch (DateTimeException& e){
        cout<<e.what();
        system("pause");
        exit(1);
    }
    test(dateA,dateB,timeA,timeB,outFilename);
}

void test(Date dateA, Date dateB, const Time& timeA, const Time& timeB, const StringType& filename){
    /** Test cases.
     *
     * Write simultaneously into {filename} and console.
     */
    ofstream outFile;
    if (!outFile) {
        cout << "Unable to open file: "<<filename;
        exit(1);
    }
    outFile.open(filename.c_str());

    DualStream dualStream(cout, outFile);
    dualStream<<"-----------Date--------------\n";
    dualStream<<"DateA: "<<dateA<<" - "<<dateA.day_of_the_week()<<"\n";
    dateA.next_day();
    dualStream<<"Next day dateA: "<<dateA<<"\n";
    dateA.prev_day();
    dateA.prev_day();
    dualStream<<"Previous day dateA: "<<dateA<<"\n";
    dateA.next_day();
    dualStream<<"dateA to Time: "<<dateA.from_beginning_time()<<"\n";
    dateA.add_days(366);
    dualStream<<"DateA + 366 days: "<<dateA<<"\n";
    dualStream<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    dualStream<<"DateB: "<<dateB<<" - "<<dateB.day_of_the_week()<<"\n";
    dateB.next_day();
    dualStream<<"Next day dateB: "<<dateB<<"\n";
    dateB.prev_day();
    dateB.prev_day();
    dualStream<<"Previous day dateB: "<<dateB<<"\n";
    dateB.next_day();
    dualStream<<"dateB to Time: "<<dateB.from_beginning_time()<<"\n";
    dateB.add_days(366);
    dualStream<<"DateB + 366 days: "<<dateB<<"\n";
    dualStream<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    if (dateA>dateB){
        dualStream<<"DateA > DateB\n"<<"Days between: "<<days_between(dateA,dateB)<<"\n";
        dualStream<<"DateA - DateB = "<<dateA-dateB<<"\n";
    } else if (dateB>dateA) {
        dualStream<<"DateB > DateA\n"<<"Days between: "<<days_between(dateB,dateA)<<"\n";
        dualStream<<"DateA - DateB = "<<dateB-dateA<<"\n";
    } else {
        dualStream<<"DateB = DateA\n"<<"Days between: "<<days_between(dateB,dateA)<<"\n";
        dualStream<<"Couldn't sub equal date because -1.12.31 is incorrect.\n";
    }
    dualStream<<"DateA + DateB = "<<dateA+dateB<<"\n";
    dualStream<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

    dualStream<<"-----------Time--------------\n";
    dualStream<<"TimeA: "<<timeA<<"\n";
    try {
        dualStream << "TimeA + DateA = " << timeA + dateA << "\n";
        dualStream << "TimeA - DateB = " << timeA - dateB << "\n";
        dualStream<< "TimeA * 5 = "<<timeA * 5 <<"\n";
        dualStream<< "TimeA / 7 = "<<timeA / 7 <<"\n";
    } catch (DateTimeException& e){
        dualStream<<e.what();
        exit(1);
    }
    dualStream<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    dualStream<<"TimeB: "<<timeB<<"\n";
    try {
        dualStream << "TimeB + DateA = " << timeB + dateA << "\n";
        dualStream << "TimeB - DateB = " << timeB - dateB << "\n";
        dualStream<< "TimeB * 0 = "<<timeB * 0<<"\n";
        try {
            dualStream<< "TimeB / 0 = "<<timeA / 0<<"\n";
        } catch (overflow_error& e){
            dualStream<<e.what()<<"\n";
        }
    } catch (DateTimeException& e){
        dualStream<<e.what();
        exit(1);
    }
    dualStream<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    if (timeA>timeB){
        dualStream<<"timeA > timeB\n";
        dualStream<<"timeA - timeB = "<<timeA-timeB<<"\n";

    } else if (timeA<timeB){
        dualStream<<"timeB > timeA\n";
        dualStream<<"timeA - timeB = "<<timeB-timeA<<"\n";

    } else {
        dualStream<<"timeB = timeA\n";
    }
    dualStream<<"timeA + timeB = "<<timeA+timeB<<"\n";
}

int main() {
    IType i;
    cout<<"Read tests case from: 0-console, 1-file\n";
    cin>>i;
    while (i<0 || i>1){
        cout<<"Read tests case from: 0-console, 1-file\n";
        cin>>i;
    }
    if (!(bool)i){
        cout<<"*In first two lines should be two Date representations in format yyyy.mm.dd or dd.{month literal}.yyyy\n"
              "*In next two lines should be rwo Time representations in format d.h.m.s\n";
    }
    readFrom("../tests/DateTime_test_input.txt","../tests/DateTime_test_output.txt", (bool)i);
    return 0;
}