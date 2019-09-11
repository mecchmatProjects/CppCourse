#ifndef TRUKHAN_CPP_PROJECT_PLANT_TRUKHAN_CPP_PROJECT_PLANT_H
#define TRUKHAN_CPP_PROJECT_PLANT_TRUKHAN_CPP_PROJECT_PLANT_H

using namespace std;

#include <fstream>
#include <string>
#include <vector>

#include <iostream>

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
    string first_result, second_result;

    in >> first_result >> second_result;

    P.set_t(first_result);

    P.set_v(stoi(second_result));

    return in;
}

ostream &operator<<(ostream &out, const Product &P)
{
    out << P.Title << endl << to_string(P.Value);
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
    Profession();
    explicit Profession(string);
    Profession(string, float);

    void set_t(string);
    void set_w(float);

    string get_t();
    float get_w();

    float calc_wages(unsigned);

    friend istream &operator>>(istream&, Profession&);
    friend ostream &operator<<(ostream&, const Profession&);
};

istream &operator>>(istream &in, Profession &P)
{
    string first_result, second_result;

    in >> first_result >> second_result;

    P.set_t(first_result);

    P.set_w(stoi(second_result));

    return in;
}

ostream &operator<<(ostream &out, const Profession &P)
{
    out << P.Title << endl << to_string(P.Cash);
    return out;
}

Profession::Profession() : Title(), Cash() {}

Profession::Profession(string s) : Title(s), Cash() {}

Profession::Profession(string s, float w) : Title(s), Cash(w) {}

void Profession::set_t(string s)
{
    this->Title = s;
}

void Profession::set_w(float w)
{
    this->Cash = w;
}

float Profession::calc_wages(unsigned y)
{
    return static_cast<float>((y * 0.1 + 1 ) * this->Cash); // y? because
}

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
    out << P.Name;
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
    vector<Product> Products_in_use;
    vector<Equipment> Equipment_in_use;
public:
    Employee();
    Employee(string, unsigned);
    explicit Employee(string);

    void set_years(unsigned);
    unsigned get_years();

    float calc_wages();
    float calc_product_cost();
    float calc_equipment_cost();
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

float Employee::calc_wages()
{
    if(this->Job.get_t().empty() && !this->Job.get_w())
        throw runtime_error("Employee doesn't have any job yet..\n");

    return this->Job.calc_wages(this->Years) + 0.001 * (this->calc_equipment_cost() + this->calc_product_cost());
}

float Employee::calc_product_cost()
{
    float final_sum = 0;

    for(auto& product : this->Products_in_use)
        final_sum += product.get_v();

    return final_sum;
}

float Employee::calc_equipment_cost()
{
    float final_sum = 0;

    for(auto& product : this->Equipment_in_use)
        final_sum += product.get_v();

    return final_sum;
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

#endif
