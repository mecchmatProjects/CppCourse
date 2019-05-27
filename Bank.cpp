#include<iostream>
#include<vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* File  Bank.cpp
Realization of Bank
Done by Zelenko Petro & Goryslavets Dmytro Statistics 2 curs
Email:  zelenko.peter369@gmail.com & d.goryslavets@ukr.net
Date 26.05.2019 */

using namespace std;

struct deposit
{
    float amount; // amount of deposit
    int deposit_rate;  // deposit percentage
    int term;             // term of deposit in years
    int type; //0 - deposit is returned right after customers request, 1 - deposit is returned after the expiration of the term specified by the agreement
};

struct obligation
{
    float price;   // price of obligation
    float award;   // payout on obligation per year
};

struct stock
{
    float price;   // price of stock
    float rate;    // percentage of the bank's profit for the year - payment on stock
};

struct bank_info      // bank state
{
    int amount_of_stocks;             // amount of sold bank's stocks
    int amount_of_obligations;        // amount of sold bank's obligations

    int amount_of_deposits;            // amount of the deposits in bank

    float avg_stock_price;             // average stock price
    float avg_obligation_price;        // average obligation price

    float money;                        // bank's money

    friend ostream & operator << (ostream& f, const bank_info &curbank)
    {
        f << curbank.amount_of_deposits << endl;
        f << curbank.amount_of_stocks << endl;                      //overloaded output operator
        f << curbank.amount_of_obligations << endl;
        f << curbank.avg_stock_price << endl;
        f << curbank.avg_obligation_price << endl;
        f << curbank.money << endl;

        return f;
    }

    bank_info operator - (const bank_info &b)
    {
        struct bank_info res;
        res.amount_of_deposits = amount_of_deposits - b.amount_of_deposits;
        res.amount_of_stocks = amount_of_stocks - b.amount_of_stocks;
        res.amount_of_obligations = amount_of_obligations - b.amount_of_obligations;   //overloading subtraction operator to get
        res.avg_stock_price = avg_stock_price - b.avg_stock_price;                     //changes in bank finances for a certain period
        res.avg_obligation_price = avg_obligation_price - b.avg_obligation_price;
        res.money = money - b.money;

        return res;
    }
};

class Bank
{
private:
    vector<struct deposit> deposits;        // deposits in bank
    vector<struct stock> stocks;            // sold bank's stocks
    vector<struct obligation> obligations;  // ..........obligations

    float money;                        //all bank's money
    int amount_of_stocks;             //amount of sold bank's stocks
    int amount_of_obligations;        //...................obligations

    float min_stock_price;              // minimal stock price
    float min_obligation_price;         //.......obligation....
public:
    Bank();              // class constructor by default

    void make_deposit(); // with a certain probability the bank can receive a deposit
    void pass_year(); // random changes in bank finances in a year
    void buy_and_sell_securities(); // buy or sell securities
    void add_stock(); // sell a stock to investor
    void add_obligation(); // sell an obligation to investor
    void erase_stock();    // buy back (with a certain probability) a stock from investor
    void erase_obligation(); // buy back (with a certain probability) an obligation from investor
    void update_securities_prices(); // update prices on securities
    vector<struct bank_info> get_report_per_n_years(int n); // get result of bank working n years, returns vector of bank states

};   // random strategy described below is unprofitable (tested)

void Bank::update_securities_prices()
{
    srand (unsigned(time(NULL)));         // initialisation of function srand by a function time (setting the seed of random value)

    int delta = rand() % 7 + (-2);    // delta - random integer in range [-2, 4], makes random fluctuation of securities prices

    min_stock_price += delta;
    min_obligation_price += delta;
}

void Bank::erase_stock()
{
    srand (unsigned(time(NULL)));

    int index_of_stock = rand() % stocks.size(); // random index from vector of stocks to erase it

    money -= stocks[index_of_stock].price;

    stocks.erase(stocks.begin() + index_of_stock);

    amount_of_stocks--;

}

