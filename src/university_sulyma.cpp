#include "../headers/univeristy_sulyma.h"

University::Recordbook::Recordbook():
math(), computerScience(), philosophy(), pe()
{}

University::Recordbook::Recordbook(int i1, int i2, int i3, int i4):
math(i1), computerScience(i2), philosophy(i3), pe(i4)
{}

double University::Recordbook::getAverage()
{
    return (math + computerScience + philosophy + pe) / 4.;
}

University::Profession::Profession():
title(), experience(), k()
{}

University::Profession::Profession(std::string s, int i1, int i2):
title(s), experience(i1), k(i2)
{}

int University::Profession::premium()
{
    return k * experience;
}

University::Student::Student():
rb(Recordbook()), name(), surname()
{}

University::Student::Student(int i1, int i2, int i3, int i4, std::string s1, std::string s2):
rb(Recordbook(i1, i2, i3, i4)), name(s1), surname(s2)
{}

int University::Student::getSalary()
{
    return (int)(4000 * rb.getAverage());
}

University::Teacher::Teacher():
name(), surname(), rate(), experience()
{}

University::Teacher::Teacher(std::string s1, std::string s2, bool b, int i):
name(s1), surname(s2), rate(b), experience(i)
{}

University::Worker::Worker():
profession(Profession()), name(), surname()
{}

University::Worker::Worker(std::string s1, std::string s2, std::string s3, int i1, int i2):
profession(Profession(s1, i1, i2)), name(s2), surname(s3)
{}