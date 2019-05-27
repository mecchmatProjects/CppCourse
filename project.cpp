#include <iostream>
#include <vector>
#include "worker.h"
#include "student.h"
#include "teacher.h"
#include "record_book.h"
int main(int argc, char* argv[])
{
    std::vector<record_book> record_book_list;
    std::vector<student> student_list;
    std::vector<teacher> teacher_list;
    std::vector<worker> worker_list;
    std::string name, last_name, kind;
    unsigned int experience, work_time,degree, basic_salary, record_book_num, number, mathematical_analysis, data_science, algebra, philosophy;
    int N, num, j;
    std::string mathematical_analysis_teacher, data_science_teacher, algebra_teacher, philosophy_teacher;
    while (num != 8){
        std::cout <<"Select operation mode:  {1-8} "<<std::endl<<"1. Add a student"
        <<std::endl<<"2. Add a teacher"<<std::endl<<"3. Add a record book"
        <<std::endl<<"4. Operations with a teacher"<<std::endl<<"5. Operations with a student"<<std::endl<<"6. Add a worker "
        <<std::endl<<"7. Show lists of people at the university"<<std::endl<<"8. Exit"<<std::endl;
        std::cin>>num;
        if (num == 1)
        {
            std::cout <<"Enter the student's  last name, name, record book number"<<std::endl;
            std::cin>> last_name;
            std::cin>> name;
            std::cin>> record_book_num;
            student_list.push_back(student(last_name, name, record_book_num));
        }
        else if(num == 2){
            std::cout <<"Enter the teacher's  last name, name, experience, degree, work time in a week and basic salary at the university"<<std::endl;
            std::cin>> last_name;
            std::cin>> name;
            std::cin>> experience;
            std::cin>>degree;
            std::cin>> work_time;
            std::cin>> basic_salary;
            teacher_list.push_back(teacher(last_name, name, experience,work_time,degree, basic_salary));
        }
        else if (num == 3){
            std::cout <<"Enter record book: number, mathematical_analysis and teacher, data_science and teacher, algebra and teacher, philosophy and teacher: "<<std::endl;
            std::cin>> number;
            std::cin>> mathematical_analysis;
            std::cin>> mathematical_analysis_teacher;
            std::cin>> data_science;
            std::cin>> data_science_teacher;
            std::cin>> algebra;
            std::cin>> algebra_teacher;
            std::cin>> philosophy;
            std::cin>> philosophy_teacher;
            record_book_list.push_back(record_book(number, mathematical_analysis, mathematical_analysis_teacher, data_science,
                                                   data_science_teacher, algebra, algebra_teacher, philosophy, philosophy_teacher ));
        }
        else if (num == 4){
            std::string tname;
            std::cout<<"Enter the teacher name "<<std::endl;
            std::cin>>tname;
            for (int h = 0; h<teacher_list.size(); h++){
                std::cout<<teacher_list[h].get_full_name();
                if (tname == (teacher_list[h].get_full_name())){
                    std::cout<<"Salary: "<<teacher_list[h].get_salary()<<std::endl;
                    break;
                }
            std::cout<<"Teacher is not found "<<std::endl;
            }
        }
        else if (num == 5){
            std::string sname;
            std::cout<<"Enter the student name "<<std::endl;
            std::cin>>sname;
            for (int h = 0; h<student_list.size(); h++){
                if (sname == (student_list[h].get_full_name())){
                    for (int g = 0; h<record_book_list.size(); g++){
                        if (student_list[h].get_record_book_number() == record_book_list[g].get_number())
                            std::cout<<sname<<"'s average score is "<<record_book_list[g].get_average_score()<<std::endl;
                            break;
                    }
            std::cout<<"Student or his record book is not found"<<std::endl;

        }
        }
        }
        else if (num == 6){
            std::cout <<"Enter the worker's  last name, name, kind of prof, experience,  work time in a week and basic salary at the university"<<std::endl;
            std::cin>> last_name;
            std::cin>> name;
            std::cin>> kind;
            std::cin>> experience;
            std::cin>> work_time;
            std::cin>> basic_salary;
            worker_list.push_back(worker(last_name, name, kind, experience,work_time, basic_salary));
        }
        else if (num == 7){
            std::cout<<"Students: "<<std::endl;
            for (int b = 0; b<student_list.size(); b++){
                std::cout<<b<<"."<<student_list[b].get_full_name()<<std::endl;
            }
            std::cout<<"Teachers: "<<std::endl;
            for (int b = 0; b<teacher_list.size(); b++){
                std::cout<<b<<"."<<teacher_list[b].get_full_name()<<std::endl;
            std::cout<<"Workers: "<<std::endl;
            }
            for (int b = 0; b<worker_list.size(); b++){
                std::cout<<b<<"."<<worker_list[b].get_full_name()<<std::endl;
            }
            std::cout<<"Record books numbers: "<<std::endl;
            for (int b = 0; b<record_book_list.size(); b++){
                std::cout<<b<<"."<<record_book_list[b].get_number()<<std::endl;
            }
            }

    }
    return 0;
}
