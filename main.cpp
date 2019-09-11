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

    Product P1("TEST", 100);
    Equipment E1("TEST1", 150), E2("TEST1", 175);

    Profession PROF;

    cin >> PROF;

    Employee TEST_UNIT_1;

    TEST_UNIT_1.set_name("Alyona");
    TEST_UNIT_1.set_job(PROF);

    TEST_UNIT_1.push_back_product(P1);

    TEST_UNIT_1.push_back_equipment(E1);
    TEST_UNIT_1.push_back_equipment(E2);

    TEST_UNIT_1.set_years(10);

    cout << TEST_UNIT_1.calc_wages()          << endl
         << TEST_UNIT_1.calc_product_cost()   << endl
         << TEST_UNIT_1.calc_equipment_cost() << endl;
}

void test_manager()
{
    cout << "Start" << endl;

    Product P1("TEST", 75);
    Equipment E1("TEST1", 25), E2("TEST1", 15);

    Profession PROF;

    PROF.set_t("TEST_UNIT_1");

    Employee TEST_UNIT_1;

    TEST_UNIT_1.set_name("User_Test_Unit");
    TEST_UNIT_1.set_job(PROF);

    TEST_UNIT_1.push_back_product(P1);

    TEST_UNIT_1.push_back_equipment(E1);
    TEST_UNIT_1.push_back_equipment(E2);

    TEST_UNIT_1.set_years(9);

    Manager TEST_UNIT_MANAGER;

    TEST_UNIT_MANAGER.set_name("Ernest");

    for(int i=0; i<3; i++)
        TEST_UNIT_MANAGER.push_back_employee(TEST_UNIT_1);

    cout << TEST_UNIT_MANAGER.calc_employees_e_values() << endl
         << TEST_UNIT_MANAGER.calc_employees_p_values() << endl
         << TEST_UNIT_MANAGER.calc_employees_w_values() << endl;

    TEST_UNIT_MANAGER.pop_employee_by_index(1);
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