void Bank::erase_obligation()
{
    srand (unsigned(time(NULL)));

    int index_of_obligation = rand() % obligations.size(); // random index from vector of obligations to erase it

    money -= obligations[index_of_obligation].price;

    obligations.erase(obligations.begin() + index_of_obligation);

    amount_of_obligations--;

}

void Bank::add_stock()
{
    srand (unsigned(time(NULL)));

    stock s;
    float price  = rand() % 11 + min_stock_price; // stock price is randomly selected from range of values [min_stock_price, min_stock_price + 10]
    float rate = rand() % 3 + 3; // stocks rate is randomly selected from 3 to 5
    s.price = price;
    s.rate = rate;
    stocks.push_back(s);

    money += price;

    amount_of_stocks++;

}

void Bank::add_obligation()
{
    srand (unsigned(time(NULL)));

    obligation s;
    float price;
    price = rand() % 11 + min_obligation_price; // obligation price is randomly selected from range of values [min_obligation_price, min_obligation_price + 10]


    float award = rand() % 6 + 5; // payout on obligation is randomly selected from 5 to 10
    s.price = price;
    s.award = award;
    obligations.push_back(s);

    money += price;

    amount_of_obligations++;

}

void Bank::buy_and_sell_securities()
{
    srand (unsigned(time(NULL)));

    int flag1;
    flag1 = rand() % 4; // with the probability of 25% bank buys back its stocks from investors and with the probability of 75% sells them to investor

    if(flag1 == 0)
    {
        erase_stock();
    }
    else
    {
        add_stock();
    }

    int flag2 = rand() % 4; // regardless of stock but similar to it obligation is bought back or sold

    if(flag2 == 0)
    {
        erase_obligation();
    }
    else
    {
        add_obligation();
    }

}

void Bank::make_deposit()
{
    srand (unsigned(time(NULL)));

    int flag;
    flag = rand() % 4; // bank can receive a deposit from customer with a probability of 25% (for example)

    if(flag == 0)
    {
        deposit dep;
        float amount = rand() % 4901 + 100; // deposit on random amount of money from 100 to 5000
        int deposit_rate = rand() % 11 + 5;  // with random rate from 5% to 15%
        int term = rand() % 19 + 2;         // on random term from 2 to 20
        int type = rand() % 2;              // equally probable one of two types of deposit, described in deposit structure

        dep.amount = amount;
        dep.deposit_rate = deposit_rate;
        dep.term = term;
        dep.type = type;

        deposits.push_back(dep);

        money += amount;

    }
    else
    {

    }

}

Bank::Bank()
{

    srand (unsigned(time(NULL)));
    make_deposit();

    min_stock_price = rand() % 11 + 40;       // minimal price of both types of securities is randomly selected from 40 to 50
    min_obligation_price = rand() % 11 + 40;

    money = rand() % 50001 + 100000;       // start bank's money value is randomly selected from 100 000 to 150 000

    amount_of_stocks = rand() % 21 + 50;    // start amount of stocks randomly selected from 50 to 70


    for(int i = 0; i < amount_of_stocks; ++i)
    {
        add_stock();
        amount_of_stocks--;
    }

    amount_of_obligations = rand() % 21 + 50;  // similar to stocks

    for(int i = 0; i < amount_of_obligations; ++i)
    {
        add_obligation();
        amount_of_obligations--;
    }

    buy_and_sell_securities();
    update_securities_prices();            // update prices
}

