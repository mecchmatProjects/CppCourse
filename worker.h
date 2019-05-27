// worker.h
#ifndef WORKER_H_INCLUDED
#define WORKER_H_INCLUDED

#include "human.h"

class worker : public human {
    // worker constructor
public:
    worker(
            std::string last_name,
            std::string name,
            std::string kind_of_prof,
            // Work time  and work experience
            unsigned int experience,
            unsigned int work_time,
            unsigned int basic_salary
    ) : human(
            last_name,
            name)
    {
        this->work_time = work_time;
        this->experience = experience;
        this->basic_salary = basic_salary;
    }

    // Gettimg work time
    unsigned int get_work_time()
    {
        return this->work_time;
    }

    // Gettimg an experience
    unsigned int get_experience()
    {
        return this->experience;
    }


    // Gettimg a basic salary
    unsigned int get_basic_salary()
    {
        return this->basic_salary;
    }

    float get_salary()
    {
        float salary = ((float) this->basic_salary * (2 - ((float) this ->degree * 0.1)) +
                        ((float) this->basic_salary * (float)this ->experience * 0.1)) * (((float)this -> work_time)/40);
        return salary;
    }
private:
    // Work time, experience, degree
    unsigned int work_time;
    unsigned int experience;
    unsigned int degree;
    unsigned int basic_salary;
};
#endif
