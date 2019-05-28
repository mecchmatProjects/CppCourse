//#include <stdio.h>
//#include <cmath>
#include <iostream>
#include "tensor.h"
using namespace std;

void Test_operator_sum();
void Test_operator_sub();
void Test_operator_mul();
void Test_operator_mul_const();
void Test_operator_div_const();
void Test_operator_unadd();
void Test_operator_unsub(); //-=
void Test_operator_unar_min(); //-()
void Test_operator_equal(); //=
void Test_operator_index(); //[]
void Test_Method_hstack();
void Test_Method_vstack();
void Test_Method_transpose();


int main()
{

    cout << "Some of the tests may stop the program, so use them one by one\n";
    //Test_operator_sum();
    //Test_operator_sub();
    //Test_operator_mul();
    //Test_operator_mul_const();
    //Test_operator_div_const();
    //Test_operator_unadd();
    //Test_operator_unsub(); //-=
    //Test_operator_unar_min(); //-()
    //Test_operator_equal(); //=
    //Test_operator_index()
    //Test_Method_hstack();
    //Test_Method_vstack();
    //Test_Method_transpose();

    Tensor F_T;
    /*
    ifstream f, fw;
    f.open("/home/cstat/CLionProjects/tensorflow_pr/Tensor_Pryhodiuk/test_input.txt", ios::in);
    f >> F_T;

    fw.open("/home/cstat/CLionProjects/tensorflow_pr/Tensor_Pryhodiuk/test_output.txt", ios::out);

    cout << "check" << endl;

    cout << F_T << endl;

    cout << "end" << endl;

    Tensor R_T_I = Tensor::random_int_ranged(2, 3, 4, 8);
    Tensor R_T_F = Tensor::random_float_ranged(3, 2, 1, 5);

    cout << R_T_I << endl;
    cout << R_T_F << endl;

    Tensor R_T_I_0 = Tensor::random_int(3, 3);
    Tensor R_T_F_0 = Tensor::random_float(3, 4);

    cout << R_T_I_0 << endl;
    cout << R_T_F_0 << endl;*/

    Test_Method_vstack();
}

void Test_operator_sub()
{
    cout << "Testing operator -:" << endl;
    cout << "Equal sizes 1-dim:" << endl;

    Tensor T0 = Tensor:: ones(4);

    cout << "First:" << endl;
    cout << T0 << endl;

    DataType a[] = {1, 2, 3, 4};
    Tensor T1 = Tensor(4, a);

    cout << "Second:" << endl;
    cout << T1 << endl;

    cout << "Their sub:" << endl;
    cout << T0 - T1 << endl;

    cout << "Same sizes 2-dim:" << endl;

    Tensor T3 = Tensor:: ones(2, 2);

    cout << "First:" << endl;
    cout << T3 << endl;

    Tensor T4 = Tensor:: ones(2, 2);

    cout << "Second:" << endl;
    cout << T4 << endl;
    cout << "Their sub:" << endl;
    cout << T3 - T4 << endl;

    cout << "Different sizes 1-dim and 2-dim:" << endl;

    Tensor T2 = Tensor::random_float(2, 2);

    cout << "Second:" << endl;
    cout << T2 << endl;

    cout << "Their sub:" << endl;
    cout << T0 - T2 << endl;
}

void Test_Method_vstack()
{
    cout << "Testing vstack method:" << endl;

    Tensor T0 = Tensor::fill(2, 3, 1);
    Tensor T1 = Tensor::fill(2, 3, -1);

    cout << "IN:" << endl;
    cout << T0 << T1 << endl;

    vstack(&T0, T1);

    cout << "OUT:" << endl;
    cout << T0 << endl;

    Tensor T2 = Tensor::zeros(1, 4);
    Tensor T3 = Tensor::ones(4);

    cout << "IN:" << endl;
    cout << T2 << T3 << endl;

    vstack(&T2, T3);

    cout << "OUT:" << endl;
    cout << T2 << endl;
}

