#define TESTS_NUM 6

#include "./headers/trukhan_cpp_project_plant.h"

#include <exception>
#include <iostream>

void test_person()
{
    cout << "Start" << endl;

    Person TEST_UNIT_1;

    TEST_UNIT_1.set_name("Ernest");
    cout << TEST_UNIT_1.get_name() << endl;

    string INPUT_NAME;

    cout << "Input your name" << endl;
    cin >> INPUT_NAME;

    Person TEST_UNIT_2(INPUT_NAME);

    cout << TEST_UNIT_2.get_name() << endl;

    Person TEST_UNIT_3;

    cin >> TEST_UNIT_3;
    cout << TEST_UNIT_3;
}

void test_employee()
{
    cout << "Start" << endl;
}

void test_manager()
{
    cout << "Start" << endl;
}

void test_product()
{
    cout << "Start" << endl;
}

void test_equipment()
{
    cout << "Start" << endl;
}

void test_profession()
{
    cout << "Start" << endl;
}

void (*tests[TESTS_NUM])() = {
        test_person,
        test_employee,
        test_manager,
        test_product,
        test_equipment,
        test_profession
};

int main()
{
    unsigned v;
    try
    {
        cout << "Tests for ...        \n"
                "1 - class Person     \n"
                "2 - class Employee   \n"
                "3 - class Manager    \n"
                "4 - class Product    \n"
                "5 - class Equipment  \n"
                "6 - class Profession \n";
        cin >> v;
        if(!cin || (v > TESTS_NUM) || !v)
            throw runtime_error("Invalid input\n");
        tests[v-1]();
    }
    catch (runtime_error e)
    {
        cerr << e.what();
    }
}