void Bank::pass_year()
{
    float curmoney = money;                                   // bank's money on the end of the previous year
    for(int i = 0; i < deposits.size(); ++i)
    {
        deposits[i].amount *= (1 + deposits[i].deposit_rate / 100); // compound interest
        deposits[i].term--;

        if(deposits[i].term == 0)       // if deposit term is over money are payed to customer
        {
            money -= deposits[i].amount;
            deposits.erase(deposits.begin() + i);
        }

        else if(deposits[i].term != 0 && deposits[i].type == 0) // if deposits type is 0
        {
            srand (unsigned(time(NULL)));
            int flag;
            flag = rand() % 5;          // customer can get back his deposit with a probability of 20% (1/5)

            if(flag == 0)
            {
                money -= deposits[i].amount;
                deposits.erase(deposits.begin() + i);
            }
        }
    }

    make_deposit();
    buy_and_sell_securities();

    for(int i = 0; i < obligations.size(); ++i)   //obligations settlement
    {
        money -= obligations[i].award;
    }

    float profit = money - curmoney;    // bank's year profit

    if(profit > 0)
    {
        for(int i = 0; i < stocks.size(); ++i) // because of stocks payment are calculated according to profit of the bank,
        {                                      // they are placed in the end of finance calculations
            money -= (profit * stocks[i].rate / 100);
        }
    }

    update_securities_prices();  // update securities prices

}

vector<struct bank_info> Bank::get_report_per_n_years(int n)
{

    vector<struct bank_info> res;

    struct bank_info curbank;                       // current bank state

    curbank.amount_of_deposits = deposits.size();
    curbank.amount_of_obligations = amount_of_obligations;  // bank state on beginning of its life
    curbank.amount_of_stocks = amount_of_stocks;

    float all_obligations = 0;

    for(int i = 0; i < obligations.size(); ++i)
        all_obligations += obligations[i].price;

    curbank.avg_obligation_price = all_obligations / obligations.size();

    float all_stocks = 0;

    for(int i = 0; i < stocks.size(); ++i)
        all_stocks += stocks[i].price;

    curbank.avg_stock_price = all_stocks / stocks.size();

    curbank.money = money;

    res.push_back(curbank);

    for(int i = 0; i < n; ++i)
    {
        time_t timer = time(NULL);          // because of initialisation of function rand() by the current time, to evade repeats of the random value
        time_t timer1 = time(NULL);          // making system to wait a bit

        while(difftime(timer1, timer) < 0.6)
        {
            timer1 = time(NULL);                        //Sleep(800) is working better, but its only for windows
        }

        pass_year();

        curbank.amount_of_deposits = deposits.size();
        curbank.amount_of_obligations = amount_of_obligations;
        curbank.amount_of_stocks = amount_of_stocks;

        float all_obligations = 0;

        for(int i = 0; i < obligations.size(); ++i)
            all_obligations += obligations[i].price;

        curbank.avg_obligation_price = all_obligations / obligations.size();

        float all_stocks = 0;

        for(int i = 0; i < stocks.size(); ++i)
            all_stocks += stocks[i].price;

        curbank.avg_stock_price = all_stocks / stocks.size();

        curbank.money = money;

        res.push_back(curbank);
    }

    return res;
}

void get_delta(vector<struct bank_info> &a, int k, int m)   // get result of bank working from k to m year of its life
{
    struct bank_info delta;

    delta = a[m] - a[k];


    if(delta.amount_of_deposits > 0)
        cout << "+" << delta.amount_of_deposits << " deposits" << endl;
    else
        cout << delta.amount_of_deposits << " deposits" << endl;

    if(delta.amount_of_stocks > 0)
        cout << "+" << delta.amount_of_stocks << " stocks" << endl;
    else
        cout << delta.amount_of_stocks << " stocks" << endl;

    if(delta.amount_of_obligations > 0)
        cout << "+" << delta.amount_of_obligations << " obligations" << endl;
    else
        cout << delta.amount_of_obligations << " obligations" << endl;

    if(delta.avg_stock_price > 0)
        cout << "+" << delta.avg_stock_price << " average stock price" << endl;
    else
        cout << delta.avg_stock_price << " average stock price" << endl;

    if(delta.avg_obligation_price > 0)
        cout << "+" << delta.avg_obligation_price << " average obligation price" << endl;
    else
        cout << delta.avg_obligation_price << " average obligation price" << endl;

    if(delta.money > 0)
        cout << "+" << delta.money << " bank's money" << endl;
    else
        cout << delta.money << " bank's money" << endl;

}
