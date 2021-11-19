#include "Evolution_Harbuz.h"
#include <random>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdio>

//��������� ������� ������� v � f
double FitnessFunction::fitFun(std::vector<int> v){
    if (v.size() != f.size()){
        return -1;
    }
    double res=0;
    for (unsigned a=0; a<v.size(); a++)
    {
        res+=v[a]*f[a];
    }

    return res;
}

//����������� ���� ������ ������� �������� �������
Animal::Animal(size_t count){
    for (unsigned a=0; a<count; a++){
        srand (time(NULL)+a);
        genome.push_back(rand());
    }
}
//����������� ������ ������ �����
Animal::Animal(std::vector<int> genome){
    for (auto &i : genome)
    {
        this->genome.push_back(i);
    }
}
//����� �� ����� m ��� x ����� � ������� ����� ���������� ����� � ������� ���� ��������
int changeBits(int m, int x){
    unsigned int x2 = 0;
    x2--;
    x2>>(sizeof (x)-m);
    return (x^x2);
}

unsigned int set_bits(unsigned int a, int n, unsigned int z, int v){
    unsigned int l = (sizeof(a) << 3) - (v + n);
    unsigned int x = (((a >> n) << n) << l) >> l;
    return (a ^ x) | (((z << n) << l) >> l);
}
// ����� �� ����� m ��� n ����� � ������� genome ���������� ����� � ������� ��������
void Animal::mutate(int n){ //n numbers
    //int** numbers = new int*[n];
    int size_genom=genome.size();
    for(int i=0;i<n;i++){
        int k=rand()%size_genom+0;


        int value=genome[k];

        int z=rand()%9001+1000;
        genome[k]=z;

    }

}
//�������� ����� �������� �� ������
void Animal::Print(){
    std::cout<<"Animal genome: ";
    for (auto &i : genome)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

void Animal::PrintToFile(const char* filename){
    std::ofstream out;
    out.open(filename);
    if (out.is_open())
    {
        for(auto &i:genome) out << i << " ";
    }
}


// ������� ���� �������� � genome, �� � ���������� genome-�� x �� ��������� Animal (���������, ������ ����������� �� ��������� �����).
Animal Animal::breed(Animal x){
    //Animal animal(animal.genome.size());
    std::vector<int> new_genome;

    int a=0;
    for (auto &i : x.genome)
    {
        new_genome.push_back((i+genome[a])/2);
        a++;
    }

    return Animal(new_genome);
}
//��������� FitnessFunction �� genome
double Animal::fitness(FitnessFunction f){
    fitness_value = f.fitFun(genome);
    return fitness_value;
}
// ������ ������� �� �����
int Herb::add(Animal animal){
    animals.push_back(animal);
    return animals.size();
}

int Herb::add(Animal* animal, int n){
    for (int a=0; a<n; a++){
        animals.push_back(animals[a]);
    }
    return animals.size();
}
 // ������ ������ �������� �� �����
std::vector<Animal*> Herb::selection(size_t m, FitnessFunction f){
    for (unsigned a=0; a<animals.size()-1; a++){
        animals[a].fitness(f);
        if (animals[a].fitness_value>animals[a+1].fitness_value){
            Animal temp = animals[a+1];
            animals[a+1]=animals[a];
            animals[a] = temp;
            a=0;
        }
    }

    std::vector<Animal*> res;
    for (unsigned a=0;a<m;a++){
        res.push_back(&animals[a]);
    }
}
//C�������� ���������(��������� �� ������� ������) m �������� � ����������� ��������� �� ������ �� �� �����
Animal Herb::crossover(size_t m, FitnessFunction f){
    std::vector<Animal*> best = selection(m,f);

    Animal animal = *best[0];
    for (int a=0; a<m-1;a++){
        animal.breed(*best[a+1]);
    }
    return animal;
}
//�������� ���� n ��������� �� ������� ������
int Herb::select(int n, FitnessFunction f){
    for (int a=0; a<animals.size()-1; a++){
        animals[a].fitness(f);
        if (animals[a].fitness_value>animals[a+1].fitness_value){
            Animal temp = animals[a+1];
            animals[a+1]=animals[a];
            animals[a] = temp;
            a=0;
        }
    }

    for (int a=n;a<animals.size();a++){
        animals.pop_back();
    }
}