void Test_Method_hstack()
{
    cout << "Testing hstack method:" << endl;

    Tensor T0 = Tensor::fill(2, 2, 1);
    Tensor T1 = Tensor::fill(2, 5, -1);

    cout << "IN:" << endl;
    cout << T0 << T1 << endl;

    hstack(&T0, T1);

    cout << "OUT:" << endl;
    cout << T0 << endl;

    Tensor T2 = Tensor::zeros(1, 1);
    Tensor T3 = Tensor::ones(4);

    cout << "IN:" << endl;
    cout << T2 << T3 << endl;

    hstack(&T2, T3);

    cout << "OUT:" << endl;
    cout << T2 << endl;
}

void Test_Method_transpose()
{
    cout << "Testing transpose method:" << endl;

    Tensor T0 = Tensor::random_int(2, 2);

    cout << "IN:" << endl;
    cout << T0 << endl;

    transpose(&T0);

    cout << "OUT:" << endl;
    cout << T0 << endl;

    Tensor T1 = Tensor::random_float(3, 2);

    cout << "IN:" << endl;
    cout << T1 << endl;

    transpose(&T1);

    cout << "OUT:" << endl;
    cout << T1 << endl;

    Tensor T3 = Tensor::random_float(2, 3);

    cout << "IN:" << endl;
    cout << T3 << endl;

    transpose(&T3);

    cout << "OUT:" << endl;
    cout << T3 << endl;

    Tensor T4 = Tensor::random_int(1, 1);

    cout << "IN:" << endl;
    cout << T4 << endl;

    transpose(&T4);

    cout << "OUT:" << endl;
    cout << T4 << endl;
}

void Test_operator_sum()
{
    cout << "Testing operator +:" << endl;
    cout << "Equal sizes 1-dim:" << endl;

    Tensor T0 = Tensor:: ones(4);

    cout << "First:" << endl;
    cout << T0 << endl;

    DataType a[] = {1, 2, 3, 4};
    Tensor T1 = Tensor(4, a);

    cout << "Second:" << endl;
    cout << T1 << endl;

    cout << "Their sum:" << endl;
    cout << T0 + T1 << endl;

    cout << "Same sizes 2-dim:" << endl;

    Tensor T3 = Tensor:: ones(2, 2);

    cout << "First:" << endl;
    cout << T3 << endl;

    Tensor T4 = Tensor:: ones(2, 2);

    cout << "Second:" << endl;
    cout << T4 << endl;
    cout << "Their sum:" << endl;
    cout << T4 + T3 << endl;

    cout << "Different sizes 1-dim and 2-dim:" << endl;

    Tensor T2 = Tensor::random_float(2, 2);

    cout << "Second:" << endl;
    cout << T2 << endl;

    cout << "Their sum:" << endl;
    cout << T0 + T2 << endl;
}

void Test_operator_mul()
{
    cout << "Testing operator *:" << endl;
    cout << "Equal sizes 1-dim:" << endl;

    Tensor T0 = Tensor:: ones(2, 1);

    cout << "First:" << endl;
    cout << T0 << endl;

    Tensor T1 = Tensor:: fill(1, 2, -4);

    cout << "Second:" << endl;
    cout << T1 << endl;

    cout << "Their mul:" << endl;
    cout << T0 * T1 << endl;

    cout << "Correct sizes 2-dim:" << endl;

    Tensor T3 = Tensor:: ones(2, 2);

    cout << "First:" << endl;
    cout << T3 << endl;

    Tensor T4 = Tensor:: fill(2, 2, -4);

    cout << "Second:" << endl;
    cout << T4 << endl;
    cout << "Their mul:" << endl;
    cout << T3 * T4 << endl;

    cout << "Incorrect sizes:" << endl;

    Tensor T2 = Tensor::random_float(2, 2);

    cout << "First:" << endl;
    cout << T0 << endl;

    cout << "Second:" << endl;
    cout << T2 << endl;

    cout << "Their mul:" << endl;
    cout << T0 * T2 << endl;
}

