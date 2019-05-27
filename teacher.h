// teacher.h
#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED

#include "human.h"
#include <string>

class teacher : public human {
    // teacher constructor
    public:
        teacher(
            std::string last_name,
            std::string name,
            // Work time  and work experience
            unsigned int experience,
            unsigned int work_time,
            unsigned int degree,
            unsigned int basic_salary
        ) : human(
            last_name,
            name)
            {
            this->work_time = work_time;
            this->experience = experience;
            this->degree = degree;
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

        // Gettimg an degree
        unsigned int get_degree()
        {
            return this->degree;
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

#endif // TEACHER_H_INCLUDED
