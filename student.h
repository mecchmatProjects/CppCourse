// student.h
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "human.h"
#include <string>
#include <vector>

class student : public human {
    public:
        // Student constructor
        student(
            std::string last_name,
            std::string name,
            unsigned int record_book_number
        ) : human(
            last_name,
            name
        ) {
            this->record_book_number = record_book_number;
        }
    unsigned int get_record_book_number(){
            return this->record_book_number;
        }

    private:
        unsigned int record_book_number;
};
#endif // STUDENT_H_INCLUDED