void Test_operator_mul_const()
{
    cout << "Testing operator * C:" << endl;
    cout << "1-dim:" << endl;

    Tensor T0 = Tensor:: ones(2, 1);

    cout << "First:" << endl;
    cout << T0 << endl;
    cout << "*18:" << endl;
    cout << "We get:" << endl;
    cout << T0 * 18 << endl;

    cout << "2-dim:" << endl;

    Tensor T3 = Tensor:: ones(2, 2);
    cout << "First:" << endl;
    cout << T3 << endl;
    cout << "* -20:" << endl;
    cout << "We get:" << endl;
    cout << T3 * -20 << endl;

    cout << "2-dim * 0:" << endl;

    cout << T3 * 0 << endl;
}

void Test_operator_div_const()
{
    cout << "Testing operator / C:" << endl;
    cout << "1-dim:" << endl;

    Tensor T0 = Tensor:: ones(2, 1);

    cout << "First:" << endl;
    cout << T0 << endl;
    cout << "/2:" << endl;
    cout << "We get:" << endl;
    cout << T0 / 2 << endl;

    cout << "2-dim:" << endl;

    Tensor T3 = Tensor:: ones(2, 2);
    cout << "First:" << endl;
    cout << T3 << endl;
    cout << "/ -10:" << endl;
    cout << "We get:" << endl;
    cout << T3 / -10 << endl;

    cout << "2-dim / 0:" << endl;

    cout << T3 / 0 << endl;
}

void Test_operator_unadd()
{
    cout << "Testing operator +=:" << endl;
    cout << "Equal sizes 1-dim:" << endl;

    Tensor T0 = Tensor:: ones(4);

    cout << "First:" << endl;
    cout << T0 << endl;

    DataType a[] = {1, 2, 3, 4};
    Tensor T1 = Tensor(4, a);

    cout << "Second:" << endl;
    cout << T1 << endl;

    cout << "Their sum:" << endl;
    T0 += T1;
    cout << T0 << endl;

    cout << "Same sizes 2-dim:" << endl;

    Tensor T3 = Tensor:: ones(2, 2);

    cout << "First:" << endl;
    cout << T3 << endl;

    Tensor T4 = Tensor:: ones(2, 2);

    cout << "Second:" << endl;
    cout << T4 << endl;
    cout << "Their sum:" << endl;
    T4 += T3;
    cout << T4 << endl;

    cout << "Different sizes 2-dim:" << endl;

    Tensor T2 = Tensor::random_float(2, 2);
    cout << "First:" << endl;
    cout << T3 << endl;

    cout << "Second:" << endl;
    cout << T2 << endl;

    cout << "Their sum:" << endl;
    T3 += T2;
    cout << T3 << endl;
}

void Test_operator_unsub()
{
    cout << "Testing operator -=:" << endl;
    cout << "Equal sizes 1-dim:" << endl;

    Tensor T0 = Tensor:: ones(4);

    cout << "First:" << endl;
    cout << T0 << endl;

    DataType a[] = {1, 2, 3, 4};
    Tensor T1 = Tensor(4, a);

    cout << "Second:" << endl;
    cout << T1 << endl;

    cout << "Their sum:" << endl;
    T0 -= T1;
    cout << T0 << endl;

    cout << "Same sizes 2-dim:" << endl;

    Tensor T3 = Tensor:: ones(2, 2);

    cout << "First:" << endl;
    cout << T3 << endl;

    Tensor T4 = Tensor:: ones(2, 2);

    cout << "Second:" << endl;
    cout << T4 << endl;
    cout << "Their sum:" << endl;
    T4 -= T3;
    cout << T4 << endl;

    cout << "Different sizes 2-dim:" << endl;

    Tensor T2 = Tensor::random_float(2, 2);
    cout << "First:" << endl;
    cout << T3 << endl;

    cout << "Second:" << endl;
    cout << T2 << endl;

    cout << "Their sum:" << endl;
    T3 -= T2;
    cout << T3 << endl;
}

