#include "Bank.h"
#include<iostream>
#include<vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* File  Bank_test.cpp
Realization of Bank
Done by Goryslavets Dmytro & Zelenko Petro Statistics 2 curs
Email:  d.goryslavets@ukr.net & zelenko.peter369@gmail.com
Date 26.05.2019 */


/* testing unprofitability of bank working scheme */
int test1()
{
    vector<struct bank_info> a;

    Bank mybank;
    a = mybank.get_report_per_n_years(5);

    int res;

    if((a[4].money - a[0].money) <= 0)
        res = 1;
    else
        res = 0;

    return res;
}

int test2()
{
    vector<struct bank_info> a;

    Bank mybank;
    a = mybank.get_report_per_n_years(10);

    int res;

    if((a[9].money - a[0].money) <= 0)
        res = 1;
    else
        res = 0;

    return res;
}

int test3()
{
    vector<struct bank_info> a;

    Bank mybank;
    a = mybank.get_report_per_n_years(15);

    int res;

    if((a[14].money - a[0].money) <= 0)
        res = 1;
    else
        res = 0;

    return res;
}

int test4()
{
    vector<struct bank_info> a;

    Bank mybank;
    a = mybank.get_report_per_n_years(20);

    int res;

    if((a[19].money - a[0].money) <= 0)
        res = 1;
    else
        res = 0;

    return res;
}

int main()
{
    cout << "testing..." << endl;

    if(test1())
        cout << "test 1 passed" << endl;        // because of random test are working a long while
    if(test2())
        cout << "test 2 passed" << endl;
    if(test3())
        cout << "test 3 passed" << endl;
    if(test4())
        cout << "test 4 passed" << endl;

    int n;
    cout << "Input years of bank working (optimal values due to speed of program are in range 10-20): ";
    cin >> n;

    cout << "Wait please, imitating banks work..." << endl;

    vector<struct bank_info> a;

    Bank mybank;
    a = mybank.get_report_per_n_years(n);

    cout << "Bank have been working for " << n << " years. Input 2 numbers from 0 to " << n;
    cout << " included " << endl << "to get financial report of bank's work on this period" << endl;

    int k, m;
    cin >> k >> m;

    get_delta(a, k, m);

    return 0;
}

