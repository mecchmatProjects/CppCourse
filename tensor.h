
#ifndef TENSORFLOW_TENSOR_H
#define TENSORFLOW_TENSOR_H

#include <cmath>
#include <cassert>
#include <cstdarg>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
typedef float DataType;

using namespace std;

class Tensor
{
protected:
    unsigned columns;
    unsigned lines;
    DataType **data;
public:
    // Constructors
    Tensor();
    Tensor(const Tensor &T);
    Tensor(unsigned lines, unsigned columns, DataType value);
    Tensor(unsigned columns);
    Tensor(unsigned lines, unsigned columns, DataType **matrix);
    Tensor(unsigned columns, DataType *Vector);

    //constructor especially for func 'eye'
    Tensor(unsigned columns, DataType value);

    // Named constructors for 2-dim
    static Tensor zeros(unsigned lines, unsigned columns);
    static Tensor ones(unsigned lines, unsigned columns);
    static Tensor fill(unsigned lines, unsigned columns, DataType value);
    static Tensor eye(unsigned n);

    // Named constructors for 1-dim
    static Tensor zeros(unsigned columns);
    static Tensor ones(unsigned columns);
    static Tensor fill(unsigned columns, DataType value);

    // Constructors for randomly generated tensors
    static Tensor random_int(unsigned lines, unsigned columns);
    static Tensor random_float(unsigned lines, unsigned columns);
    static Tensor random_int_ranged(unsigned lines, unsigned columns, int low, int high);
    static Tensor random_float_ranged(unsigned lines, unsigned columns, float low, float high);

    // Destructor
    ~Tensor();

    // Methods
    void reshape(unsigned new_l_user, unsigned new_m_user);
    friend Tensor transpose(Tensor * x);
    friend Tensor vstack(Tensor * a, Tensor b);
    friend Tensor hstack(Tensor * a, Tensor b);

    //overloading operators
    friend Tensor operator +(const Tensor &T1, const Tensor &T2);
    friend Tensor operator -(const Tensor &T1, const Tensor &T2);
    friend Tensor operator *(const Tensor &T1, const Tensor &T2);
    friend Tensor operator *(const Tensor &T1, DataType C);
    friend Tensor operator /(const Tensor &T1, DataType C);

     //overloading unary operators
    Tensor& operator =(const Tensor &T);
    Tensor operator +=(const Tensor &T);
    Tensor operator -();
    Tensor operator -=(const Tensor &T);
    Tensor operator *=(const Tensor &T);
    Tensor operator *=(DataType C);
    DataType& operator [](const int index);

    //input/output
    friend istream &operator>>(istream &in, Tensor &T);
    friend ostream &operator<<(ostream &out, const Tensor &T);

    //input/output - file stream
    friend ifstream &operator>>(ifstream &in, Tensor &T);
    friend ofstream &operator<<(ofstream &out, const Tensor &T);

};
///constructors

//1 - empty constructor
Tensor:: Tensor():lines(), columns(), data() {data = NULL;}

/*2
    @ n - number of lines
    @ m - number of columns
    @ result: Tensor n*m, where every el of matrix = value */
Tensor:: Tensor(unsigned n, unsigned m, DataType value):
        columns(m), lines(n){

        data = new DataType*[n];
        for(unsigned i = 0; i < n; i++){
            data[i] = new DataType[m];
            for(unsigned j = 0; j < m; j++)
                data[i][j] = (DataType)value;
        }
    }
    /*catch (invalid_argument& str){
        //I used 'cerr', because this stream is for errors
        cerr << str.what();
        exit(1);
    }
}*/
/*3 - copies vector's element
    @ n - number of columns
    @ result: 1-dim Tensor, copy of a vector */
Tensor:: Tensor(unsigned n, DataType *Vector):
        lines(1), columns(n)
{
    data = new DataType*[1];
    data[0] = new DataType[n];
    for(unsigned k = 0; k < n; k++){
        data[0][k] = Vector[k];
    }
}

/*4 - copies matrix's elements
    @ n - number of lines
    @ m - number of columns
    @ result: Tensor n*m, where every el = el of matrix*/