void Test_operator_unar_min()
{
    cout << "Testing operator -():" << endl;
    cout << "1-dim:" << endl;

    Tensor T0 = Tensor:: ones(4);

    cout << "First:" << endl;
    cout << T0 << endl;
    cout << "We get:" << endl;
    cout << -T0 << endl;

    cout << "2-dim:" << endl;

    Tensor T3 = Tensor:: ones(3, 2);

    cout << "First:" << endl;
    cout << T3 << endl;
    cout << "We get:" << endl;
    cout << -T3 << endl;
}

void Test_operator_equal()
{
    cout << "Testing operator =:" << endl;
    cout << "1-dim:" << endl;

    Tensor T0 = Tensor:: random_int(1, 4);

    cout << "First:" << endl;
    cout << T0 << endl;
    cout << "We get T:" << endl;
    Tensor T1;
    T1 = T0;
    cout << T1 << endl;

    cout << "2-dim:" << endl;

    Tensor T3 = Tensor:: ones(3, 2);

    cout << "First:" << endl;
    cout << T3 << endl;
    cout << "We get T:" << endl;
    Tensor T2; T2 = T3;
    cout << T2 << endl;

}

void Test_operator_index()
{
    cout << "Testing operator []:" << endl;
    cout << "1-dim:" << endl;

    Tensor T0 = Tensor:: random_int(1, 4);

    cout << "First:" << endl;
    cout << T0 << endl;
    cout << "We get T[-1]:" << T0[-1] <<endl;
    cout << "We get T[3]:" << T0[3] <<endl;

    cout << "2-dim:" << endl;

    Tensor T3 = Tensor:: ones(3, 2);

    cout << "First:" << endl;
    cout << T3 << endl;
    cout << "We get T[0]:" << T3[0] << endl;
}

void Test_Randomizer_int()
{
    cout << "Testing tensor generator with random coefficients (int val):\n" << endl;

    Tensor T = Tensor::random_int(3, 3);
    cout << T << endl;

    Tensor H = Tensor::random_int(4, 1);
    cout << H << endl;

    Tensor J = Tensor::random_int(1, 5);
    cout << J << endl;
}

void Test_Randomizer_float()
{
    cout << "Testing tensor generator with random coefficients (int val):\n" << endl;

    Tensor T = Tensor::random_float(3, 3);
    cout << T << endl;

    Tensor H = Tensor::random_float(4, 1);
    cout << H << endl;

    Tensor J = Tensor::random_float(1, 5);
    cout << J << endl;
}

void Test_Randomizer_int_ranged()
{
    cout << "Testing tensor generator with random coefficients (int val ranged):\n" << endl;

    Tensor T = Tensor::random_int_ranged(3, 3, 1, 6);
    cout << T << endl;

    Tensor H = Tensor::random_int_ranged(4, 1, 7, 25);
    cout << H << endl;

    Tensor J = Tensor::random_int_ranged(1, 5, 1, 6);
    cout << J << endl;
}

void Test_Randomizer_float_ranged()
{
    cout << "Testing tensor generator with random coefficients (int val ranged):\n" << endl;

    Tensor T = Tensor::random_float_ranged(3, 3, 1, 6);
    cout << T << endl;

    Tensor H = Tensor::random_float_ranged(4, 1, 7, 25);
    cout << H << endl;

    Tensor J = Tensor::random_float_ranged(1, 5, 1, 6);
    cout << J << endl;
}

void Test_fstream_write()
{
    cout << "Testing fstream(out) overload:\n" << endl;

    Tensor T = Tensor::random_float_ranged(3, 3, 1, 6);
    cout << T << endl;

    fstream out;
    out.open("../test_tensor.txt", ios::out);

    out << T;

    out.close();
}

void Test_fstream_read()
{
    cout << "Testing fstream(in) overload:\n" << endl;

    Tensor T;

    fstream in;
    in.open("../test_input.txt", ios::in);

    in >> T;

    cout << T << endl;

    in.close();
}
