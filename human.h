// human.h
#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED

#include <string>
#include <sstream>

class human {
    public:
        // constructor human
        human(std::string last_name,
              std::string name)
        {
            this->last_name = last_name;
            this->name = name;
        }

        // Get full name
        std::string get_full_name()
        {
            std::ostringstream full_name;
            full_name << this->last_name;
            return full_name.str();
        }

    private:
        std::string name; // имя
        std::string last_name; // фамилия
};

#endif // HUMAN_H_INCLUDED
