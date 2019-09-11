#define TESTS_NUM 6

#include "./headers/trukhan_cpp_project_plant.h"

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
    cout << TEST_UNIT_3 << endl;
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

    Product TEST_UNIT_1;

    cin >> TEST_UNIT_1;
    cout << TEST_UNIT_1 << endl;

    TEST_UNIT_1.set_t("Useless Item");
    TEST_UNIT_1.set_v(100);

    cout << TEST_UNIT_1.get_t() << '\t' << TEST_UNIT_1.get_v() << endl;

    fstream file;

    file.open("../test_product.txt", ios::out);
    file << TEST_UNIT_1;
    file.close();
}

void test_equipment()
{
    cout << "Start" << endl;

    Equipment TEST_UNIT_1;

    cin >> TEST_UNIT_1;
    cout << TEST_UNIT_1 << endl;

    TEST_UNIT_1.set_v(100);
    TEST_UNIT_1.set_t("Cucumber");

    cout << TEST_UNIT_1 << endl;
}

void test_profession()
{
    cout << "Start" << endl;

    Profession TEST_UNIT_1;

    TEST_UNIT_1.set_t("Plumber");
    TEST_UNIT_1.set_w(1500);

    cout << TEST_UNIT_1 << endl;
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