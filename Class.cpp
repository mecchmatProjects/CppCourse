#include <iostream>
#include <string>
using namespace std;

//Абстрактний клас
class Person
{
    public:
    virtual~Person(){};
    virtual void Show()=0;
     };

class Profession
{
    string profession_name; // назва професії
    double basic_salary; // базова ставка зарплатні
    public:
        Profession() // Конструктор за замовчуванням
        {
            profession_name = "None";
            basic_salary = 0;
        }
        Profession(string prof, double salary) // Конструктор
        {
            profession_name = prof;
            basic_salary = salary;
        }
        double get_salary()
        {
            return basic_salary;
        }
        string get_name ()
        {
            return profession_name;
        }

};
class Equipment
{
    string equipment_name; // назва обладнання
    double equipment_cost; // вартість обладнання
    public:
        Equipment()
        {
            equipment_name = "None";
            equipment_cost = 0;
        }
        Equipment(string equipm, double cost)
        {
            equipment_name = equipm;
            equipment_cost = cost;
        }
        string get_name()
        {
            return equipment_name;
        }
        double get_cost()
        {
            return equipment_cost;
        }
        void set_cost()
        {
            double cost;
            cout << "Set equipment cost: ";
            cin >> cost;
            equipment_cost = cost;
        }
};
class Product
{
    string product_name; // назва виробу
    double product_cost; // вартість виробу
    unsigned product_quantity;
    public:
        Product ()
        {
            product_name = "None";
            product_cost = 0.0;
        }
        Product (string prname, unsigned prquantity, double prcost)
        {
            product_name = prname;
            product_quantity = prquantity;
            product_cost = prcost;
        }
        string get_name()
        {
            return product_name;
        }
        double get_cost()
        {
            return product_cost;
        }
        unsigned get_quantity()
        {
            return product_quantity;
        }
        void set_quantity()
        {
            double quantity;
            cout <<"Set product quantity: ";
            cin>>quantity;
            product_quantity = quantity;
        }
        void set_cost()
        {
            double cost;
            cout <<"Set product cost: ";
            cin>>cost;
            product_cost = cost;
        }
};
/*class Head // Клас керівник
{

};*/
class Worker : public Person// клас Робітник, нащадок абстрактного класу Person
{
    public:
    Worker(string name, unsigned age, Profession prof, Equipment eq, Product pr, unsigned exp)
    {
        worker_name = name;
        worker_age = age;
        profes = prof;
        equipm = eq;
        prod = pr;
        experience = exp;
    }

    string get_name()
    {
        return worker_name;
    }
    void set_age()
    {
            double age;
            cout <<"Set worker age: ";
            cin>>age;
            worker_age = age;
    }
    double salary()
    {
        double surcharge;
        if (experience < 1)
            surcharge = 0.0;
        else if (experience <=5)
            surcharge = 0.15;
        else surcharge = 0.25;
        return (profes.get_salary()*(1.+surcharge)+prod.get_quantity()*prod.get_cost()*0.01);
    }
    void Show ()
    {
        cout << "Worker name is " << worker_name << endl;
        cout << "Worker age is " << worker_age << endl;
        cout << "Worker profession is " << profes.get_name() << endl;
    }
    protected:

        string worker_name;  //ім’я
        unsigned worker_age; //вік
        Profession profes;
        Equipment equipm;
        Product prod;
        unsigned experience;


};
int main()
{
    Profession pr1 = Profession("profession_1",5500.0); // приклади
    Profession pr2 = Profession("profession_2",7200.0);
    Profession pr3 = Profession("profession_3",9000.0);
    Equipment eq1 = Equipment ("equipment_1",10000.0);
    Equipment eq2 = Equipment ("equipment_2",25000.0);
    Product prod1 = Product ("product_1",10,100);
    Worker wrk1 = Worker ("Ivan Petrov",39,pr2,eq2,prod1,10);
    wrk1.Show();
    cout << "Worker salary is " << wrk1.salary();
    return 0;
}