Tensor:: Tensor(unsigned n, unsigned m, DataType **matrix):
        lines(n), columns(m){
    data = new DataType*[lines];
    for(int i = 0; i < n; i++){
        data[i] = new DataType[columns];
        for(unsigned k = 0; k < m; k++)
            data[i][k] = matrix[i][k];
    }
}

/*5 - copying constructor*/
Tensor:: Tensor(const Tensor &T){
    this->columns = T.columns;
    this->lines = T.lines;
    this->data = new DataType *[this->lines];

    for (unsigned i = 0; i < this->lines; i++) {
        this->data[i] = new DataType [this->columns];
        for (unsigned j = 0; j < this->columns; j++)
            this->data[i][j] = T.data[i][j];
    }
}

/*6 - copies matrix's elements
    @ n - number of lines
    @ m - number of columns
    @ result: Tensor n*m, where every el = el of matrix*/

Tensor:: ~Tensor()
{
    for(unsigned j = 0; j < lines; j++)
        delete[] data[j];
    delete[] data;
    data = NULL;
}

///named constructors for 2-dim

/*7 - named constructor
generates matrix l_user * m_user, every element = 1
*/
Tensor Tensor:: ones(unsigned l_user, unsigned m_user){
    return Tensor(l_user, m_user, (DataType)1);
}

/*8 - named constructor
generates matrix l_user * m_user, every element = 0
*/
Tensor Tensor:: zeros(unsigned l_user, unsigned m_user){
    return Tensor(l_user, m_user, (DataType)0);
}

/*9 - named constructor
generates matrix l_user * m_user, every element = value
*/
Tensor Tensor:: fill(unsigned l_user, unsigned m_user, DataType value){
    return Tensor(l_user, m_user, value);
}
/*10 - named constructor
generates diagonal matrix = E
*/
Tensor Tensor:: eye(unsigned n){
    return Tensor(n, 1);
}

///named constructors for 1-dim

/*11 - named constructor
generates vector with length = l_user and every element equals to 1
*/
Tensor Tensor:: ones(unsigned l_user){
    return Tensor(1, l_user, (DataType)1);
}

/*12 - named constructor
generates vector with length = l_user and every element equals to 0
*/
Tensor Tensor:: zeros(unsigned l_user){
    return Tensor(1, l_user, (DataType)0);
}

/*13 - named constructor
generates vector with length = l_user and every element equals to value
*/
Tensor Tensor:: fill(unsigned l_user, DataType value){
    return Tensor(1, l_user, (DataType) value);
}

///Overloading

/*14 - operator 'return element' or 'set element'
returns element with index = index, if Tensor is not a matrix
*/
DataType& Tensor:: operator [](const int index){
    try
    {
        if (lines != 1)
            throw invalid_argument("\nIndexError: index out of range");
        if (index >= 0 && index < columns)
            return this->data[0][index];
        else if (index < 0 && abs(index) < columns)
            return this->data[0][index + columns];
        else
            throw invalid_argument("\nIndexError: index out of range");
    }
    catch (invalid_argument& str){
        cerr << str.what();
        exit(1);
    }
}

/*15 - operator =
makes left Tensor exactly like right
*/
Tensor& Tensor:: operator =(const Tensor &T)
{
    for (int i = 0; i < lines; i ++)
        delete[] data[i];
    delete [] data;
    this->columns = T.columns;
    this->lines = T.lines;
    this->data = new DataType *[this->lines];

    for (unsigned i = 0; i < this->lines; i++) {
        this->data[i] = new DataType [this->columns];
        for (unsigned j = 0; j < this->columns; j++)
            this->data[i][j] = T.data[i][j];
    }
    return *this;
}

