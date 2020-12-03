#ifndef ARRAY_H
#define ARRAY_H
 
#include <assert.h> // для assert()
 

template <class T>
class Array
{
private:
    int m_length;
    T *m_data;
 
public:
    Array()
    {
        m_length = 0;
        m_data = nullptr;
    }
 
    Array(int length)
    {
        m_data = new T[length];
        m_length = length;
    }
 
    ~Array()
    {
        delete[] m_data;
    }
 
    void Erase()
    {
        delete[] m_data;
        // Присваиваем значение nullptr для m_data, чтобы на выходе не получить висячий указатель!
        m_data = nullptr;
        m_length = 0;
    }
 
 
    T& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
 
    // Длина массива всегда является целочисленным значением, она не зависит от типа элементов массива
    int getLength();
};
 
#endif

