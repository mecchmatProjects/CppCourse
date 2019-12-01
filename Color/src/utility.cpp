#include "utility.h"

//max of 3 float values
float f_max(float a, float b, float c){
    float m = a;
    m = b > m ? b : m;
    m = c > m ? c : m;
    return m;
}

//min of 3 float values
float f_min(float a, float b, float c){
    float m = a;
    m = b < m ? b : m;
    m = c < m ? c : m;
    return m;
}

//check float equlity
bool f_eq(float a, float b){
    return fabs(a-b) < 0.001f;
}
