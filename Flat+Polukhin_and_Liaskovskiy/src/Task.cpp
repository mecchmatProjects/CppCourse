#include "Task.hpp"
#include "Point.hpp"

Task::~Task()
{
}

Task::Task()
{
    this->flat = Flat();
    this->target = Target();

    std::cout << "\nInput start position x y:\n";
    int x, y;
    std::cin >> x >> y;
    Point start = Point(x, y);

    std::cout << "\nInput stamina (how many times robot can do action):\n";
    uint stamina;
    std::cin >> stamina;

    std::cout << "\nInput number of tests:\n";
    uint testsCount;
    std::cin >> testsCount;

    for (size_t i = 0; i < testsCount; i++)
    {
        Robot robot = Robot(start, stamina, &(this->flat), &(this->target));
        this->robots.push_back(robot);
    }
}

uint Task::GetAverageScore()
{
    uint averageScore = 0;

    for (size_t i = 0; i < this->results.size(); i++)
    {
        averageScore += results[i];
    }

    averageScore /= results.size();

    return averageScore;
}

void Task::DoTest()
{
    for(uint _i = 0; _i < robots.size(); ++_i)
    {
        robots[_i].Start();    
    }
}