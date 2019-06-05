#define _ERR_INVALID_INPUT 1

#include "../headers/univeristy_sulyma.h"

#include <iostream>
#include <fstream>

using namespace University;

void TestStudent()
{

}

void TestTeacher()
{

}

void TestWorker()
{

}

void TestRecordbook()
{
    Recordbook r;

    std::cout << "Input marks for math, cs, philosophy, p.e.:" << std::endl;
    std::cin >> r;

    std::cout << "Output marks:" << std::endl;
    std::cout << r;

    std::cout << "Writing data..." << std::endl;

    std::fstream i_text_file_stream("../output_data_recordbook.txt", std::ios::out);

    i_text_file_stream << r;

    i_text_file_stream.close();

    std::cout << "Done." << std::endl;

    Recordbook q;

    std::cout << "Reading data from text file..." << std::endl;

    std::fstream o_text_file_stream("../output_data_recordbook.txt", std::ios::in);

    o_text_file_stream >> q;

    o_text_file_stream.close();

    std::cout << q;

    std::cout << "Done." << std::endl;

    std::cout << "Avg. is " << r.getAverage() << std::endl;
}

int main()
{
    short m;

    std::cout << "\tEnter mode:\n"
           "1 - test Student class\n"
           "2 - test Teacher class\n"
           "3 - test Worker class\n"
           "4 - test Recordbook class\n" << std::endl;

    std::cin >> m;

    switch (m)
    {
        case 1:
        {
            TestStudent();
            break;
        }
        case 2:
        {
            TestTeacher();
            break;
        }
        case 3:
        {
            TestWorker();
            break;
        }
        case 4:
        {
            TestRecordbook();
            break;
        }
        default:
        {
            std::cout << "Error: Invalid input" << std::endl;
            exit(_ERR_INVALID_INPUT);
        }
    }
}