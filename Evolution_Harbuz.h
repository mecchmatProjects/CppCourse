#include <vector>
#include <cstdlib>

class FitnessFunction{
    unsigned int n;


    public:
        std::vector<double> f;
        double fitFun(std::vector<int> v);
};

class Animal{
    std::vector<int> genome;


    public:
        double fitness_value = 0;

        Animal(size_t count);
        Animal(std::vector<int> genome);

        void Input();

        void mutate(int n);

        void Print();
        void PrintToFile(const char* filename);
        void ReadFromShell();
        void ReadFromFile(char* filename);

        Animal breed(Animal x);
        double fitness(FitnessFunction f);
};


class Herb{
    size_t n;
    std::vector<Animal> animals;

    public:
        int add(Animal animal);
        int add(Animal* animal, int n);
        std::vector<Animal*> selection(size_t m, FitnessFunction f);
        Animal crossover(size_t m, FitnessFunction f);
        int select(int n, FitnessFunction f);
};
