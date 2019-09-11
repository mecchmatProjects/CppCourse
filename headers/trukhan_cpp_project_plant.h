#ifndef TRUKHAN_CPP_PROJECT_PLANT_TRUKHAN_CPP_PROJECT_PLANT_H
#define TRUKHAN_CPP_PROJECT_PLANT_TRUKHAN_CPP_PROJECT_PLANT_H

using namespace std;

#include <string>
#include <vector>

class Product
{
protected:
    string Title;
    int Value;
public:
    Product();
    Product(string, int);
    explicit Product(string);

    void set_t(string);
    void set_v(int);

    string get_t();
    int get_v();

    friend istream &operator>>(istream&, Product&);
    friend ostream &operator<<(ostream&, const Product&);
};

istream &operator>>(istream &in, Product &P)
{
    string first_result;
    int second_result;
    in >> first_result;
    P.set_t(first_result);

    return in;
}

ostream &operator<<(ostream &out, const Product &P)
{
    out << static_cast<string>("Class Person Data:\t") << P.Name;
    return out;
}

Product::Product() : Title(), Value() {}

Product::Product(string s) : Title(s), Value() {}

Product::Product(string s, int v) : Title(s), Value(v) {}

string Product::get_t()
{
    return this->Title;
}

int Product::get_v()
{
    return this->Value;
}

void Product::set_t(string s)
{
    this->Title = s;
}

void Product::set_v(int v)
{
    this->Value = v;
}

class Equipment: public Product
{
public:
    Equipment();
    explicit Equipment(string);
    Equipment(string, int);
};

Equipment::Equipment() : Product() {}

Equipment::Equipment(string s) : Product(s) {}

Equipment::Equipment(string s, int v) : Product(s, v) {}

class Profession
{
private:
    string Title;
    float Cash;
public:

};
class Person
{
protected:
    string Name;
public:
    Person();
    explicit Person(string);

    void set_name(string);
    string get_name();

    friend istream &operator>>(istream&, Person&);
    friend ostream &operator<<(ostream&, const Person&);
};

istream &operator>>(istream &in, Person &P)
{
    string result;
    in >> result;
    P.set_name(result);
    return in;
}

ostream &operator<<(ostream &out, const Person &P)
{
    out << static_cast<string>("Class Person Data:\t") << P.Name;
    return out;
}

Person::Person() : Name() {}

Person::Person(string N) : Name(N) {}

void Person::set_name(string N)
{
    this->Name = N;
}

string Person::get_name()
{
    return this->Name;
}

class Employee: public Person
{
protected:
    unsigned Years;
    Profession Job;
    vector<Equipment> Equipment_in_use;
public:
    Employee();
    Employee(string, unsigned);
    explicit Employee(string);

    void set_years(unsigned);
    unsigned get_years();
};

Employee::Employee() : Person(), Years() {}

Employee::Employee(string s) : Person(s), Years() {}

Employee::Employee(string s, unsigned y) : Person(s), Years(y) {}

void Employee::set_years(unsigned y)
{
    this->Years = y;
}

unsigned Employee::get_years()
{
    return this->Years;
}

class Manager: public Employee
{
private:
    vector<Employee> Employees_list;
public:
    Manager();
    explicit Manager(string);
    Manager(string, unsigned);
};

class Pluralist: public Employee
{

};

#endif
