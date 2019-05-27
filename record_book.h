// record_book.h
#ifndef RECORD_BOOK_H_INCLUDED
#define RECORD_BOOK_H_INCLUDED

#include <string>
#include <sstream>

class record_book{
    private:
        unsigned int number;
        unsigned int mathematical_analysis;
        std::string mathematical_analysis_teacher;
        unsigned int data_science;
        std::string data_science_teacher;
        unsigned int algebra;
        std::string algebra_teacher;
        unsigned int philosophy;
        std::string philosophy_teacher;
    public:
        record_book(unsigned int number,
                    unsigned int mathematical_analysis, std::string mathematical_analysis_teacher,
                    unsigned int data_science, std::string data_science_teacher,
                    unsigned int algebra, std::string algebra_teacher,
                    unsigned int philosophy, std::string philosophy_teacher)
        {
            this->number = number;
            this->mathematical_analysis = mathematical_analysis;
            this->data_science = data_science;
            this->algebra = algebra;
            this->philosophy = philosophy;
            this->mathematical_analysis_teacher = mathematical_analysis_teacher;
            this->data_science_teacher = data_science_teacher;
            this->algebra_teacher = algebra_teacher;
            this->philosophy_teacher = philosophy_teacher;
        }

        unsigned int get_number()
        {
            return this->number;
        }
        // Get student's average score
        float get_average_score()
        {
            std::vector<unsigned int> scores;
            scores.push_back(this->mathematical_analysis);
            scores.push_back(this->data_science);
            scores.push_back(this->algebra);
            scores.push_back(this->philosophy);
            unsigned int sum_scores = 0;
            // Average marks
            float average_score;

            for (unsigned int i = 0; i < 4; ++i) {
                sum_scores += scores[i];
            }

            average_score = (float) sum_scores / 4.0;
            return average_score;
        }
    std::vector<std::string> get_list_of_teachers()
    {
        std::vector<std::string> list_of_teachers;
        list_of_teachers.push_back(this->mathematical_analysis_teacher);
        list_of_teachers.push_back(this->data_science_teacher);
        list_of_teachers.push_back(this->algebra_teacher);
        list_of_teachers.push_back(this->philosophy_teacher);
        return list_of_teachers;

    }
};
#endif // RECORD_BOOK_H_INCLUDED