/*16 - operator +
makes a new Tensor, which is a sum of T1 and T2
loyal to vectors with different sizes, but
not loyal for matrixes with different sizes
*/
Tensor operator +(const Tensor &T1, const Tensor &T2){
    if (T1.lines == T2.lines && T1.columns == T2.columns){
        Tensor T = T1;
        for (unsigned j = 0; j < T.lines; j ++)
            for (unsigned i = 0; i < T.columns; i ++)
                T.data[j][i] += T2.data[j][i];
        return T;
    }
    else{
        cout << "\nCan't summarize tensors with different sizes.";
        exit(1);
    }
}
/*17 - operator -
makes a new Tensor, which is a sub of T1 and T2
loyal to vectors with different sizes, but
not loyal for matrixes with different sizes
*/
Tensor operator -(const Tensor &T1, const Tensor &T2){
    if (T1.lines == T2.lines && T1.columns == T2.columns){
        Tensor T = T1;
        for (int j = 0; j < T.lines; j ++){
            //T.data[j] = new DataType [T.columns];
            for (int i = 0; i < T.columns; i ++)
                T.data[j][i] -= T2.data[j][i];// - T1.data[j][i];
        }
        return T;
    }
    else if (T1.lines == T2.lines && T1.lines == 1){
        Tensor T = Tensor:: zeros(max(T1.columns, T2.columns));
        for (int i = 0; i < T2.columns; i ++)
            T.data[0][i] += T2.data[0][i];;
        for (int i = 0; i < T1.columns; i ++)
            T.data[0][i] += T1.data[0][i];
        return T;
    }
    else if (T1.columns == T2.columns && T1.columns == 1){
        Tensor T = Tensor:: zeros(max(T1.lines, T2.lines), 1);
        for (int i = 0; i < T2.lines; i ++)
            T.data[i][0] += T2.data[i][0];
        for (int i = 0; i < T1.lines; i ++)
            T.data[i][0] += T1.data[i][0];
        return T;
    }
    else{
        cout << "\nCan't summarize tensors with different sizes.";
        exit(1);
    }
}
/*18 - operator *
makes a new Tensor, where every el is a mul by C
*/
Tensor operator *(const Tensor &T1, DataType C){
    Tensor T = T1;
    for (int i = 0; i < T.lines; i ++)
        for (int j = 0; j < T.columns; j ++)
            T.data[i][j] *= C;
    return T;
}

/*19 - operator /
makes a new Tensor, which is like previous,
but it's coef are divided by C
not loyal to C = 0
*/
Tensor operator /(const Tensor &T1, DataType C){
    //can be rewrited as a *(1/C), but it doesn't work for int type
    if (C != 0){
        Tensor T = T1;
        for (int i = 0; i < T.lines; i ++)
            for (int j = 0; j < T.columns; j ++)
                T.data[i][j] /= C;
         return T;
    }
    else{
        cout << "\nZeroDivisionError";
        exit(1);
    }
}
///unary operations

/*20 - operator *=
rewrites the left Tensor to T1 * T2
rules are from overloading *
*/
Tensor Tensor:: operator *=(const Tensor &T1){
    *this = *this * T1;
    return *this;
}
/*21 - operator +=
rewrites the left Tensor to T1 + T2
rules are from overloading +
*/
Tensor Tensor:: operator +=(const Tensor &T2){
    *this = *this + T2;
    return *this;
}

/*22 - operator -
rewrites the left Tensor to -T1
*/
Tensor Tensor:: operator -(){
    for (int i = 0; i < lines; i ++)
        for (int j = 0; j < columns; j ++)
            data[i][j] *= -1;
    return *this;
}

/*23 - operator -=
rewrites the left Tensor to T1 - T2
rules are from overloading -
*/
Tensor Tensor:: operator -=(const Tensor &T2){
    *this = *this - T2;
    return *this;
}
/*24 - operator *
rewrites the left Tensor to T1 * T2
loyal to vectors and matrixes, which sizes follow the rules
columns1 = lines2 */

Tensor operator *(const Tensor &T1, const Tensor &T2){
    if (T2.lines == T1.columns){
        Tensor T = Tensor:: zeros(T1.lines, T2.columns);
        int s = 0;
        for (int k = 0; k < T1.lines; k ++){
            for (int i = 0; i < T2.columns; i ++){
                for (int j = 0; j < T2.lines; j ++){
                    T.data[k][i] += T2.data[j][i] * T1.data[k][j];
                }
            }
        }
        return T;
    }
    else{
        cerr << "\nCan't multiply tensors with incorrect sizes.";
        exit(1);
    }
}
/*25 - operator *=
multiplies every el of Tensor by C and rewrited */

