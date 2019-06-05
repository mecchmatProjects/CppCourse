#ifndef UNIVERSITY_SULYMA_MARIIA_UNIVERISTY_SULYMA_H
#define UNIVERSITY_SULYMA_MARIIA_UNIVERISTY_SULYMA_H

#include <iostream>
#include <string>

namespace University
{
    class Human;
    class Recordbook;
    class Profession;

    class Student;
    class Teacher;
    class Worker;
}

class University::Human
{
    virtual int getSalary() = 0;
};

class University::Recordbook
{
private:
    int math;
    int computerScience;
    int philosophy;
    int pe;
public:
    Recordbook();
    Recordbook(int i1, int i2, int i3, int i4);

    double getAverage();

    friend std::istream &operator>>(std::istream &in, Recordbook &r)
    {
        in >> r.math;
        in >> r.computerScience;
        in >> r.philosophy;
        in >> r.pe;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, const Recordbook &r)
    {
        out << r.math << std::endl;
        out << r.computerScience << std::endl;
        out << r.philosophy << std::endl;
        out << r.pe << std::endl;
        return out;
    }
};

class University::Profession
{
    const static int base = 8000;
public:
    std::string title;
    int experience;
    int k;

    Profession();
    Profession(std::string s, int i1, int i2);

    int premium();
};

class University::Student : public Human
{
    Recordbook rb;
    std::string name;
    std::string surname;

    Student();
    Student(int i1, int i2, int i3, int i4, std::string s1, std::string s2);

    int getSalary() override;
};

class University::Teacher : public Human
{
    std::string name;
    std::string surname;
    bool rate;
    int experience;

    Teacher();
    Teacher(std::string s1, std::string s2, bool b, int i);

    int getSalary() override
    {
        if (!rate)
        {
            return 15000 + 1000 * experience;
        }
        return 25000 + 1000 * experience;
    }
};

class University::Worker : public Human
{
    std::string name;
    std::string surname;
    Profession profession;

    Worker();
    Worker(std::string s1, std::string s2, std::string s3, int i1, int i2);
};

#endif