#include "Bank.cpp"
/* File  Bank.h
Realization of Bank
Done by Goryslavets Dmytro & Zelenko Petro Statistics 2 curs
Email: d.goryslavets@ukr.net & zelenko.peter369@gmail.com
Date 26.05.2019 */

/* Base structure of deposit */
/*struct deposit
{
    float amount; // amount of deposit
    int deposit_rate;  // deposit percentage
    int term;             // term of deposit in years
    int type; //0 - deposit is returned right after customers request, 1 - deposit is returned after the expiration of the term specified by the agreement
};*/

/* Base structure of obligation */
/*struct obligation
{
    float price;   // price of obligation
    float award;   // payout on obligation per year
};*/

/* Base structure of stock */
/*struct stock
{
    float price;   // price of stock
    float rate;    // percentage of the bank's profit for the year - payment on stock
};*/

/* Base structure of bank state */
/*struct bank_info      // bank state
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
};*/

/* realisation of bank work*/
/*class Bank
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

};   // random strategy described below is unprofitable (tested)*/

extern Bank::Bank();   // class constructor by default

extern void Bank::make_deposit(); // with a certain probability the bank can receive a deposit

extern void Bank::pass_year(); // random changes in bank finances in a year

extern void Bank::buy_and_sell_securities(); // buy or sell securities

extern void Bank::add_stock(); // sell a stock to investor

extern void Bank::add_obligation(); // sell an obligation to investor

extern void Bank::erase_stock();    // buy back (with a certain probability) a stock from investor

extern void Bank::erase_obligation(); // buy back (with a certain probability) an obligation from investor

extern void Bank::update_securities_prices(); // update prices on securities

extern vector<struct bank_info> Bank::get_report_per_n_years(int n); // get result of bank working n years, returns vector of bank states

extern void get_delta(vector<struct bank_info> &a, int k, int m);   // get result of bank working from k to m year of its life