Tensor Tensor:: operator *=(DataType C){
    *this = *this * C;
    return *this;
}

/*26 - operator >>
new input to Tensor from console */

istream &operator>>(istream &in, Tensor &T){
    cout << "Enter number of lines:" << endl;
    in >> T.lines;
    cout << "Enter number of columns:" << endl;
    in >> T.columns;

    T.data = new DataType*[T.lines];
    for(unsigned i = 0; i < T.lines; i++){
        T.data[i] = new DataType [T.columns];
        for(unsigned j = 0; j < T.columns; j++){
            cout << "T[" << i << "][" << j << "]:\n";
            in >> T.data[i][j];
        }
    }
    return in;
}

/*27 - operator <<
new output from Tensor to console or txt file */

ostream &operator<<(ostream &out, const Tensor &T){
    //cout << "Tensor:" << endl;
    for(unsigned i = 0; i < T.lines; i++){
        out << endl;
        for(unsigned j = 0; j < T.columns; j++)
            out << T.data[i][j] << '\t';
        out << endl;
        }
    if (T.lines + T.columns == 0)
        out << 0 << endl;
    return out;
}


/*28 - operator <<
new input to Tensor from txt file */

ifstream &operator>>(ifstream &in, Tensor &T)
{

    char buffer[256];

    char *current;

    in.getline(buffer, 256);

    current = strtok(buffer, " ");

    T.lines = strtol(current, NULL, 10);

    current = strtok(NULL, " ");

    T.columns = strtol(current, NULL, 10);

    T.data = new DataType*[T.lines];

    for(unsigned i = 0; i < T.lines; i++){

        T.data[i] = new DataType [T.columns];

        memset(buffer, 0, 256);

        in.getline(buffer, 256);

        current = strtok(buffer, " ");

        for(unsigned j = 0; j < T.columns; j++)
        {
            T.data[i][j] = strtof(current, NULL);

            current = strtok(NULL, " ");
        }
    }

    return in;
}

/*
ofstream &operator<<(ofstream &out, const Tensor &T)
{
    //out << T.lines << ' ' << T.columns << endl;
}*/

/*29 - constructor, which was made
to release func 'eye'*/

Tensor::Tensor(unsigned n, DataType value): columns(n), lines(n)
{
    data = new DataType *[lines];
    for (int i = 0; i < n; i ++){
        data[i] = new DataType [columns];
        for(unsigned j = 0; j < n; j++)
            data[i][j] = (DataType) 0;
        data[i][i] = (DataType) value;
    }

}
///generate

/*30 - generates random int matrix lines*columns*/

Tensor Tensor::random_int(unsigned lines, unsigned columns){
    Tensor T(lines, columns);

    T.data = new DataType*[T.lines];
    for(unsigned i = 0; i < T.lines; i++){
        T.data[i] = new DataType [T.columns];
        for(unsigned j = 0; j < T.columns; j++){
            T.data[i][j] = rand() % 100 + 1;
        }
    }

    return T;
}

/*31 - generates random float matrix lines*columns*/

Tensor Tensor::random_float(unsigned lines, unsigned columns){
    Tensor T(lines, columns);

    T.data = new DataType*[T.lines];
    for(unsigned i = 0; i < T.lines; i++){
        T.data[i] = new DataType [T.columns];
        for(unsigned j = 0; j < T.columns; j++){
            T.data[i][j] = float(rand()) / (float(RAND_MAX) + 1.0);
        }
    }

    return T;
}

/*32 - generates random DataType matrix lines*columns,
where elements > low and < high*/

Tensor Tensor::random_int_ranged(unsigned lines, unsigned columns, int low, int high){
    Tensor T(lines, columns);

    T.data = new DataType*[T.lines];
    for(unsigned i = 0; i < T.lines; i++){
        T.data[i] = new DataType [T.columns];
        for(unsigned j = 0; j < T.columns; j++){
            T.data[i][j] = low + (int)(rand() / (RAND_MAX / (high - low)));
        }
    }

    return T;
}

