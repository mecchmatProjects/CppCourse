//GNU GCC Compiler
//���� �������(Animal) ���������� � ������� (genome) ����� ��� ����� �����.
//������: ��������/��������� � ������� �� �/� �����.
//�����������: ������ ������ genome ��� ������� �������� ������� �� ���������� ����� ������ genome.
//AnimalAnimal::mutate(intn, intm);
 // ����� �� ����� m ��� n ����� � ������� genome ���������� ����� �� ������ � ���� ��������
//voidAnimal::mutate(intn, intm);
// ����� �� ����� m ��� n ����� � ������� genome ���������� ����� � ������� ��������

//AnimalAnimal::breed(Animalx);
// ������� ���� �������� � genome, �� � ���������� genome-�� x �� ��������� Animal
//(���������, ������ ����������� �� ��������� �����). �������� ��������� �����������.

//doubleAnimal::fitness(FitnessFunction f ); //��������� FitnessFunction �� genome
//���������(Herb):
//size_t n;
//����� Animal;

//������:
//Int Herb::add(Animal); // ������������� �� �����
//IntHerb::add(Animal*, intn); // ������ ������ �������� �� �����
//Intselection(size_tm); ������ m ��������� �� ������� ������
//Animal* crossover(size_tm); //C�������� ���������(��������� �� ������� ������)
//m �������� � ����������� ��������� �� ������ �� �� �����
//Intselect(); �������� ���� n ��������� �� ������� ������



#include <iostream>
#include "Evolution_Harbuz.h"
#include <string>
#include <fstream>
using namespace std;
void input_animal(){
    int n;
    cout<<"\nInput n=";
    cin>>n;
    vector<int> genom(n);
    string buffer="1";
    for(unsigned i=0;i<n;i++){
            cout<<"\ngenom["<<i<<"]";
        cin>>buffer;


            genom[i]=atoi(buffer.c_str());

    }
    unsigned int vector_size = genom.size();
    Animal animal(genom);
    animal.Print();
}

void input_file_animal(){

    const int len = 30, strings = 1;
	const char ch = '\n';
	char mass[len][strings];

	ifstream fs("Evolution_Skurativska.txt", ios::in | ios::binary);

	if(!fs) exit(1) ; //���� ������ �������� �����, �� ��������� ���������

	for(int r = 0; r<strings; r++)
	{
		fs.getline(mass[r], len-1,ch); //��������� ������ � ������
		cout << "genom" << r+1 << " = "<< mass[r] << endl; //������ ������ �� �������
	}
	fs.close(); //��������� ����

}

void print_file(){
    int n;
    cout<<"\nInput n=";
    cin>>n;
    vector<int> genom(n);
    string buffer="1";
    for(unsigned i=0;i<n;i++){
            cout<<"\ngenom["<<i<<"]";
        cin>>buffer;


            genom[i]=atoi(buffer.c_str());

    }
    unsigned int vector_size = genom.size();
    Animal animal(genom);
    animal.PrintToFile("Evolution_Skurativska.txt");

}

void emulation(){
    int n;
    cout<<"\nInput n=";
    cin>>n;
    vector<int> genom(n);
    string buffer="1";
    for(unsigned i=0;i<n;i++){
            cout<<"\ngenom_1["<<i<<"]";
        cin>>buffer;


            genom[i]=atoi(buffer.c_str());

    }
    unsigned int vector_size = genom.size();
    Animal animal(genom);


    vector<int> genom_1(n);
    string buffer_1="1";
    for(unsigned i=0;i<n;i++){
            cout<<"\ngenom_2["<<i<<"]";
        cin>>buffer_1;


            genom_1[i]=atoi(buffer_1.c_str());

    }
    unsigned int vector_size_1 = genom_1.size();
    Animal animal_1(genom_1);

    Animal result=(genom_1);
    result=animal_1.breed(animal);
    result.Print();

}
void change_genom(){
    int n;
    cout<<"\nInput n=";
    cin>>n;
    vector<int> genom(n);
    string buffer="1";
    for(unsigned i=0;i<n;i++){
            cout<<"\ngenom["<<i<<"]";
        cin>>buffer;


            genom[i]=atoi(buffer.c_str());

    }
    unsigned int vector_size = genom.size();
    Animal animal(genom);

    int k,m;
    cout<<"Input k:";
    cin>>k;
    animal.mutate(k);
    animal.Print();
}
void fitnesss(){
    int n;
    cout<<"\nInput n=";
    cin>>n;
    vector<int> vect(n);
    vector<int> genom(n);
    string buffer="1";
    for(unsigned i=0;i<n;i++){
            cout<<"\ngenom["<<i<<"]";
            cin>>buffer;
            genom[i]=atoi(buffer.c_str());
    }
    for(unsigned i=0;i<n;i++){
            cout<<"\fitnessfunc["<<i<<"]";
            cin>>buffer;
            vect[i]=atoi(buffer.c_str());
    }


    Animal animal(genom);
    int res=animal.fitness_value;
    for(int i=0;i<n;i++){
        res+=vect[i]*genom[i];
    }
    cout<<"\nResult="<<res<<"\n";


}

void test_Animal(){
    cout<<"\nChoices:\n11-input from console\n12-input from file";
    cout<<"\n13-print file\n14-emulation";
    cout<<"\n15-change genom in the current animal\n16-fitness\n10-exit";
    int k;
    while(k!=10){
        cout<<"\nChoice:";
            cin>>k;
        if(k==11) input_animal();
        if(k==12) input_file_animal();
        if(k==13) print_file();
        if(k==14) emulation();
        if(k==15) change_genom();
        if(k==16) fitnesss();
    }
}

void input_herb(){
    cout<<"\nNumber of animals";
    int n;
    cin>>n;
    for(int j=0;j<n;j++){
        int n;
        cout<<"\nInput n=";
        cin>>n;
        vector<int> genom(n);
        string buffer="1";
        for(unsigned i=0;i<n;i++){
            cout<<"\ngenom["<<i<<"]";
            cin>>buffer;
            genom[i]=atoi(buffer.c_str());

        }
        unsigned int vector_size = genom.size();
        Animal animal(genom);
        //Herb.animals[j]=animal;
    }

}

void print_herb(){
    cout<<"\nNot ready";
}
void add_one_animal(){
    cout<<"\nNot ready";
}
void test_Herb(){
    cout<<"\nChoices:\n21-input from console\n22-add one animal";
    cout<<"\n23-print herb";
    cout<<"\n20-exit";
    int k;
    while(k!=20){
        cout<<"\nChoice:";
            cin>>k;
        if(k==21) input_herb();
        if(k==22) add_one_animal();
        if(k==23) print_herb();
    }
}

void test(){
    cout<<"Choices:\n1-Test class Animals\n2-Test class Herb\n0-Exit";
    int k;
    while(k>0){
            cout<<"\nEnter choice(0,1 or 2):";
        cin>>k;
        if(k==1) test_Animal();
        if(k==2) test_Herb();
    }
}

int main(){
    test();
}