/*33 - generates random DataType matrix lines*columns,
where elements > low and < high*/

Tensor Tensor::random_float_ranged(unsigned lines, unsigned columns, float low, float high){
    Tensor T(lines, columns);

    T.data = new DataType*[T.lines];
    for(unsigned i = 0; i < T.lines; i++){
        T.data[i] = new DataType [T.columns];
        for(unsigned j = 0; j < T.columns; j++){
            T.data[i][j] = low + float(rand()) / (float(RAND_MAX) / (high - low));
        }
    }

    return T;
}
//methods

/*34 - makes a reshape, changes it's dimensions
loyal for new size, which follows the rule:
old lines*columns = new n*m
*/

void Tensor:: reshape(unsigned n, unsigned m){

    assert((lines * columns) == (n * m));

    Tensor temp = *this;

    for(unsigned i = 0; i < lines; i ++)
        delete[] this->data[i];
    delete[] this->data;

    this->lines = n;
    this->columns = m;

    unsigned cnt_i=0, cnt_j=0, cnt_k=0;

    this->data = new DataType*[lines];

    for(unsigned i = 0; i < lines; i++){
        this->data[i] = new DataType[columns];
        for(unsigned j = 0; j < columns; j ++){
            this->data[i][j] = temp.data[cnt_i][cnt_j];
            cnt_j++;
            if(cnt_i == temp.lines){
                cnt_j = 0;
                cnt_i++;
            }
        }
    }
}

/*35 - changes Tensor: swaps it's dimensions
*/

Tensor transpose(Tensor * x){
    Tensor temp = *x;
    x->lines = temp.columns;
    x->columns = temp.lines;
    for (int i = 0; i < x->columns; i ++)
        delete []x->data[i];
    delete []x->data;

    x->data = new DataType* [x->lines];
    for (int i = 0; i < x->lines; i ++){
        x->data[i] = new DataType [x->columns];
        for (int j = 0; j < x->columns; j ++)
            x->data[i][j] = temp.data[j][i];
    }
    return *x;
}

/*36 - changes Tensor a:
puts Tensor b  under the a
not loyal for Tensors with different number of columns
*/

Tensor vstack(Tensor * a, Tensor b){
    try
    {
        if (a->columns !=  b.columns)
            throw invalid_argument("\nIncorrectSizeError");

        Tensor temp = *a;
        for (int i = 0; i < a->lines; i ++)
            delete [] a->data[i];
        delete []a->data;

        a->lines += b.lines;
        a->data = new DataType *[a->lines];
        for (int i = 0; i < a->lines; i ++){
            a->data[i] = new DataType [a->columns];
            if (i < temp.lines){
                for (int j = 0; j < a->columns; j ++)
                        a->data[i][j] = temp.data[i][j];
            }
        }
        for (int i = 0; i < b.lines; i ++)
            for (int j = 0; j < b.columns; j ++)
                a->data[i + temp.lines][j] = b.data[i][j];
        return *a;
    }
    catch (invalid_argument& str){
        cerr << str.what();
    }
}

/*36 - changes Tensor a:
puts Tensor b on the rigth of the a
not loyal for Tensors with different number of lines
*/

Tensor hstack(Tensor * a, Tensor b){
    try
    {
        if (a->lines !=  b.lines)
            throw invalid_argument("\nIncorrectSizeError");

        Tensor temp = *a;
        for (int i = 0; i < a->lines; i ++)
            delete [] a->data[i];

        a->columns += b.columns;
        //a->data = new DataType *[a->lines];
        for (int i = 0; i < a->lines; i ++){
            a->data[i] = new DataType [a->columns];
            for (int j = 0; j < temp.columns; j ++)
                    a->data[i][j] = temp.data[i][j];
            }

        for (int i = 0; i < b.lines; i ++)
            for (int j = 0; j < b.columns; j ++)
                a->data[i][j + temp.lines] = b.data[i][j];
        return *a;
    }
    catch (invalid_argument& str){
        cerr << str.what();
    }
}
#endif
